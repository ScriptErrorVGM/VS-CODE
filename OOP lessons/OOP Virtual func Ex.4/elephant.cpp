#include "elephant.h"

Elephant::Elephant():Wild_Animal()
{

}

Elephant::Elephant(std::string name):Wild_Animal(name)
{

}

void Elephant::info()
{
    std::cout << "This is elephant " << name << "\n";
}

void Elephant::voice()
{
    std::cout << "pawooooo \n";
}