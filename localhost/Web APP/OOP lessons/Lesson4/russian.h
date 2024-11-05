#ifndef RUSSIAN_H
#define RUSSIAN_H
#include "person.h"


class Russian : public Person
{
public:
    Russian();
    Russian(std::string name);
    void info();
    void eat();
    void drink();
};

#endif // RUSSIAN_H
