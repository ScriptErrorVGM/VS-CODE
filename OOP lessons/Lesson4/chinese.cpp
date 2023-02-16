#include "chinese.h"

Chinese::Chinese():Person()
{

}

Chinese::Chinese(std::string name):Person(name)
{

}

void Chinese::info()
{
    std::cout << "This is chinese " << name << "\n";
}

void Chinese::eat()
{
    std::cout << "I eating rice \n";
}

void Chinese::drink()
{
    std::cout << "I drinking tea \n";
}
