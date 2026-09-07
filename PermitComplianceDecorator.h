#ifndef PERMIT_COMPLIANCE_DECORATOR_H
#define PERMIT_COMPLIANCE_DECORATOR_H


#include "WorkComponentDecorator.h"

class PermitComplianceDecorator : public WorkComponentDecorator
{
private:
    double permitFee;
    int permitDays;
public:
    PermitComplianceDecorator(WorkComponent* wrapped, double permitFee, int permitDays);

    double getCost() const override;
    int getDuration() const override;
    void describe(int depth) const override;

    ~PermitComplianceDecorator();
};

#endif