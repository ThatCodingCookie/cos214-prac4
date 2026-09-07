#ifndef WORKCOMPONENTDECORATOR_H
#define WORKCOMPONENTDECORATOR_H


#include <string>
#include "WorkComponent.h"

class WorkComponentDecorator : public WorkComponent
{
protected:
    WorkComponent* wrapped;
public:
    WorkComponentDecorator(WorkComponent* wrapped);

    std::string getName() const override;
    bool needsInspection() const override;

    virtual ~WorkComponentDecorator();
};

#endif

