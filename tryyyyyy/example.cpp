#include <iostream>

using namespace std;

void x(int a,int &b)
{
    a=a+b;
    a=a-b;
    b=b-a;
}


int main()
{
    int a=4,b=10;
    x(a,b);
    cout << a << ", " << b;
}