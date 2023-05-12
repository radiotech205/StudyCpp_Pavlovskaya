#ifndef LINE_H
#define LINE_H
#include "function.h"


class Line : public Function
{
public:
    Line() : name("a*x + b") {}
    virtual ~Line() {}
    virtual const std::string& GetName() const {return name;}
    virtual void Calculate();
protected:
    std::string name;
    double a;
    double b;
};

//extern Line f_line;
#endif // LINE_H
