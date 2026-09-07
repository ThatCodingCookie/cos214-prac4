#include "WorkComponentDecorator.h"

WorkComponentDecorator::WorkComponentDecorator(WorkComponent* wrapped)
    : WorkComponent(wrapped->getName()), wrapped(wrapped)
{
}

std::string WorkComponentDecorator::getName() const
{
    return wrapped->getName();
}

bool WorkComponentDecorator::needsInspection() const
{
    return wrapped->needsInspection();
}

WorkComponentDecorator::~WorkComponentDecorator()
{
    delete wrapped;
}