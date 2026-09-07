#ifndef BLOCKED_STATE_H
#define BLOCKED_STATE_H

#include "TaskState.h"

class BlockedState : public TaskState
{
private:
    BlockedState() = default;

public:
    static TaskState* instance();

    void start(Task* task) override;
    void block(Task* task, const std::string& reason) override;
    void resume(Task* task) override;
    void complete(Task* task) override;

    std::string getName() const override;
};

#endif