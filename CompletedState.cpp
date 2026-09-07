#include <iostream>
#include "CompletedState.h"
#include "Task.h"

TaskState* CompletedState::instance()
{
    static CompletedState instance;
    return &instance;
}

void CompletedState::start(Task*)
{
    std::cout << "Cannot restart a completed task." << std::endl;
}

void CompletedState::block(Task*, const std::string&)
{
    std::cout << "Cannot block a completed task." << std::endl;
}

void CompletedState::resume(Task*)
{
    std::cout << "Cannot resume a completed task." << std::endl;
}

void CompletedState::complete(Task*)
{
    std::cout << "Task is already completed." << std::endl;
}

std::string CompletedState::getName() const
{
    return "Completed";
}


