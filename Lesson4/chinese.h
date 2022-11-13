#ifndef CHINESE_H
#define CHINESE_H
#include "person.h"


class Chinese : public Person
{
public:
    Chinese();
    Chinese(std::string name);
    void info();
    void eat();
    void drink();
};

#endif // CHINESE_H
