#include "person.h"

Person::Person()
{
    name = "NO NAME";
}

Person::Person(std::string name, int birthYear)
{
    this->name = name;
    this->birthYear = birthYear;
}

bool Person::operator<(Person p)
{
    return (this->birthYear < p.birthYear);
}

void Person::info()
{
    std::cout << name << "\t" << birthYear << "\n";
}
