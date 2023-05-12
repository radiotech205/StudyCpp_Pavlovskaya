#ifndef EXP_H
#define EXP_H
#include "function.h"



class Exp : public Function
{
public:
    Exp() : name("e^x") {}
    virtual ~Exp() {}
    virtual const std::string & GetName() const {return name;}
    virtual void Calculate();
protected:
    std::string name;
};

//extern Exp f_exp;
#endif // EXP_H
