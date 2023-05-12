#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>


class Function
{
public:
    virtual ~Function() {}
    void SetArg(double arg) {x = arg;}
    virtual void SetCoeff(void) = 0;
    virtual double GetVal(void) const = 0;
    virtual const std::string& GetName() const = 0;
protected:
    double x;
};

#endif // FUNCTION_H
