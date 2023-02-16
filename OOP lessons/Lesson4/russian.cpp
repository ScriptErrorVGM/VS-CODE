#include "russian.h"

Russian::Russian():Person()
{

}

Russian::Russian(std::string name):Person(name)
{

}

void Russian::info()
{
    std::cout << "This is russian " << name << "\n";
}

void Russian::eat()
{
    std::cout << "I eating borshch \n";
}

void Russian::drink()
{
    std::cout << "I drinking kvas \n";
}
