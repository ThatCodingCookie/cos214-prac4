#include "PendingInspectionIterator.h"
#include "WorkGroup.h"
#include "Task.h"

PendingInspectionIterator::PendingInspectionIterator(const WorkGroup* root)
    : position(0)
{
    buildSnapshot(root);
}

void PendingInspectionIterator::buildSnapshot(const WorkGroup* group)
{
    for (WorkComponent* child : group->children)
    {
        if (child->needsInspection())
        {
            snapshot.push_back(child);
        }

        WorkGroup* childGroup = dynamic_cast<WorkGroup*>(child);

        if (childGroup != nullptr)
        {
            buildSnapshot(childGroup);
        }
    }
}


void PendingInspectionIterator::first()
{
    position = 0;
}

bool PendingInspectionIterator::hasNext()
{
    return position < static_cast<int>(snapshot.size());
}

WorkComponent* PendingInspectionIterator::next()
{
    if (!hasNext())
    {
        return nullptr;
    }

    return snapshot[position++];
}