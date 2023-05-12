#include <iostream>
#include "function.h"
#include "exp.h"
#include "line.h"
#include "porabola.h"
#include "action.h"
#include "calculation.h"
#include "tabulation.h"
#include "anyaction.h"
#include "menu.h"
using namespace std;


int main()
{
    Exp f_exp;
    Line f_line;
    Porabola f_porabola;

    Calculation calculation;
    Tabulation tabulation;
    AnyAction any_action;

    Function* pObjs[] = {&f_exp, &f_line, &f_porabola};
    vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs)/sizeof(Function*));

    Action* pActs[] = {&calculation, &tabulation, &any_action};
    vector<Action*> operList(pActs, pActs + sizeof(pActs)/sizeof(Action*));

    Menu menu(funcList, operList);
    while(Function *pObj = menu.SelectObject())
    {
        Action* pAct = menu.SelectAction(pObj);
        pAct->Operate(pObj);
    }

    cout << "Bye!\n";
    cout << "Hello World!" << endl;
    return 0;
}
