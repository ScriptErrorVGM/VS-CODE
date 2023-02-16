#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include"ageenum.h"

struct Person
{
    std::string name;
    std::string sirname;
    int year;
};

void infoPerson(Person h);
Person olderPerson(Person *parr, int n);
ageEnum agePerson(Person p);

#endif // PERSON_H
