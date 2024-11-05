
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include "my_array.h"

using namespace std;

int main()
{
    MyArray arr1;
    arr1.add(3);
    arr1.add(4);
    arr1.add(5);
    arr1.info();
    arr1.del();
    arr1.info();
    return 0;
}
