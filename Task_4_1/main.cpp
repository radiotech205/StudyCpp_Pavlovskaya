#include <iostream>
#include "cyrostream.h"
using namespace std;

int main()
{
    char str[] = "++!\n";
    cout << "Добро пожаловать в ";
    cout.put('C');
    cout.write(str, strlen(str));

    double y = 372.141526;
    cout.width(20);
    cout << y << endl;

    cout.fill('.');
    cout.width(20);
    cout << y << endl;

    cout.precision(10);
    cout.width(20);
    cout << y << endl;

    cout << "Hello World!";
    cout << endl;
    return 0;
}
