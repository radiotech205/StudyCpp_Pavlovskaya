#include "showstr.h"
#include <iostream>
using namespace std;

void ShowStr::Operate(AString *pObj)
{
    cout << pObj->GetName() << ": ";
    cout << pObj->GetVal() << endl;
    cin.get();
}
