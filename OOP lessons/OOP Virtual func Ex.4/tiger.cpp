#include "tiger.h"

Tiger::Tiger():Wild_Animal()
{

}

Tiger::Tiger(std::string name):Wild_Animal(name)
{

}

void Tiger::info()
{
    std::cout << "This is tiger " << name << "\n";
}

void Tiger::voice()
{
    std::cout << "grrrrr raaaaa \n";
}