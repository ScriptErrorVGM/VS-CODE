#include "person.h"

void infoPerson(Person h)
{
    std::cout << h.name << ", " << h.sirname << ", " << h.year << "\n";
}


Person olderPerson(Person *parr, int n)
{
    Person result = parr[0];
    for(int i = 1; i < n; i++)
    {
        if (result.year > parr[i].year)
        {
            result = parr[i];
        }
    }
    return result;
}

ageEnum agePerson(Person p)
{
    int currYear = 2021;
    ageEnum result;

    if (currYear - p.year < 12)
    {
        result = CHILD;
    }
    else if (currYear - p.year < 18)
    {
        result = TEEN;
    }
    else
    {
        result = ADULT;
    }
    return result;
}
