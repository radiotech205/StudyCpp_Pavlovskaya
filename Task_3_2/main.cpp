#include <iostream>
#include <string>
#include "vect.h"
#include "vecterror.h"
using namespace std;

template <typename T>
void SomeFunction(Vect<T> v)
{
    cout << "Reversive output for " << v.mark() << " : " << endl;
    for(int i = v.size()-1; i >= 0; i--)
        cout << v[i] << "  ";
    cout << endl;
}

int main()
{
    try
    {
        string initStr[5] = {"first", "second", "third", "fourth", "fifth"};

        Vect<int> v1(10);
        string str = ("v1");
        v1.mark(str/*string("v1")*/);
        for(uint i = 0; i < v1.size(); i++)  v1[i] = i+1;
        v1.show();
        SomeFunction(v1);
        try
        {
            Vect<string> v2(5);
            str.clear();
            str = ("v2");
            v2.mark(str/*string("v2")*/);
            for(uint i = 0; i < v2.size(); i++) v2[i] = initStr[i];

            v2.show();
            v2.insert(v2.begin() + 3, "After_third");
            v2.show();
            cout << v2[6] << endl;
            v2.push_back("Add_1");
            v2.push_back("Add_2");
            v2.push_back("Add_3");
            v2.show();

            v2.pop_back();
            v2.pop_back();
            v2.show();
        }
        catch(VectError &vre)   { vre.ErrMsg();}

        try
        {
            Vect<int> v3;
            str.clear();
            str = ("v3");
            v3.mark(str/*string("v3")*/);

            v3.push_back(41);
            v3.push_back(42);
            v3.push_back(43);
            v3.show();

            Vect<int> v4;
            str.clear();
            str = ("v4");
            v4.mark(str/*string("v4")*/);
            v4 = v3;
            v4.show();

            v3.pop_back();
            v3.pop_back();
            v3.pop_back();
            v3.pop_back();

            v3.show();

            str.clear();
        }
        catch(VectError &vre)   {vre.ErrMsg();}
    }
    catch(...)  {cerr << "Epiloge: error of Main().\n";}
    cout << "Hello World!" << endl;
    return 0;
}
