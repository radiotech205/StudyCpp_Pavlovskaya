#include "point.h"
#include "triangle.h"

double Point::Length() const
{
    return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0));
}
ORIENT Point::Classify(Point beg_p, Point end_p) const
{
    Point p0 = *this;
    Point a = end_p - beg_p;
    Point b = p0 - beg_p;
    double sa = a.x*b.y - b.x*a.y;

    if(sa > 0.0) return LEFT;
    if(sa < 0.0) return RIGHT;

    if((a.x*b.x < 0.0) || (a.y*b.y < 0.0))  return BEHIND;
    if(a.Length() < b.Length()) return AHEAD;

    return BETWEEN;
}
bool Point::InTriange(Triangle &rv) const
{
    ORIENT or1 = Classify(rv.Get_v1(), rv.Get_v2());
    ORIENT or2 = Classify(rv.Get_v2(), rv.Get_v3());
    ORIENT or3 = Classify(rv.Get_v3(), rv.Get_v1());

    if((or1 == RIGHT || or1 ==BETWEEN)
     &&(or2 == RIGHT || or2 ==BETWEEN)
     &&(or3 == RIGHT || or3 ==BETWEEN))
        return true;
    else
        return false;
}
void Point::operator +=(Point &p)
{
    this->x += p.x;
    this->y += p.y;
}
Point Point::operator +(Point &rv)
{
    return Point(this->x + rv.x, this->y + rv.y);
}
Point Point::operator -(Point &rv)
{
    return Point(this->x - rv.x, this->y - rv.y);
}
