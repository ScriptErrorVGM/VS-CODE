#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

struct Number
{
    double x;
    double y;
};

void infoNumber(Number h);
void calcNumber(Number parr1, Number parr2, double &result);

#endif
