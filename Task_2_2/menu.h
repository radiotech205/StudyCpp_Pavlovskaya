#ifndef MENU_H
#define MENU_H
#include <vector>
#include "function.h"
#include "action.h"


class Menu
{
public:
    Menu(std::vector<Function*> _pObj, std::vector<Action*> _pAct);
    Function* SelectObject() const;
    Action* SelectAction(Function* pObj) const;
private:
    int SelectItem(int nItem) const;
    std::vector<Function*> pObj;
    std::vector<Action*> pAct;
};

#endif // MENU_H
