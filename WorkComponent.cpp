#include "WorkComponent.h"

WorkComponent::WorkComponent(std::string name)
    : name(name)
{
}

std::string WorkComponent::getName() const
{
    return name;
}

void WorkComponent::add(WorkComponent* component)
{
    // do nothing
}

void WorkComponent::remove(WorkComponent* component)
{
    // do nothing
}

bool WorkComponent::needsInspection() const
{
    return false;
}