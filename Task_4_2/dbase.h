#ifndef DBASE_H
#define DBASE_H
#include "man.h"

class DBase
{
public:
    DBase(int nRec) : nRecords(nRec), pMan(new Man[nRec]) {}
    ~DBase() { if(pMan)delete []pMan;}
    void InitInput();
    void Show();
    void SearchPayNotLess(double anyPay);
private:
    int nRecords;
    Man *pMan;
};

#endif // DBASE_H
