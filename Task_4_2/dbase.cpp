#include "dbase.h"

void DBase::InitInput()
{
    for(int i = 0; i < nRecords; i++)
        cin >> *(pMan + i);
}
void DBase::Show()
{
    cout << "==================================\n";
    cout << "Содержимое БД:\n";
    for(int i = 0; i < nRecords; i++)
        cout << *(pMan + i);
}
void DBase::SearchPayNotLess(double anyPay)
{
    bool not_found = true;
    for(int i = 0; i < nRecords; i++)
    {
        if(pMan[i].GetPay() >= anyPay)
        {
            cout << *(pMan + i);
            not_found = false;
        }
    }
    if(not_found) cout << "Таких сотрудников нет\n";
}
