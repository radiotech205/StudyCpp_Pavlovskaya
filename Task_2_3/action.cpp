#include "action.h"
#include "hexstring.h"
#include <iostream>
using namespace std;

long Action::GetDecimal(AString *pObj) const
{
    if(dynamic_cast<HexString*>(pObj))
    {
        long dest;
        string source = pObj->GetVal();
        sscanf(source.c_str(), "%lx", &dest);
        return dest;
    }
    else
    {
        cout << "Action not supported." << endl;
        return -1;
    }
}
