#ifndef MYARRAY_H
#define MYARRAY_H

const int MAX = 10;

class MyArray 
{
    public:
    float data[MAX];
    int size;
    MyArray();
    void add(float x);
    void del();
    void info();
};

#endif
