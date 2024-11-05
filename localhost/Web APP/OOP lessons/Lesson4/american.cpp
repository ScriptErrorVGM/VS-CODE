#include "american.h"

American::American():Person()
{

}

American::American(std::string name):Person(name)
{

}

void American::info()
{
    std::cout << "This is american " << name << "\n";
}

void American::eat()
{
    std::cout << "I eating burger \n";
}

void American::drink()
{
    std::cout << "I drinking cola \n";
}

