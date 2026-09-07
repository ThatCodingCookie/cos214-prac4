#ifndef PENDING_INSPECTION_ITERATOR_H
#define PENDING_INSPECTION_ITERATOR_H

#include <vector>
#include "WorkIterator.h"

class WorkGroup;

class PendingInspectionIterator : public WorkIterator
{
private:
    std::vector<WorkComponent*> snapshot;
    int position;
    void buildSnapshot(const WorkGroup* group);

public:
    PendingInspectionIterator(const WorkGroup* root);
    void first() override;
    bool hasNext() override;
    WorkComponent* next() override;
};

#endif // PENDING_INSPECTION_ITERATOR_H