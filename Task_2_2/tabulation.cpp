#include "tabulation.h"
#include <iostream>
#include <iomanip>
using namespace std;
void Tabulation::Operate(Function *pFunc)
{
    cout << "Tabulation for function y = ";
    cout << pFunc->GetName() << endl;
    pFunc->SetCoeff();
    double x_beg, x_end, x_step;

    cout << "Enter x_beg = ";
    cin >> x_beg;
    cout << "Enter x_end = ";
    cin >> x_end;
    cout << "Enter x_step = ";
    cin >> x_step;
    cin.get();

    cout << "------------------" << endl;
    cout << "       x         y" << endl;
    cout << "------------------" << endl;

    double x = x_beg;
    while(x <= x_end)
    {
        pFunc->SetArg(x);
        cout << setw(6) << x << setw(14) << pFunc->GetVal() << endl;
        x += x_step;
    }
    cin.get();
}
