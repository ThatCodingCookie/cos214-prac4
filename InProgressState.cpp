#include <iostream>
#include "InProgressState.h"
#include "BlockedState.h"
#include "CompletedState.h"
#include "Task.h"

TaskState* InProgressState::instance()
{
    static InProgressState instance;
    return &instance;
}

void InProgressState::start(Task* task)
{
    std::cout << "Task is already in progress." << std::endl;
}

void InProgressState::block(Task* task, const std::string& reason)
{
    std::cout << "Task blocked: " << reason << std::endl;
    task->setState(BlockedState::instance());
}

void InProgressState::resume(Task*)
{
    std::cout << "Task is already in progress." << std::endl;
}

void InProgressState::complete(Task* task)
{
    task->setState(CompletedState::instance());
}

std::string InProgressState::getName() const
{
    return "In Progress";
}


