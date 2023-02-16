#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "wild_animal.h"

class Elephant: public Wild_Animal
{
public:
    Elephant();
    Elephant(std::string name);
    void info();
    void voice();
};

#endif