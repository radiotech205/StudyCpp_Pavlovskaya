#ifndef ANYACTION_H
#define ANYACTION_H
#include "action.h"

class AnyAction : public Action
{
public:
    AnyAction() : name("Any action") {}
    virtual ~AnyAction() {}
    virtual void Operate(Function *pFunc);
    virtual const std::string& GetName() const {return name;}
private:
    std::string name;
};

#endif // ANYACTION_H
