#ifndef WOLF_H
#define WOLF_H
#include "wild_animal.h"

class Wolf: public Wild_Animal
{
public:
    Wolf();
    Wolf(std::string name);
    void info();
    void voice();
};

#endif