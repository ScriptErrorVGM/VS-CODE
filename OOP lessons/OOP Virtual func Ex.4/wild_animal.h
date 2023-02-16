#ifndef WILD_ANIMAL_H
#define WILD_ANIMAL_H

#include <iostream>

class Wild_Animal
{
public:
    std::string name;
    Wild_Animal();
    Wild_Animal(std::string name);
    void info();
    virtual void voice() = 0;
};

#endif 