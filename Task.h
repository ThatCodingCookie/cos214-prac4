#ifndef TASK_H
#define TASK_H

#include <string>
#include "WorkComponent.h"

class TaskState;

class Task : public WorkComponent
{
private:
    TaskState* state;
    double baseCost;
    int baseDurationDays;

public:
    Task(const std::string& name, double baseCost, int baseDurationDays);

    void start();
    void block(const std::string& reason);
    void resume();
    void complete();
    void setState(TaskState* state);
    std::string getStateName() const;
    std::string getName() const override;
    double getCost() const override;
    int getDuration() const override;
    void describe(int depth) const override;

    bool needsInspection() const override;
    
    ~Task();
};

#endif