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
    for(int i=0; i<size; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << "\n";
}


