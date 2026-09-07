#ifndef WORK_ITERATOR_H
#define WORK_ITERATOR_H

#include "WorkComponent.h"

class WorkIterator
{
public:
    virtual void first() = 0;
    virtual bool hasNext() = 0;
    virtual WorkComponent* next() = 0;

    virtual ~WorkIterator() = default;
};

#endif // WORK_ITERATOR_H