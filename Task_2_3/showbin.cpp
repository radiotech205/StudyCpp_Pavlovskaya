#include "showbin.h"
#include <iostream>
using namespace std;

void ShowBin::Operate(AString* pObj)
{
    cout << pObj->GetName() << ": ";
    cout << GetBinary(pObj) << endl;
    cin.get();
}

string ShowBin::GetBinary(AString *pObj) const
{
    int nBinDigit = 4 * pObj->GetSize();
    char *binStr = new char[(nBinDigit + 1)*1024];
    for(int k = 0; k < nBinDigit; ++k) binStr[k] = '0';
    binStr[nBinDigit] = 0;
    long decVal = GetDecimal(pObj);
    if(-1 == decVal)
        return string("");

    int i = nBinDigit-1;
    while(decVal > 0)
    {
        binStr[i--] = 48 + decVal % 2;
        decVal >>= 1;
    }

    string temp(binStr);
    delete []binStr;
    return temp;
}
