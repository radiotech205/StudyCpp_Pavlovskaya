#ifndef TABULATION_H
#define TABULATION_H
#include "action.h"

class Tabulation : public Action
{
public:
    Tabulation(): name("Tabulation") {}
    virtual ~Tabulation() {}
    virtual void Operate(Function *pFunc);
    virtual const std::string& GetName() const {return name;}
private:
    std::string name;
};

#endif // TABULATION_H
