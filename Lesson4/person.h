#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    std::string name;
    Person();
    Person(std::string name);
    void info();
    virtual void eat() = 0;
    virtual void drink() = 0;
};

#endif // PERSON_H
