#ifndef WORK_COMPONENT_H
#define WORK_COMPONENT_H

#include <string>

class WorkComponent
{
protected:
    std::string name;
public:
    WorkComponent(std::string name);

    virtual std::string getName() const;
    virtual double getCost() const  = 0;
    virtual int getDuration() const  = 0;
    virtual void describe(int depth) const  = 0;
    virtual bool needsInspection() const;

    virtual void add(WorkComponent* component);
    virtual void remove(WorkComponent* component);

    virtual ~WorkComponent() = default;
};

#endif // WORK_COMPONENT_H