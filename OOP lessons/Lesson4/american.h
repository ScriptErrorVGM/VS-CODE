#ifndef AMERICAN_H
#define AMERICAN_H
#include "person.h"

class American : public Person
{
public:
    American();
    American(std::string name);
    void info();
    void eat();
    void drink();
};

#endif // AMERICAN_H
