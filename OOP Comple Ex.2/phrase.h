#ifndef PHRASE_H
#define PHRASE_H

#include<iostream>

class Phrase 
{
public:
    std::string text;
    Phrase();
    Phrase(std::string text);
    void info();
    int symbolNumbers();
    int isMax();
    int isMin();
};

#endif // PHRASE_H
