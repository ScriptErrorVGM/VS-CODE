#ifndef STORE_H
#define STORE_H

#include <iostream>

const int MAX = 100;

class Store
{
private:
    int data[MAX];
    int size;
public:
    Store();
    void add(int x);
    void del();
    class iterator
    {
    private:
        int index;
        Store* pdata;
    public:
        iterator();
        iterator(int i, Store* p);
        Store::iterator operator++();
        bool operator !=(Store::iterator x);
        bool operator ==(Store::iterator x);
        int& operator*();
    };
    Store::iterator begin();
    Store::iterator end();
};

#endif // STORE_H
