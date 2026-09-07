#ifndef SAFETY_INSPECTION_DECORATOR_H
#define SAFETY_INSPECTION_DECORATOR_H
#include "WorkComponentDecorator.h"

class SafetyInspectionDecorator : public WorkComponentDecorator
{
private:
    double inspectionFee;
    int inspectionDays;
public:
    SafetyInspectionDecorator(WorkComponent* wrapped, double inspectionFee, int inspectionDays);

    double getCost() const override;
    int getDuration() const override;
    void describe(int depth) const override;
    bool needsInspection() const override;

    ~SafetyInspectionDecorator();
};

#endif // SAFETY_INSPECTION_DECORATOR_H