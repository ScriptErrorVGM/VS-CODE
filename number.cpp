#include "number.h"
#include <cmath>
#include <complex>


void infoNumber(Number h)
{
    
}


void calcNumber(Number parr1, Number parr2, double &result)
{
    //std::complex<double> result;
    std::complex<double> h1(parr1.x,parr1.y);
    std::complex<double> h2(parr2.x,parr2.y);
    std::cout   << "diveded = "<< h1 / h2 <<'\n';
    //std::cout   << "multiplyed = " <<H1 * H2 <<'\n';

    //double x = real(mycomplex);
    //double y = imag(mycomplex);
    result = norm(h1 / h2);
}

void Output(Number h)
{
    printf("z = %.f + (%.f*i)\n", h.x, h.y);
}

