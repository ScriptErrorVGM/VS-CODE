#include "number.h"
#include <cmath>
#include <complex>

//функция деление комплексного числа 
Number div(Number a, Number b)
{
    Number x;

    double real = ((a.real*b.real + a.imag*b.imag)/(b.real*b.real + b.imag*b.imag));
    double image = ((a.imag*b.real - a.real*b.imag)/(b.real*b.real + b.imag*b.imag));
    
    x = {real,image};
    
    return x;
}

//функция умножения комплексного числа 
Number multi(Number a, Number b)
{
    Number x;

    double real = (a.real*b.real - a.imag*b.imag);
    double image = (a.imag*b.real + a.real*b.imag);

    x = {real,image};
    
    return x;
}

// функция определния типа числа
typeNum typeN(Number a)
{
    typeNum x;
    
    if(a.imag == 0){
        x = REAL;
    } else if(a.real == 0) {
        x = IMAGINARY;
    } else {
        x = COMPLEX;
    }
    return x;
}

//функция вывода
void Output(Number h)
{   
    std::cout << "Result is : " << std::endl;
    // std::cout << h.x << " "  << h.y << std::endl;
    
    printf("z = %.2f + (%.2f*i)\n", h.real, h.imag);
}

