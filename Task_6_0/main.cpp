#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T> void print(T& cont);

class Man
{
public:
    Man(string _name, int _age) : name(_name), age(_age) {}
    bool operator< (const Man& m) const
    {
        return name < m.name;
    }
    friend ostream& operator<< (ostream&, const Man&);
    friend struct LessAge;

private:
    string name;
    int age;
};

ostream& operator<<(ostream& os, const Man& m)
{
    return os << endl << m.name << ", \t age: " << m.age;
}

struct LessAge
{
    bool operator() (const Man& a, const Man& b)
    {
        return a.age < b.age;
    }
};

int main()
{
    Man ar[] =
    {
        Man("Mary Poppins", 36),
        Man("Count Basie", 70),
        Man("Duke Ellington", 90),
        Man("Joy Amore", 18)
    };

    int size = sizeof(ar)/sizeof(Man);
    vector<Man> men(ar, ar + size);

    sort(men.begin(), men.end());
    print(men);

    sort(men.begin(), men.end(), LessAge());
    print(men);

    /**************************************/
    int arr[] = {1,5,9,7,5,3,8,5,2,1,4,7,3,6,9};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    vector<int> arrVec(arr, arr + arrSize);

    sort(arrVec.begin(), arrVec.end(), greater<int>());

    print(arrVec);
    /********************************************/
    int a[4] = {40, 30, 20, 10};
    vector<int> va(a, a + 4);

    int b[3] = {80, 90, 100};
    vector<int> vb(b, b + 3);

    int c[3] = {50, 60, 70};
    vector<int> vc(c, c + 3);

    list<int> L;

    copy(va.begin(), va.end(), front_inserter(L));
    print(L);

    copy(vb.begin(), vb.end(), back_inserter(L));
    print(L);

    list<int>::iterator from = L.begin();
    advance(from, 4);
    copy(vc.begin(), vc.end(), inserter(L, from));
    print(L);

    cout << "Hello World!" << endl;
    return 0;
}

template <typename T> void print(T& cont)
{
    typename T::const_iterator p = cont.begin();
    if(cont.empty())    cout << "Container is empty.";

    for(p; p != cont.end(); p++)
        cout << *p << " ";

    cout << endl;
}
