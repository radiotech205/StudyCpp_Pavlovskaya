#include <iostream>
#include "function.h"
#include "exp.h"
#include "line.h"
#include "porabola.h"
#include "menu.h"
using namespace std;

//Function* pObjs[] = {&f_exp, &f_line, &f_porabola};
//vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs)/sizeof(Function*));

int main()
{
    Exp f_exp;
    Line f_line;
    Porabola f_porabola;

    Function* pObjs[] = {&f_exp, &f_line, &f_porabola};
    vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs)/sizeof(Function*));

    Menu menu(funcList);
    while(Function *pObj = menu.SelectObject())
    {
        pObj->Calculate();
    }

    cout << "Bye!\n";
    cout << "Hello World!" << endl;
    return 0;
}
