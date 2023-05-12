#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include "point.h"

using namespace std;

class Triangle
{
public:
    Triangle(Point _v1, Point _v2, Point _v3, const char* ident);
    Triangle(const char* ident);
    Triangle(const Triangle &t);
    ~Triangle();
    Point Get_v1(void) const { return v1; }
    Point Get_v2(void) const { return v2; }
    Point Get_v3(void) const { return v3; }
    char* GetName(void) const { return name; }
    void Show(void) const;
//    void ShowSideAndArea(void) const;
    void Move(Point &dp);
    bool operator >(const Triangle &tria) const;
    Triangle & operator =(const Triangle &t);

    friend bool TriaInTria(Triangle tria1, Triangle tria2);
public:
    static int count;
private:
    char* objID;
    char* name;
    Point v1, v2, v3;
    double a;
    double b;
    double c;
};

#endif // TRIANGLE_H
