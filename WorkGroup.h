#ifndef WORK_GROUP_H
#define WORK_GROUP_H

#include <vector>
#include <string>

#include "WorkIterator.h"
#include "WorkComponent.h"


class WorkGroup : public WorkComponent
{
    friend class DepthFirstIterator;
    friend class PendingInspectionIterator;
private:
    std::vector<WorkComponent*> children;
public:
    WorkGroup(const std::string& name);

    void add(WorkComponent* component);
    void remove(WorkComponent* component);
    double getCost() const;
    int getDuration() const;
    void describe(int depth) const;
    WorkIterator* createFullIterator() const;
    WorkIterator* createPendingInspectionIterator() const;


    ~WorkGroup();

};


#endif