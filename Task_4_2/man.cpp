#include "man.h"
#include "getfunc.h"

Man::Man(int lName)
{
    pName = new char[lName + 1];
}
Man::~Man()
{
    if(pName)
        delete []pName;
}
double Man::GetPay() const
{
    return pay;
}
istream & operator >>(istream& in, Man& ob)
{
    cout << "\n Введите данные в формате" << endl;
    cout << "ФИО <Enter> Год поступления <Enter>";
    cout << "Оклад <Enter>:" << endl;
    in.getline(ob.pName, l_name);
    ob.come_year = GetInt(in);
    ob.pay = GetDouble(in);
    return in;
}
ostream & operator <<(ostream& out, Man& ob)
{
    out << setw(30) << setiosflags(ios::left);
    out << ob.pName << " ";
    out << ob.come_year << " ";
    out << ob.pay << endl;
    return out;
}
