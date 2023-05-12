#ifndef SUMBSTRING_H
#define SUMBSTRING_H
#include <string>
#include "astring.h"

class Sumbstring : public AString
{
public:
    Sumbstring(std::string _name) : name(_name) {}
    Sumbstring(std::string _name, std::string _val)
        : name(_name), val(_val) {}
    virtual ~Sumbstring() {}

    virtual const std::string& GetName() const {return name;}
    virtual const std::string& GetVal() const {return val;}
    virtual int GetSize() const {return val.size();}
private:
    std::string name;
    std::string val;
};

#endif // SUMBSTRING_H
