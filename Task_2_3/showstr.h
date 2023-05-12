#ifndef SHOWSTR_H
#define SHOWSTR_H
#include "action.h"

class ShowStr : public Action
{
public:
    ShowStr() : name("Show string value")  {}
    virtual ~ShowStr() {}
    virtual void Operate(AString *pObj);
    virtual const std::string& GetName() const {return name;}
private:
    std::string name;
};

#endif // SHOWSTR_H
