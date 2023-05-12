#include "showdec.h"
#include "hexstring.h"
#include <iostream>
using namespace std;


void ShowDec::Operate(AString* pObj)
{
    cout << pObj->GetName() << ": ";
    long decVal = GetDecimal(pObj);
    if(decVal != -1)
        cout << GetDecimal(pObj);

    cout << endl;
    cin.get();
}
