#include <iostream>

#include "Task.h"
#include "WorkGroup.h"

#include "SafetyInspectionDecorator.h"
#include "PermitComplianceDecorator.h"
#include "SubcontractorDecorator.h"

#include "WorkIterator.h"

int main()
{
    // 1. COMPOSITE - Build construction project

    WorkGroup* project = new WorkGroup("House Construction");

    WorkGroup* foundation = new WorkGroup("Foundation");
    WorkGroup* structure = new WorkGroup("Structure");
    WorkGroup* finishing = new WorkGroup("Finishing");


    // 2. Create individual Tasks

    Task* excavation =
        new Task("Excavation", 5000, 3);

    Task* concrete =
        new Task("Pour Concrete", 12000, 5);

    Task* walls =
        new Task("Build Walls", 18000, 7);

    Task* roof =
        new Task("Install Roof", 25000, 5);

    Task* painting =
        new Task("Painting", 8000, 4);


    // 3. STATE PATTERN

    excavation->start();
    excavation->complete();

    concrete->start();

    walls->start();
    walls->block("Waiting for materials");

    roof->start();

    // 4. DECORATOR PATTERN

    WorkComponent* inspectedConcrete =
        new SafetyInspectionDecorator(
            concrete,
            1500,
            2
        );

    WorkComponent* permittedRoof =
        new PermitComplianceDecorator(
            roof,
            2000,
            3
        );

    WorkComponent* subcontractedRoof =
        new SubcontractorDecorator(
            permittedRoof,
            0.10
        );


    // 5. Build Composite hierarchy

    foundation->add(excavation);
    foundation->add(inspectedConcrete);

    structure->add(walls);
    structure->add(subcontractedRoof);

    finishing->add(painting);

    project->add(foundation);
    project->add(structure);
    project->add(finishing);


    // 6. Display hierarchy

    std::cout << "\n=== CONSTRUCTION PROJECT ===\n";

    project->describe(0);

    std::cout << "\nTotal project cost: "
              << project->getCost()
              << std::endl;

    std::cout << "Project duration: "
              << project->getDuration()
              << " days"
              << std::endl;


    // 7. FULL ITERATOR

    std::cout << "\n=== DEPTH FIRST TRAVERSAL ===\n";

    WorkIterator* fullIterator =
        project->createFullIterator();

    fullIterator->first();

    while (fullIterator->hasNext())
    {
        WorkComponent* component =
            fullIterator->next();

        std::cout << component->getName()
                  << std::endl;
    }

    delete fullIterator;


    // 8. PENDING INSPECTION ITERATOR

    std::cout << "\n=== PENDING INSPECTION ===\n";

    WorkIterator* pendingIterator =
        project->createPendingInspectionIterator();

    pendingIterator->first();

    while (pendingIterator->hasNext())
    {
        WorkComponent* component =
            pendingIterator->next();

        std::cout << component->getName()
                  << std::endl;
    }

    delete pendingIterator;


    // 9. Demonstrate state changes

    std::cout << "\n=== STATE CHANGES ===\n";

    std::cout << "Walls: "
              << walls->getStateName()
              << std::endl;

    walls->resume();

    std::cout << "Walls after resume: "
              << walls->getStateName()
              << std::endl;

    walls->complete();

    std::cout << "Walls after complete: "
              << walls->getStateName()
              << std::endl;


    // 10. Show pending list after state changes

    std::cout << "\n=== PENDING INSPECTION AFTER STATE CHANGES ===\n";

    pendingIterator =
        project->createPendingInspectionIterator();

    while (pendingIterator->hasNext())
    {
        WorkComponent* component =
            pendingIterator->next();

        std::cout << component->getName()
                  << std::endl;
    }

    delete pendingIterator;


    // 11. Clean up

    delete project;

    return 0;
}