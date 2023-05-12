#include <iostream>
using namespace std;

int GetInt(istream &in)
{
    int value;
    while(true)
    {
        in >> value;
        if(in.peek() == '\n')
        {
            in.get();
            break;
        }
        else
        {
            cout << "Повторите ввод (ожидается целое число):" << endl;
            in.clear();
            while(in.get() != '\n') {};
        }
    }
    return value;
}

int GetDouble(istream &in)
{
    double value;
    while(true)
    {
        in >> value;
        if(in.peek() == '\n')
        {
            in.get();
            break;
        }
        else
        {
            cout << "Повторите ввод (ожидается вещественное число):" << endl;
            in.clear();
            while(in.get() != '\n') {};
        }
    }
    return value;
}
