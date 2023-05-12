#ifndef MENU_H
#define MENU_H
#include <vector>
#include "astring.h"
#include "action.h"
#include "factory.h"


typedef enum {AddObj, DelObj, WorkWithObj, Exit} JobMode;

class Menu
{
public:
    Menu(std::vector<Action*> _pAct);
    JobMode  SelectJob() const;
    AString* SelectObject(const Factory& fctry) const;
    Action*  SelectAction(const AString* pObj) const;
//    int SelectItem(int nItem);
private:
    std::vector<Action*> pAct;
};
int SelectItem(int nItem);
#endif // MENU_H
