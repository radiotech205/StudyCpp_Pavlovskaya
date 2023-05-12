#ifndef VECTERROR_H
#define VECTERROR_H
#include <iostream>
#define DEBUG

class VectError
{
public:
    VectError() {}
    virtual ~VectError() {}
    virtual void ErrMsg() const {std::cerr << "Error with Vect object\n";}
    void Continue() const
    {
#ifdef DEBUG
        std::cerr << "Debug: program is being Continued\n";
#else
        throw;
#endif
    }
};

class VectRangeErr : public VectError
{
public:
    VectRangeErr(int _min, int _max, int _actual) : min(_min), max(_max), actual(_actual) {}
    virtual ~VectRangeErr() {}
    virtual void ErrMsg() const
    {
        std::cerr << "Error of index: ";
        std::cerr << "possible range: " << min << " - " << max << ", ";
        std::cerr << "actual index: " << actual << std::endl;
        Continue();
    }
private:
    int min, max;
    int actual;
};


class VectPopErr : public VectError
{
public:
    virtual ~VectPopErr()   {}
    virtual void ErrMsg() const
    {
        std::cerr << "Error of pop\n";
        Continue();
    }
};
#endif // VECTERROR_H
