#include "triangle.h"



Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident)
        : v1(_v1), v2(_v2), v3(_v3)
{
    char buf[16];

    this->objID = new char[strlen(ident)+1];
    strcpy(this->objID, ident);

    count++;
    sprintf(buf, "Triangel %i", count);
    this->name = new char[strlen(buf)+1];
    strcpy(this->name, buf);

    this->a = sqrt(pow(v1.GetX() - v2.GetX(),2.0) + pow(v1.GetY() - v2.GetY(),2.0));
    this->b = sqrt(pow(v2.GetX() - v3.GetX(),2.0) + pow(v2.GetY() - v3.GetY(),2.0));
    this->c = sqrt(pow(v3.GetX() - v1.GetX(),2.0) + pow(v3.GetY() - v1.GetY(),2.0));

    cout << "Constructor_1 for: " << this->objID << " (" << this->name << ")" << endl;
}

Triangle::Triangle(const char* ident)
{
    char buf[16];

    this->objID = new char[strlen(ident)+1];
    strcpy(this->objID, ident);

    count++;
    sprintf(buf, "Triangel %i", count);
    this->name = new char[strlen(buf)+1];
    strcpy(this->name, buf);

    this->a = 0.0;
    this->b = 0.0;
    this->c = 0.0;

    cout << "Constructor_2 for: " << this->objID << " (" << this->name << ")" << endl;
}
Triangle::Triangle(const Triangle &t)
{
    this->objID = new char[strlen(t.objID) + strlen("copiya") + 1];
    strcpy(this->objID, t.objID);

    this->name = new char[strlen(t.name) + 1];
    strcpy(this->name, t.name);

    this->v1 = t.v1;
    this->v2 = t.v2;
    this->v3 = t.v3;

    this->a = t.a;
    this->b = t.b;
    this->c = t.c;

    cout << "Copy Constructor for: " << this->objID << " (" << this->name << ")" << endl;
}


Triangle::~Triangle()
{
    cout << "Destructor for: " << this->objID << endl;
    delete []this->objID;
    delete []this->name;
}

void Triangle::Show(void) const
{
    cout << this->name << ":";
    this->v1.Show();
    this->v2.Show();
    this->v3.Show();
    cout << endl;
}

//void Triangle::ShowSideAndArea(void) const
//{
//    double p = (this->a + this->b + this->c)/2.0;
//    double s = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
//    cout << "-----------------" << endl;
//    cout << this->name << ":";
//    cout.precision(4);
//    cout << " a=" << setw(5) << this->a;
//    cout << ". b=" << setw(5) << this->b;
//    cout << ". c=" << setw(5) << this->c;
//    cout << "; \ts =" << s << endl;
//}
void Triangle::Move(Point &dp)
{
    v1 += dp;
    v2 += dp;
    v3 += dp;
}

bool Triangle::operator >(const Triangle &tria) const
{
    double p = (this->a + this->b + this->c)/2.0;
    double s = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));

    double p1 = (tria.a + tria.b + tria.c)/2.0;
    double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));

    if(s > s1)  return true;
    else        return false;
}

Triangle & Triangle::operator =(const Triangle &t)
{
    if(&t == this)  return *this;


    delete []this->objID;
    this->objID = new char[strlen(t.objID) + 1];
    strcpy(this->objID, t.objID);

    delete []this->name;
    this->name = new char[strlen(t.name) + 1];
    strcpy(this->name, t.name);

    this->v1 = t.v1;
    this->v2 = t.v2;
    this->v3 = t.v3;

    this->a = t.a;
    this->b = t.b;
    this->c = t.c;

    return *this;
}

bool TriaInTria(Triangle tria1, Triangle tria2)
{
    Point v1 = tria1.Get_v1();
    Point v2 = tria1.Get_v2();
    Point v3 = tria1.Get_v3();
    return (v1.InTriange(tria2) &&
            v2.InTriange(tria2) &&
            v3.InTriange(tria2));

}
