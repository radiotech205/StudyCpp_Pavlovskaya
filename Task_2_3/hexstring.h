#ifndef HEXSTRING_H
#define HEXSTRING_H
#include <string>
#include "astring.h"

const std::string alph = "0123456789ABCDEF";
bool IsHexStrVal(std::string _str);

class HexString : public AString
{
public:
    HexString(std::string _name) : name(_name) {}
    HexString(std::string _name, std::string _val);
    virtual ~HexString() {}

    virtual const std::string& GetName() const {return name;}
    virtual const std::string& GetVal() const {return val;}
    virtual int GetSize() const {return val.size();}
private:
    std::string name;
    std::string val;
};

#endif // HEXSTRING_H
