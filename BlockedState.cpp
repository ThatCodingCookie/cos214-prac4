#include <iostream>
#include "BlockedState.h"
#include "InProgressState.h"
#include "Task.h"

TaskState* BlockedState::instance()
{
    static BlockedState instance;
    return &instance;
}

void BlockedState::start(Task*)
{
    std::cout << "Cannot start a blocked task." << std::endl;
}

void BlockedState::block(Task*, const std::string& reason)
{
    std::cout << "Task is already blocked: " << reason << std::endl;
}

void BlockedState::resume(Task* task)
{
    task->setState(InProgressState::instance());
}

void BlockedState::complete(Task*)
{
    std::cout << "Cannot complete a blocked task." << std::endl;
}

std::string BlockedState::getName() const
{
    return "Blocked";
}



