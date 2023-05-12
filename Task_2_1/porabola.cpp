#include "porabola.h"
#include <iostream>

using namespace std;

void Porabola::Calculate()
{
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter a = ";
    cin >> a;
    cout << "Enter b = ";
    cin >> b;
    cout << "Enter c = ";
    cin >> c;
    cout << "Enter x = ";
    cin >> x;
    cin.get();
    cout << "y = " << (a*x*x + b*x + c) << endl;
    cin.get();
}

//Porabola f_porabola;
