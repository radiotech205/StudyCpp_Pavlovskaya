#ifndef MENU_H
#define MENU_H
#include <vector>
#include "function.h"



class Menu
{
public:
    Menu(std::vector<Function*> _pObj);
    Function* SelectObject() const;
private:
    int SelectItem(int nItem) const;
    std::vector<Function*> pObj;
};

#endif // MENU_H
