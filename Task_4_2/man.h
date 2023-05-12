#ifndef MAN_H
#define MAN_H
#include <iostream>
#include <iomanip>
using namespace std;
const int l_name = 30;

class Man
{
public:
    Man(int lName = 30);
    ~Man();
    double GetPay() const;
    friend istream & operator >>(istream&, Man&);
    friend ostream & operator <<(ostream&, Man&);
private:
    char *pName;
    int come_year;
    double pay;
};

#endif // MAN_H
