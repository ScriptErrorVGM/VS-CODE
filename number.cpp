#include "number.h"
#include <cmath>
#include <complex>


Number div(Number a, Number b)
{
    
    std::complex<double> A(a.x,a.y);
    std::complex<double> B(b.x,b.y);
    Number x;

    double real = std::real(std::complex(A / B));
    double image = std::imag(std::complex(A / B));
    x = {real,image};
    
    return x;
}


Number multi(Number a, Number b)
{
    std::complex<double> A(a.x,a.y);
    std::complex<double> B(b.x,b.y);
    Number x;

    double real = std::real(std::complex(A * B));
    double image = std::imag(std::complex(A * B));
    x = {real,image};
    
    return x;
}


typeNum typeN(Number a)
{
    typeNum x;
    
    if(a.y == 0){
        x = REAL;
    } else if(a.x == 0) {
        x = IMAGINARY;
    } else {
        x = COMPLEX;
    }
    return x;
}


void Output(Number h)
{   
    std::cout << h.x << " "  << h.y << std::endl;
    
    printf("z = %.2f + (%.2f*i)\n", h.x, h.y);
}

