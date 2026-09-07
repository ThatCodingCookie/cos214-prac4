#include "DepthFirstIterator.h"
#include "WorkGroup.h"

DepthFirstIterator::DepthFirstIterator(const WorkGroup* root)
    : position(0) {
    buildSnapshot(root);
}

void DepthFirstIterator::buildSnapshot(const WorkGroup* group) {
    for (WorkComponent* child : group->children)
    {
        snapshot.push_back(child);

        WorkGroup* childGroup = dynamic_cast<WorkGroup*>(child);

        if (childGroup != nullptr)
        {
            buildSnapshot(childGroup);
        }
    }
}

void DepthFirstIterator::first() {
    position = 0;
}

bool DepthFirstIterator::hasNext() {
    return position < static_cast<int>(snapshot.size());
}

WorkComponent* DepthFirstIterator::next() {
    if (!hasNext()) {
        return nullptr;
    }

    return snapshot[position++];
}