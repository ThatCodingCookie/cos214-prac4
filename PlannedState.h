#ifndef PLANNED_STATE_H
#define PLANNED_STATE_H

#include "TaskState.h"

class PlannedState : public TaskState
{
private:
    PlannedState() = default;

public:
    static TaskState* instance();

    void start(Task* task) override;
    void block(Task* task, const std::string& reason) override;
    void resume(Task* task) override;
    void complete(Task* task) override;

    std::string getName() const override;
};

#endif