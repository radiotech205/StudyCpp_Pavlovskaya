#define CYR_IOS_IMPLEMENTATION
#include "cyrostream.h"

CyrOstream& CyrOstream::operator <<(_Myt& (__cdecl *_f)(_Myt&))
{
    cout << _f;
    return *this;
}

CyrOstream& CyrOstream::operator <<(ios_base& (__cdecl * _f)(ios_base&))
{
    cout << _f;
    return *this;
}

CyrOstream& CyrOstream::operator <<(const char* s)
{
    int n = strlen(s);
    strncpy(buf_, s, n);
    buf_[n] = 0;
    CharToOem(buf_, buf_);
    cout << buf_;
    return *this;
}

CyrOstream& CyrOstream::operator <<(char c)
{
    buf_[0] = c;
    buf_[1] = 0;
    CharToOem(buf_, buf_);
    cout << buf_;
    return *this;
}

CyrOstream& CyrOstream::operator <<(unsigned char c)
{
    unsigned char buf[2];
    buf[0] = c;
    buf[1] = 0;
    if(c > 191)
        CharToOem((const char*)buf, (char*)buf);
    cout << buf;
    return *this;
}

CyrOstream& CyrOstream::put(char c)
{
    buf_[0] = c;
    buf_[1] = 0;
    cout.put(buf_[0]);
    return *this;
}

CyrOstream& CyrOstream::write(const char* s, int len)
{
    int n = strlen(s);
    strncpy(buf_, s, n);
    buf_[n] = 0;
    CharToOem(buf_, buf_);
    cout.write(buf_, len);
    return *this;
}

CyrOstream& operator <<(CyrOstream& os, const _Smanip<int>& m)
{
    cout << m;
    return os;
}
/**********************************************************/
CyrIstream& CyrIstream::operator >>(ios_base& (__cdecl * _f)(ios_base&))
{
    cin >> _f;
    return *this;
}

CyrIstream& CyrIstream::operator >>(char* s)
{
    string temp;
    cin >> temp;
    unsigned int n = temp.size();
    temp.copy(buf_, n);
    buf_[n] = 0;
    OemToChar(buf_, buf_);
    strncpy(s, buf_, n+1);
    return *this;
}

CyrIstream& CyrIstream::operator >>(char& c)
{
    cin >> buf_[0];
    buf_[1] = 0;
    OemToChar(buf_, buf_);
    c = buf_[0];
    return *this;
}

CyrIstream& CyrIstream::get(char& symb)
{
    cin.get(buf_[0]);
    buf_[1] = 0;
    OemToChar(buf_, buf_);
    symb = buf_[0];
    return *this;
}

CyrIstream& CyrIstream::get(char* pch, int nCount, char delim)
{
    cin.get(pch, nCount, delim);
    OemToChar(pch, pch);
    return *this;
}

CyrIstream& CyrIstream::get(unsigned char* pch, int nCount, char delim)
{
    cin.get((char*)pch, nCount, delim);
    OemToChar((const char*)pch, (char*)pch);
    return *this;
}

CyrIstream& CyrIstream::getline(char* pch, int nCount, char delim)
{
    cin.getline(pch, nCount, delim);
    OemToChar(pch, pch);
    return *this;
}

CyrIstream& CyrIstream::read(char* pch, int nCount)
{
    cin.read(buf_, nCount);
    buf_[nCount] = 0;
    OemToChar(buf_, buf_);
    for(int i = 0; i < nCount; i++)
        pch[i] = buf_[i];
    return *this;
}

CyrIstream& operator >>(CyrIstream& is, const _Smanip<int>& m)
{
    cin >> m;
    return is;
}
/*********************************************************/
CyrIstream Cin(_Noinit);
CyrOstream Cout(_Noinit);
