#ifndef TIGER_H
#define TIGER_H
#include "wild_animal.h"

class Tiger: public Wild_Animal
{
public:
    Tiger();
    Tiger(std::string name);
    void info();
    void voice();
};

#endif