#ifndef SHOWDEC_H
#define SHOWDEC_H
#include "action.h"


class ShowDec : public Action
{
public:
    ShowDec() : name("Show decimal value") {}
    virtual ~ShowDec() {}
    virtual void Operate(AString* pObj);
    virtual const std::string& GetName() const {return name;}
private:
    std:: string name;
};

#endif // SHOWDEC_H
