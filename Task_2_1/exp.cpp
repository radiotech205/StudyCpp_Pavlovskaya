#include "exp.h"
#include <cmath>
#include <iostream>
using namespace std;
void Exp::Calculate()
{
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter x = ";
    cin >> x;
    cin.get();
    cout << "y = " << exp(x) << endl;
    cin.get();
}

//Exp f_exp;
