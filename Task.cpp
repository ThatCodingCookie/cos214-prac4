#include <iostream>

#include "Task.h"
#include "TaskState.h"
#include "PlannedState.h"

Task::Task(const std::string& name, double baseCost, int baseDurationDays)
    : WorkComponent(name),
      state(PlannedState::instance()),
      baseCost(baseCost),
      baseDurationDays(baseDurationDays)
{
}

void Task::start()
{
    state->start(this);
}

void Task::block(const std::string& reason)
{
    state->block(this, reason);
}

void Task::resume()
{
    state->resume(this);
}

void Task::complete()
{
    state->complete(this);
}

void Task::setState(TaskState* newState)
{
    state = newState;
}

std::string Task::getStateName() const
{
    return state->getName();
}

std::string Task::getName() const
{
    return name;
}

double Task::getCost() const
{
    return baseCost;
}

int Task::getDuration() const
{
    return baseDurationDays;
}

void Task::describe(int depth) const
{
    std::cout
        << std::string(depth, ' ')
        << name
        << " State: " << state->getName()
        << " Cost: R" << baseCost
        << " Duration: " << baseDurationDays << " days"
        << std::endl;
}

bool Task::needsInspection() const
{
    return getStateName() == "In Progress";
}

Task::~Task()
{
}