#include <iostream>

#include "Task.h"
#include "WorkGroup.h"

#include "SafetyInspectionDecorator.h"
#include "PermitComplianceDecorator.h"
#include "SubcontractorDecorator.h"

#include "WorkIterator.h"

void printRemaining(const std::string &label, WorkIterator *it)
{
    std::cout << "\n " << label << " n";
    while (it->hasNext())
    {
        WorkComponent *component = it->next();
        std::cout << "  " << component->getName() << std::endl;
    }
}

void printTotals(const WorkGroup *project)
{
    std::cout << "Total cost: R" << project->getCost() << " | Duration: " << project->getDuration() << " days\n";
}
// SCENARIO 1: Daily Progress Report
// Collaboration shown: Composite (full tree), State, Decorator (decorated components), and Iterator (two independently-purposed traversals over the same tree).
void runDailyReportScenario(WorkGroup *project)
{
    std::cout << "\n";
    std::cout << " SCENARIO 1: Daily Progress Report\n";
    std::cout << "\n";

    std::cout << "\n Full project structure:n";
    project->describe(0);
    printTotals(project);

    // Full traversal
    WorkIterator *fullIterator = project->createFullIterator();
    printRemaining("Depth-first traversal (everything)", fullIterator);
    delete fullIterator;

    // Different traversal: different purpose (site-safety queue) and different selection rule (only In-Progress work needing inspection).
    WorkIterator *pendingIterator = project->createPendingInspectionIterator();
    printRemaining("Pending safety inspection queue", pendingIterator);
    delete pendingIterator;
}

// SCENARIO 2 - Disruption Day
// an iterator created before a change keeps running safely on its original snapshot (stale-but-safe), while a NEW iterator created after the change reflects reality. It also performs a genuine structural change (moving work between groups), a state change, anda decoration applied at runtime to something already in the tree all three change types
void runDisruptionScenario(WorkGroup *project, WorkGroup *structure, WorkGroup *finishing, Task *concrete, WorkComponent *subcontractedRoof, Task *painting)
{
    std::cout << "\n";
    std::cout << " SCENARIO 2: Disruption Day\n";
    std::cout << "\n";

    // Grab an iterator now
    WorkIterator *midRun = project->createPendingInspectionIterator();
    std::cout << "\nMid-run iterator created (snapshot taken now).\n";
    if (midRun->hasNext())
    {
        std::cout << "First item already read: " << midRun->next()->getName() << std::endl;
    }

    // Change 1: STATE
    //  Concrete was "In Progress"
    std::cout << "\n[state change] Concrete pour is finished.\n";
    concrete->complete();

    // Change 2: STRUCTURE
    //  The roof crew has moved on to finishing touches, so the whole decorated roof bundle (permit + subcontractor markup) is relocated from Structure to finishing. This uses the same add()/remove()
    std::cout << "[structural change] Roof work reassigned: Structure -> Finishing.\n";
    structure->remove(subcontractedRoof);
    finishing->add(subcontractedRoof);

    //  Change 3: DECORATION

    std::cout << "[decoration change] Painting started; safety inspection added.\n";
    finishing->remove(painting);
    painting->start();
    WorkComponent *inspectedPainting = new SafetyInspectionDecorator(painting, 800, 1);
    finishing->add(inspectedPainting);

    printRemaining("midRun continuing on its original snapshot (stale-but-safe)", midRun);
    delete midRun;

    WorkIterator *freshIterator = project->createPendingInspectionIterator();
    printRemaining("Freshly created iterator (reflects the changes)", freshIterator);
    delete freshIterator;

    std::cout << "\n Totals after disruption (always live, unlike iterators) \n";
    printTotals(project);
}

int main()
{
    // Build the initial  tree
    WorkGroup *project = new WorkGroup("House Construction");

    WorkGroup *foundation = new WorkGroup("Foundation");
    WorkGroup *structure = new WorkGroup("Structure");
    WorkGroup *finishing = new WorkGroup("Finishing");

    Task *excavation = new Task("Excavation", 5000, 3);
    Task *concrete = new Task("Pour Concrete", 12000, 5);
    Task *walls = new Task("Build Walls", 18000, 7);
    Task *roof = new Task("Install Roof", 25000, 5);
    Task *painting = new Task("Painting", 8000, 4);

    // Initial lifecycle state for each task.
    excavation->start();
    excavation->complete();

    concrete->start();

    walls->start();
    walls->block("Waiting for materials");

    roof->start();

    WorkComponent *inspectedConcrete = new SafetyInspectionDecorator(concrete, 1500, 2);

    WorkComponent *permittedRoof = new PermitComplianceDecorator(roof, 2000, 3);

    WorkComponent *subcontractedRoof = new SubcontractorDecorator(permittedRoof, 0.10);

    foundation->add(excavation);
    foundation->add(inspectedConcrete);

    structure->add(walls);
    structure->add(subcontractedRoof);

    finishing->add(painting);

    project->add(foundation);
    project->add(structure);
    project->add(finishing);

    // Run the scenarios
    runDailyReportScenario(project);

    runDisruptionScenario(project, structure, finishing, concrete, subcontractedRoof, painting);

    delete project;

    return 0;
}