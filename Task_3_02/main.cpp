#include <iostream>
#include "list.h"
#include "tlist.h"
using namespace std;

class A
{
public:
    A()     {cout << "Constr A\n";}
    ~A()    {cout << "Destr A\n";}
};

class Error
{
public:
    virtual void ErrProcess() {cout << "Error Poly\n";}
    virtual ~Error() {}
};

class ErrorOfA : public Error
{
public:
    virtual void ErrProcess() {cout << "ErrorOfA Poly\n";}
    virtual ~ErrorOfA()  {}
};

class ErrorOfB : public ErrorOfA
{
public:
    virtual void ErrProcess() {cout << "ErrorOfB Poly\n";}
    virtual ~ErrorOfB()  {}
};
void foo()
{
    A a;
    throw 50;
    cout << "Msg never printed\n";
}

int main()
{
    TList <int> L;
    for(int i = 2; i < 6; i++) L.Add(i);
    L.Print();
    L.PrintBack();
    L.Insert(2, 200);
    if(!L.Remove(50))    cout << "Not found";
    L.Print();
    L.PrintBack();


    try
    {
        foo();
        //throw ErrorOfA();
        //throw ErrorOfB();
        throw Error();
    }
    catch(int i)  {cerr << "catch int = " << i << endl;}
//    catch(ErrorOfA)  {cerr << "catch ErrorOfA\n";}
//    catch(Error)  {cerr << "catch Error\n";}

    catch(Error &err)  {err.ErrProcess();}



    cout << "Hello World!" << endl;
    return 0;
}

