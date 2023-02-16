#include <iostream>

using namespace std;

class x
{
    private:
    x(int i)
    {
        a = i; 
    }
    private:
        int a;
};


int main()
{
    x(5);
}