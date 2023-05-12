#include <iostream>
#include "man.h"
#include "dbase.h"
#include "getfunc.h"
using namespace std;

int main()
{
    const int nRecords = 10;

    double anyPay;

    DBase dBase(nRecords);
    dBase.InitInput();
    dBase.Show();

    cout << "Ввод данных завершён." << endl;
    cout << "=======================================" << endl;
    cout << "Поиск сотрудников, чей оклад не меньше заданной величины." << endl;
    cout << "Поиск завершается при вводе -1" << endl;

    while(true)
    {
        cout << "\n Введите величину оклада или -1: ";
        anyPay = GetDouble(cin);
        if(anyPay == -1) break;
        dBase.SearchPayNotLess(anyPay);
    }

    cout << "Hello World!" << endl;
    return 0;
}
