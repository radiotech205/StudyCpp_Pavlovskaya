#ifndef CYROSTREAM_H
#define CYROSTREAM_H
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>

using namespace std;
#define MAX_STR_LEN 4096

class CyrOstream : public ostream
{
public:
    CyrOstream(_Uninitialized no_init) : ostream(no_init) {}
    CyrOstream& operator <<(_Myt& (__cdecl *_f)(_Myt&));
    CyrOstream& operator <<(ios_base& (__cdecl * _f)(ios_base&));

    CyrOstream& operator <<(short n) {cout << n; return *this;}
    CyrOstream& operator <<(unsigned short n) {cout << n; return *this;}

    CyrOstream& operator <<(int n) {cout << n; return *this;}
    CyrOstream& operator <<(unsigned int n) {cout << n; return *this;}

    CyrOstream& operator <<(long n) {cout << n; return *this;}
    CyrOstream& operator <<(unsigned long n) {cout << n; return *this;}

    CyrOstream& operator <<(float f) {cout << f; return *this;}
    CyrOstream& operator <<(double f) {cout << f; return *this;}

    CyrOstream& operator <<(long double f) {cout << f; return *this;}

    CyrOstream& operator <<(const void* v) {cout << v; return *this;}

    CyrOstream& operator <<(const char*);
    CyrOstream& operator <<(const unsigned char *s) {operator <<((const char*)s); return *this;}
    CyrOstream& operator <<(const signed char *s) {operator <<((const char*)s); return *this;}

    CyrOstream& operator <<(char);
    CyrOstream& operator <<(unsigned char);
    CyrOstream& operator <<(signed char c) {operator<< ((char)c); return *this;}

    CyrOstream& put(char);
    CyrOstream& write(const char*, int);
    CyrOstream& write(const unsigned char* s, int len) {write((const char*)s, len); return *this;}

    long setf(long lFlags) {return cout.setf(lFlags);}
    void unsetf(long lFlags) {cout.unsetf(lFlags);}
    char fill(char cFill) {return cout.fill(cFill);}
    char fill() {return cout.fill();}
    int precision(int np) {return cout.precision(np);}
    int precision() const {return cout.precision();}
    int width(int nw) {return cout.widht(nw);}
    int width() const {return cout.width();}
    int rdstate() const {return cout.rdstate();}
    long flags() const {return cout.flags();}
    long flags(long _l) {return cout.flags(_l);}
    streambuf* rdbuf() const {return cout.rdbuf();}

    friend CyrOstream& operator <<(CyrOstream&, const _Smanip<int>&);

private:
    char buf_[MAX_STR_LEN];
};


template <typename _E, typename _Tr, typename _A> inline
CyrOstream& operator <<(CyrOstream& os, const basic_string<_E, _Tr, _A> & _X>)
{
    string temp(_X);
    unsigned char symb[2];
    symb[1] = 0;
    for(int i = 0; i < temp.size(); i++)
    {
        symb[0] = temp.at(i);
        if(symb[0] > 191)
            CharToOem((const char*)symb, (char*)symb);
        cout << symb;
    }
    return os;
}

class CyrIstream: public istream
{
public:
    CyrIstream(_Uninitialized no_init) : istream(no_init) {}
    CyrIstream& operator >>(ios_base&(__cdecl * _f)(ios_base&));

    CyrIstream& operator >>(char*);
    CyrIstream& operator >>(unsigned char *s) {operator >>((char*)s); return *this;}
    CyrIstream& operator >>(signed char *s) {operator >>((char*)s); return *this;}

    CyrIstream& operator >>(char& c);
    CyrIstream& operator >>(unsigned char& c) {operator >>((char&)c); return *this;}
    CyrIstream& operator >>(signed char& c) {operator >>((char&)c); return *this;}

    CyrIstream& operator >>(short& n) {cin >> n; return *this;}
    CyrIstream& operator >>(unsigned short& n) {cin >> n; return *this;}

    CyrIstream& operator >>(int& n) {cin >> n; return *this;}
    CyrIstream& operator >>(unsigned int& n) {cin >> n; return *this;}

    CyrIstream& operator >>(long& n) {cin >> n; return *this;}
    CyrIstream& operator >>(unsigned long& n) {cin >> n; return *this;}

    CyrIstream& operator >>(float& f) {cin >> f; return *this;}
    CyrIstream& operator >>(double& f) {cin >> f; return *this;}
    CyrIstream& operator >>(long double& f) {cin >> f; return *this;}

    int get() {return cin.get();}
    CyrIstream& get(char&);
    CyrIstream& get(char*, int, char ='\n');
    CyrIstream& get(unsigned char*, int, char = '\n');
    CyrIstream& getline(char*, int, char = '\n');
    CyrIstream& getline(unsigned char* pch, int nCount, char delim = '\n')
    {
        getline((char*)pch, nCount, delim);
        return *this;
    }
    CyrIstream& read(char*, int);
    CyrIstream& read(unsigned char* pch, int nCount)
    {
        read((char*)pch, nCount);
        return *this;
    }
    int peek() {return cin.peek();}
    int gcount() const {return cin.gcount();}
    CyrIstream& putback(char ch) {cin.putback(ch); return *this;}

    void clear(int nState = 0) {cin.clear(nState);}
    long setf(long lFlags) {return cin.setfl(lFlags);}
    void unsetf(long lFlags) {return unsetfl(lFlags);}
    int rdstate()const {return cin.rdstate();}
    long flags() const {return cin.flags();}
    streambuf* rdbuf() const {return cin.rdbuf();}

    friend CyrIstream& operator >>(CyrIstream&, const _Smanip<int>&);

private:
    char buf_[MAX_STR_LEN];
};

template <typename _E, typename _Tr, typename _A> inline
CyrIstream& operator >>(CyrIstream& is, basic_string<_E, _Tr, _A>& _X)
{
    string temp;
    cin >> temp;
    unsigned int n = temp.size();
    char* buf = new char[n+1];
    temp.copy(buf, n);
    buf[n] = 0;
    OemToChar(buf, (char*)buf);
    _X = string(buf);
    delete []buf;
    return is;
}

extern CyrIstream Cin;
extern CyrOstream Cout;

#ifndef CYR_IOS_IMPLEMENTATION
#define cin Cin
#define cout Cout
#define istream CyrIstream
#define ostream CyrOstream
#endif
#endif // CYROSTREAM_H
