#include <iostream>
#include "PermitComplianceDecorator.h"

PermitComplianceDecorator::PermitComplianceDecorator(WorkComponent* wrapped, double permitFee, int permitDays)
    : WorkComponentDecorator(wrapped), permitFee(permitFee), permitDays(permitDays)
{

}

double PermitComplianceDecorator::getCost() const 
{
    return wrapped->getCost() + permitFee;
}

int PermitComplianceDecorator::getDuration() const 
{
    return wrapped->getDuration() + permitDays;
}

void PermitComplianceDecorator::describe(int depth) const 
{
    wrapped->describe(depth);
    std::cout << std::string(depth, ' ') << "- Permit Compliance: $" << permitFee << " for " << permitDays << " days" << std::endl;
}

PermitComplianceDecorator::~PermitComplianceDecorator()
{
}