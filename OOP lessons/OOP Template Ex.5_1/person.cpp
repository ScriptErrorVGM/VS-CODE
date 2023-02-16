#include "person.h"

Person::Person()
{
    name = "NO NAME";
}

Person::Person(std::string name, int height)
{
    this->name = name;
    this->height = height;
}

int Person::operator+(Person p)
{
    return (this->height + p.height);
}

int Person::operator-(Person p)
{
    return (this->height - p.height);
}

/*void Person::info()
{
    std::cout << height << "\n";
}*/
