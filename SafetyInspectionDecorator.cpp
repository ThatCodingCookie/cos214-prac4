#include <iostream>
#include "SafetyInspectionDecorator.h"

SafetyInspectionDecorator::SafetyInspectionDecorator(WorkComponent* wrapped, double inspectionFee, int inspectionDays)
    : WorkComponentDecorator(wrapped), inspectionFee(inspectionFee), inspectionDays(inspectionDays)
{
}

double SafetyInspectionDecorator::getCost() const 
{
    return wrapped->getCost() + inspectionFee;
}

int SafetyInspectionDecorator::getDuration() const 
{
    return wrapped->getDuration() + inspectionDays;
}

void SafetyInspectionDecorator::describe(int depth) const 
{
    wrapped->describe(depth);
    std::cout << std::string(depth, ' ') << "- Safety Inspection: $" << inspectionFee << " for " << inspectionDays << " days" << std::endl;
}

bool SafetyInspectionDecorator::needsInspection() const 
{
    return true;
}

SafetyInspectionDecorator::~SafetyInspectionDecorator()
{
}