#include <iostream>
#include "astring.h"
#include "sumbstring.h"
#include "hexstring.h"
#include "action.h"
#include "showstr.h"
#include "showdec.h"
#include "showbin.h"
#include "showoct.h"
#include "factory.h"
#include "menu.h"
using namespace std;

int main()
{
    ShowStr show_str;
    ShowDec show_dec;
    ShowBin show_bin;
    ShowOct show_oct;

    Action* pActs[] = {&show_str, &show_dec, &show_bin, &show_oct};
    vector<Action*> actionList(pActs, pActs + sizeof(pActs)/sizeof(Action*));

    Factory factory;
    Menu menu(actionList);
    JobMode jobMode;

    while((jobMode = menu.SelectJob()) != Exit)
    {
        switch(jobMode)
        {
        case AddObj: factory.AddObject();
            break;
        case DelObj:factory.DeleteObject();
            break;
        case WorkWithObj:
            AString *pObj = menu.SelectObject(factory);
            Action *pAct = menu.SelectAction(pObj);
            if(pAct)
                pAct->Operate(pObj);

            break;
        }
        cin.get();
    }

    cout << "Hello World!" << endl;
    return 0;
}
