#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person
{
public:
    std::string name;
    int height;
    Person();
    Person(std::string name, int height);
    int operator+(Person p);
    int operator-(Person p);
    /*void info();*/
};

#endif // PERSON_H