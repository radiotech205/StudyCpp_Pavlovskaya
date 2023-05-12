#ifndef SHOWOCT_H
#define SHOWOCT_H
#include "action.h"

class ShowOct : public Action
{
public:
    ShowOct() : name("Show octal value") {}
    virtual ~ShowOct() {}
    virtual void Operate(AString* pObj);
    virtual const std::string& GetName() const {return name;}
private:
    std::string GetOctal(AString *pObj) const;
    std::string name;
};

#endif // SHOWOCT_H
