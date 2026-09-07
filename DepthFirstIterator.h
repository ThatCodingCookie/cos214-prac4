#ifndef DEPTH_FIRST_ITERATOR_H
#define DEPTH_FIRST_ITERATOR_H

#include <vector>
#include "WorkIterator.h"

class WorkGroup;

class DepthFirstIterator : public WorkIterator
{
private:
    std::vector<WorkComponent*> snapshot;
    int position;
    void buildSnapshot(const WorkGroup* group);
    
public:
    DepthFirstIterator(const WorkGroup* root);
    
    void first() override;
    bool hasNext() override;
    WorkComponent* next() override;
};

#endif // DEPTH_FIRST_ITERATOR_H