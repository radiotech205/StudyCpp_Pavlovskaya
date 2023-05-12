#include "hexstring.h"

using namespace std;

bool IsHexStrVal(std::string _str)
{
    for(uint i = 0; i < _str.size(); ++i)
        if(-1 == alph.find_first_of(_str[i]))
            return false;
    return true;
}

HexString::HexString(std::string _name, std::string _val) : name(_name)
{
    if(IsHexStrVal(_val))
        val = _val;
}
