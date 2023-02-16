#include "wolf.h"

Wolf::Wolf():Wild_Animal()
{

}

Wolf::Wolf(std::string name):Wild_Animal(name)
{

}

void Wolf::info()
{
    std::cout << "This is wolf " << name << "\n";
}

void Wolf::voice()
{
    std::cout << "owooooooooo \n";
}