#include <iostream>
#include "PlannedState.h"
#include "InProgressState.h"
#include "Task.h"

TaskState* PlannedState::instance()
{
    static PlannedState instance;
    return &instance;
}

void PlannedState::start(Task* task)
{
    task->setState(InProgressState::instance());
}

void PlannedState::block(Task* task, const std::string& reason)
{
    std::cout << "Cannot block a planned task: " << reason << std::endl;
}

void PlannedState::resume(Task*)
{
    std::cout << "Cannot resume a task that has not started." << std::endl;
}

void PlannedState::complete(Task*)
{
    std::cout << "Cannot complete a task that has not started." << std::endl;
}

std::string PlannedState::getName() const
{
    return "Planned";
}


