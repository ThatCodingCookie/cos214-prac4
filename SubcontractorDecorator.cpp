#include <iostream>
#include "SubcontractorDecorator.h"

SubcontractorDecorator::SubcontractorDecorator(WorkComponent* wrapped, double markupPercent)
    : WorkComponentDecorator(wrapped), markupPercent(markupPercent)
{
}

double SubcontractorDecorator::getCost() const 
{
    return wrapped->getCost() * (1 + markupPercent);
}

int SubcontractorDecorator::getDuration() const 
{
    return wrapped->getDuration();
}

void SubcontractorDecorator::describe(int depth) const 
{
    wrapped->describe(depth);
    std::cout << std::string(depth, ' ') << "- Subcontractor: " << markupPercent * 100 << "% markup" << std::endl;
}

SubcontractorDecorator::~SubcontractorDecorator()
{
}