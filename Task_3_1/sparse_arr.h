#ifndef SPARSE_ARR_H
#define SPARSE_ARR_H
#include <list>

template <typename DataT>
class SA_item
{
public:
    SA_item() : index(-1), info(DataT()) {}
    SA_item(long i, DataT d) : index(i), info(d) {}
    long index;
    DataT info;
};

template <typename T>
class SparseArr
{
public:
    SparseArr(long len) : length(len) {}
    T& operator [](long ind);
    void Show(const char *title);
//private:
    std::list<SA_item<T> > arr;
    long length;
};

template <typename T>
T& SparseArr<T>::operator[](long ind)
{
    if((ind < 0) || (ind > length-1))
    {
        std::cerr << "Error of index: " << ind << std::endl;
        SA_item<T> temp;
        return temp.info;
    }

//    std::list<char> v1;
//    v1.push_back('A');
//    v1.push_back('B');
//    v1.push_back('C');

//    std::list<char>::iterator i1 = v1.begin();
//    std::list<char>::iterator n1 = v1.end();

    std::list<SA_item<T> > ::iterator i = arr.begin();
    std::list<SA_item<T> > ::iterator n = arr.end();


    for(i; i != n; ++i)
    {
        if(ind == i->index)
            return i->info;
    }

    arr.push_back(SA_item<T>(ind, T()));
    i = arr.end();
    return (--i)->info;
}

template <typename T>
void SparseArr<T>::Show(const char *title)
{
    std::cout << "====" << title << "====\n";
    std::list<SA_item<T> >::iterator i = arr.begin();
    std::list<SA_item<T> >::iterator n = arr.end();

    for(i; i != n; ++i)
        std::cout << i->index << "\t" << i->info << std::endl;
}
#endif // SPARSE_ARR_H
