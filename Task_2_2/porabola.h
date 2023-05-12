#ifndef PORABOLA_H
#define PORABOLA_H
#include "function.h"

class Porabola : public Function
{
public:
    Porabola() : name("a*x^2 + b*x + c") {}
    virtual ~Porabola() {}
    virtual const std::string& GetName(void) const {return name;}
    virtual void SetCoeff(void);
    virtual double GetVal(void) const {return (a*x*x + b*x + c);}
private:
    std::string name;
    double a, b, c;
};

//extern Porabola f_porabola;
#endif // PORABOLA_H
