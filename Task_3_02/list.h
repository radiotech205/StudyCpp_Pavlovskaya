#ifndef LIST_H
#define LIST_H




class List
{
    class Node
    {
    public:
        int d;
        Node *next;
        Node *prev;
        Node(int dat = 0) : d(dat), next(0), prev(0) {}
    };
private:
    Node *pbeg, *pend;
public:
    List() : pbeg(0), pend(0) {}
    ~List();

    void Add(int d);
    Node *Find(int i);
    Node *Insert(int key, int d);
    bool Remove(int key);
    void Print();
    void PrintBack();
};
#endif // LIST_H
