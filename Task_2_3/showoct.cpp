#include "showoct.h"
#include <iostream>
using namespace std;

void ShowOct::Operate(AString* pObj)
{
    cout << pObj->GetName() << ": ";
    cout << GetOctal(pObj) << endl;
    cin.get();
}

string ShowOct::GetOctal(AString *pObj) const
{
    long decVal = GetDecimal(pObj);
    char buffer[100];
    sprintf(buffer,"%lo", decVal);

    string temp(buffer);
    return temp;
}
