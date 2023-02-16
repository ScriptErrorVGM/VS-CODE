#ifndef PHRASE_H
#define PHRASE_H

#include<iostream>

class Phrase
{
public:
    std::string text;
    Phrase();
    Phrase(std::string text);
    Phrase(char* text);
    void info();
    operator int();
    operator std::string();
};

#endif // PHRASE_H
