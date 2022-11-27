#ifndef MYTEMPLATES
#define MYTEMPLATES

#include<iostream>

const int MAXSIZE = 100;

template <class T>
class Container
{
private:
    T data[MAXSIZE];
    int size;
public:
    Container();
    void add(T x);
    void del();
    void info();
};

template <class T>
Container<T>::Container()
{
    size = 0;
}

template <class T>
void Container<T>::add(T x)
{
    if(size < MAXSIZE){
        int sum = 0;
        for(int i = 0; i < size-1; i++)
            {
                if ((x == data[i]))
                {
                    sum += 1;
                } else if(sum >= 2)
                    break;
            }
        if(sum < 2){
            data[size] = x;
            size++;
        }
    } else {
        std::cout << "ERROR: out of range"<< "\n";
    }
}

template <class T>
void Container<T>::del()
{   if(size > 0){
        size--; 
    } else {
        std::cout << "ERROR: out of range"<< "\n";
    }
}

template <class T>
void Container<T>::info()
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    if (size > 0)
    {
        std::cout << data[size - 1];
    }
    std::cout << "\n";
}

#endif // MYTEMPLATES
