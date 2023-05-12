#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

#include <deque>

#include <list>

#include <functional>
using namespace std;

template <typename T> void print(T& cont);

int main()
{
    ifstream in("../inpnum.txt");
    if(!in) {cerr << "File is not found\n"; return 1;}

    vector<int> v;
    int x;

    while(in >> x) v.push_back(x);

    sort(v.begin(), v.end());

    vector<int>::iterator i;
    for(i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl << endl;
    /***************************************/
    double arr[] = {1.1, 2.2, 3.3, 4.4};
    int n = sizeof(arr)/sizeof(double);

    vector<double> v1(arr, arr + n);
    vector<double> v2;

    v1.swap(v2);

    while(!v2.empty())
    {
        cout << v2.back() << " ";
        v2.pop_back();
    }
    cout << endl << endl;
    /**************************************/
    deque<int> dec;     print(dec);
    dec.push_back(4);   print(dec);
    dec.push_front(3);  print(dec);

    dec.push_back(5);   print(dec);
    dec.push_front(2);  print(dec);

    dec.push_back(6);   print(dec);
    dec.push_front(1);  print(dec);

    cout << endl << endl;
    /********************************/
    int arrInt[] = {1, 2, 3, 4, 5, 2, 6, 2, 7};
    int arrIntCnt = sizeof(arrInt)/sizeof(int);

    vector<int> vInt(arrInt, arrInt+arrIntCnt);
    int value = 2;

    int howMuch = count(vInt.begin(), vInt.end(), value);
    cout << "howMuch = " << howMuch << endl;

    list<int> locList;

    vector<int>::iterator location = vInt.begin();

    int temp1, temp2;
    while(1)
    {
        location = find(location, vInt.end(), value);
        if(location == vInt.end())    break;

        temp1 = location - vInt.begin();
        locList.push_back(temp1);
        //temp2 = location;
        cout << temp1 << "\t\t" << *location << endl;
        location++;
    }

    print(locList);
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
