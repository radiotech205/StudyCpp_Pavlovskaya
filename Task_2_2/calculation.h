#ifndef CALCULATION_H
#define CALCULATION_H
#include "action.h"

class Calculation : public Action
{
public:
    Calculation() : name("Calculation") {}
    virtual ~Calculation() {}
    virtual void Operate(Function *pFunc);
    virtual const std::string& GetName() const {return name;}
private:
    std::string name;
};

#endif // CALCULATION_H
