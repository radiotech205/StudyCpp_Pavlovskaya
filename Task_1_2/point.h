#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>

using namespace std;
enum ORIENT {LEFT, RIGHT, AHEAD, BEHIND, BETWEEN};

class Triangle;

class Point
{
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void Show(void) const {cout << " (" << this->x << " . " << this->y <<")";}
    void SetX(double x) {this->x = x;}
    void SetY(double y) {this->y = y;}
    double GetX(void)   {return this->x;}
    double GetY(void)   {return this->y;}

    double Length() const;
    ORIENT Classify(Point beg_p, Point end_p) const;
    bool InTriange(Triangle &rv) const;

    void operator +=(Point &p);
    Point operator +(Point &rv);
    Point operator -(Point &rv);
};

#endif // POINT_H
