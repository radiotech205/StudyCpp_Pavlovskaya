#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include "point.h"
#include "triangle.h"
using namespace std;

/************************************************/


int Triangle::count = 0;


int Menu(void);
int GetNumber(int, int);
void ExitBack(void);
void Show(Triangle* p_tria[] , int k);
void Move(Triangle* p_tria[], int k);
void FindMax(Triangle* p_tria[], int k);
void IsIncluded(Triangle* p_tria[], int k);
double GetDouble(void);

int main()
{
    Point p1(0, 0);
    Point p2(0.5, 1);
    Point p3(1, 0);
    Point p4(0, 4.5);
    Point p5(2, 1);
    Point p6(2, 0);
    Point p7(2, 2);
    Point p8(3, 0);

    Triangle triaA(p1, p2, p3, "TriaA");
    Triangle triaB(p1, p4, p8, "TriaB");
    Triangle triaC(p1, p5, p6, "TriaC");
    Triangle triaD(p1, p7, p8, "TriaD");

    Triangle *pTria[] = {&triaA, &triaB, &triaC, &triaD};
    int n = sizeof(pTria)/sizeof(pTria[0]);


    bool done = false;
    while(!done)
    {
        switch(Menu())
        {
        case 1: Show(pTria, n);
            break;
        case 2:Move(pTria, n);
            break;
        case 3: FindMax(pTria, n);
            break;
        case 4: IsIncluded(pTria, n);
            break;
        case 5: cout << "Завершение работы" << endl;
            done = true;
            break;
        }
    }

    cout << "Hello World!" << endl;
    return 0;
}

int Menu()
{
    cout << "\n============= Главное меню ===============" << endl;
    cout << "1 - вывести все объекты\t 3 - найти максимальный" << endl;
    cout << "2 - переместить \t\t 4 - определить отношение включения" << endl;
    cout << "\t\t 5 - выход" << endl;

    return GetNumber(1, 5);
}

int GetNumber(int min, int max)
{
    int number = min - 1;
    while(true)
    {
        cin >> number;
        if((number >= min) && (number <= max) && (cin.peek() == '\n'))
            break;
        else
        {
            cout << "Error" << endl;
            cin.clear();
            while(cin.get() != '\n') {};
        }
    }
    return number;
}

void ExitBack(void)
{
    cout << "Press Enter." << endl;
    cin.get();
    cin.get();
}

void Show(Triangle* p_tria[], int k)
{
    cout << "==========Перечень треугольников============" << endl;
    for(int i = 0; i < k; ++i)
        p_tria[i]->Show();

//    for(int i = 0; i < k; ++i)
//        p_tria[i]->ShowSideAndArea();

    ExitBack();
}

void Move(Triangle* p_tria[], int k)
{
    cout << "===============Перемещение==================" << endl;
    cout << "Введите номер треугольника" << endl;
    int i = GetNumber(1, k) - 1;
    p_tria[i]->Show();

    Point dp;
    cout << "Введите смещение по x";
    dp.SetX(GetDouble());
    cout << "Введите смещение по y";
    dp.SetY(GetDouble());

    p_tria[i]->Move(dp);
    cout << "Новое положение треугольника:" << endl;
    p_tria[i]->Show();

    ExitBack();
}
void FindMax(Triangle* p_tria[], int k)
{
    cout << "=====Поиск максимального треугольника====" << endl;
    Triangle triaMax("TriaMax");
    triaMax = *p_tria[0];

    for(int i = 1; i < k; ++i)
        if(*p_tria[i] > triaMax)
            triaMax = *p_tria[i];

    cout << "Максимальный треугольник: " << triaMax.GetName()<< endl;

    ExitBack();
}
void IsIncluded(Triangle* p_tria[], int k)
{
    cout << "==========Отношение включения=============" << endl;
    cout << "Введите номер 1-го треугольника: ";
    int i1 = GetNumber(1, k) - 1;

    cout << "Введите номер 2-го треугольника: ";
    int i2 = GetNumber(1, k) - 1;

    if(TriaInTria(*p_tria[i1], *p_tria[i2]))
        cout << p_tria[i1]->GetName() << " входит в " << p_tria[i2]->GetName() << endl;
    else
        cout << p_tria[i1]->GetName() << " не входит в " << p_tria[i2]->GetName() << endl;


    ExitBack();
}

double GetDouble(void)
{
    double value;
    while(true)
    {
        cin >> value;
        if(cin.peek() == '\n')
            break;
        else
        {
            cout << "Введите вещественное число" << endl;
            cin.clear();
            while(cin.get() != '\n')    {};
        }
    }
    return value;
}
