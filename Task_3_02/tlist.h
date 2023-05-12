#ifndef TLIST_H
#define TLIST_H

template <typename Data>
class TList
{
    class Node
    {
    public:
        Data d;
        Node *next;
        Node *prev;
        Node(Data dat = 0) : d(dat), next(0), prev(0) {}
    };
private:
    Node *pbeg, *pend;
public:
    TList() : pbeg(0), pend(0) {}
    ~TList();

    void Add(Data d);
    void* Find(Data i);
    void* Insert(Data key, Data d);
    bool Remove(Data key);
    void Print();
    void PrintBack();
};


#include <iostream>

using namespace std;

template <typename Data>
TList<Data>::~TList()
{
    if(this->pbeg != 0)
    {
        Node *pv = pbeg;
        while(pv)
        {
            pv = pv->next;
            delete pbeg;
            pbeg = pv;
        }
    }
}
template <typename Data>
void TList<Data>::Add(Data d)
{
    Node *pv = new Node(d);
    if(pbeg == 0)
    {
        pbeg = pv;
        pend = pv;
    }
    else
    {
        pv->prev = pend;
        pend->next = pv;
        pend = pv;
    }
}
template <typename Data>
void* TList<Data>::Find(Data i)
{
    Node *pv = pbeg;
    while(pv)
    {
        if(pv->d == i) break;
        pv = pv->next;
    }
    return pv;
}
template <typename Data>
void* TList<Data>::Insert(Data key, Data d)
{
    Node *pkey = (Node*)this->Find(key);
    if(pkey)
    {
        Node *pv = new Node(d);
        pv->next = pkey->next;
        pv->prev = pkey;
        pkey->next = pv;
        if(pkey != pend)
            (pv->next)->prev = pv;
        else
            pend = pv;
        return pv;
    }
    return 0;
}
template <typename Data>
bool TList<Data>::Remove(Data key)
{
    Node *pkey = (Node*)this->Find(key);
    if(pkey)
    {
        if(pkey == pbeg)
        {
            pbeg = pbeg->next;
            pbeg->prev = 0;
        }
        else if(pkey == pend)
        {
            pend = pend->prev;
            pend->next = 0;
        }
        else
        {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}
template <typename Data>
void TList<Data>::Print()
{
    Node *pv = this->pbeg;
    cout << endl << "list: ";
    while(pv)
    {
        cout << pv->d << " ";
        pv = pv->next;
    }
    cout << endl;
}
template <typename Data>
void TList<Data>::PrintBack()
{
    Node *pv = this->pend;
    cout << endl << "list back: ";
    while(pv)
    {
        cout << pv->d << " ";
        pv = pv->prev;
    }
    cout << endl;
}

#endif // TLIST_H
