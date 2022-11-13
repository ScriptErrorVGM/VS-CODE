#include "wild_animal.h"

Wild_Animal::Wild_Animal()
{
    name = "NO NAME";
}

Wild_Animal::Wild_Animal(std::string name)
{
    this->name = name;
}

void Wild_Animal::info()
{
    std::cout << "This wild animal nickname " << name << "\n";
}