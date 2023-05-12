#ifndef ACTION_H
#define ACTION_H

#include "function.h"

class Action
{
public:
    virtual ~Action() {}
    virtual void Operate(Function *) = 0;
    virtual const std::string& GetName() const = 0;
};

#endif // ACTION_H
