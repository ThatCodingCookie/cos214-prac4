#ifndef SUBCONTRACTOR_DECORATOR_H
#define SUBCONTRACTOR_DECORATOR_H

#include "WorkComponentDecorator.h"

class SubcontractorDecorator : public WorkComponentDecorator
{
private:
    double markupPercent;
public:
    SubcontractorDecorator(WorkComponent* wrapped, double markupPercent);

    double getCost() const override;
    int getDuration() const override;
    void describe(int depth) const override;

    ~SubcontractorDecorator();
};

#endif