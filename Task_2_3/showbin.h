#ifndef SHOWBIN_H
#define SHOWBIN_H
#include "action.h"

class ShowBin : public Action
{
public:
    ShowBin() : name("Show binary value") {}
    virtual ~ShowBin() {}
    virtual void Operate(AString* pObj);
    virtual const std::string& GetName() const {return name;}
private:
    std::string GetBinary(AString *pObj) const;
    std::string name;
};

#endif // SHOWBIN_H
