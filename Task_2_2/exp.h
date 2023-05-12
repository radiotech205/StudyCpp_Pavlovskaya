#ifndef EXP_H
#define EXP_H
#include "function.h"
#include <cmath>


class Exp : public Function
{
public:
    Exp() : name("e^x") {}
    virtual ~Exp() {}
    virtual void SetCoeff(void) {}
    virtual double GetVal(void) const {return exp(x);}
    virtual const std::string & GetName() const {return name;}
private:
    std::string name;
};

//extern Exp f_exp;
#endif // EXP_H
