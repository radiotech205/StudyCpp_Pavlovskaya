#include <iostream>

using namespace std;

template <typename T> struct LessThan
{
    bool operator() (const T& x, const T& y)
    {
        return x < y;
    }
};

template <typename T> struct GreaterThan
{
    bool operator() (const T& x, const T& y)
    {
        return x > y;
    }
};

template <typename T, typename Compare> class PairSelect
{
public:
    PairSelect(const T& x, const T& y) : a(x), b(y) {}
    void OutSelect() const
    {
        cout << (Compare()(a, b) ? a : b) << endl;
    }
private:
    T a, b;
};

int main()
{
    PairSelect <int, LessThan<int> > ps1(13, 9);
    ps1.OutSelect();

    PairSelect <double, GreaterThan<double> > ps2(13.8, 9.8);
    ps2.OutSelect();

    cout << "Hello World!" << endl;
    return 0;
}
