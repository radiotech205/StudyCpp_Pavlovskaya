#include "list.h"
#include <iostream>

using namespace std;

List::~List()
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

void List::Add(int d)
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

List::Node *List::Find(int i)
{
    Node *pv = pbeg;
    while(pv)
    {
        if(pv->d == i) break;
        pv = pv->next;
    }
    return pv;
}

List::Node *List::Insert(int key, int d)
{
    Node *pkey = this->Find(key);
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

bool List::Remove(int key)
{
    Node *pkey = this->Find(key);
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

void List::Print()
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

void List::PrintBack()
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
