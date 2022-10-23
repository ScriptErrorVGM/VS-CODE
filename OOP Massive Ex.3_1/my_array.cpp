#include "my_array.h"
#include <iostream>

MyArray::MyArray()
{
    size = 0;
}

void MyArray::add(float x)
{
    data[size] = x;
    size++;
}

void MyArray::del()
{
    size--;
}

void MyArray::info()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << "\n";
}

MyArray& MyArray::operator++()
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] + 1;
    }
    return *this;
}

MyArray MyArray::operator++(int x)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] + 1;
    }
    return *this;
}

MyArray& MyArray::operator--()
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] - 1;
    }
    return *this;
}

MyArray MyArray::operator--(int x)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] - 1;
    }
    return *this;
}