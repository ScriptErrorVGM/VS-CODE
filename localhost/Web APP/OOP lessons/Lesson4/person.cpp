#include "person.h"

Person::Person()
{
    name = "NO NAME";
}

Person::Person(std::string name)
{
    this->name = name;
}

void Person::info()
{
    std::cout << "This is person " << name << "\n";
}

