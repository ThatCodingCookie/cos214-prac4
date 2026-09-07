#ifndef TASK_STATE_H
#define TASK_STATE_H

#include <string>

class Task;

class TaskState
{
public:
    virtual void start(Task* task) = 0;
    virtual void block(Task* task, const std::string& reason) = 0;
    virtual void resume(Task* task) = 0;
    virtual void complete(Task* task) = 0;

    virtual std::string getName() const = 0;

    virtual ~TaskState() = default;
};

#endif // TASK_STATE_H