#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include "typenum.h"

struct Number
{
    double x;
    double y;
};

Number div(Number a, Number b);
Number multi(Number a, Number b);
typeNum typeN(Number a);

#endif
