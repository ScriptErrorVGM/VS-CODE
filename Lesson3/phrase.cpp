#include "phrase.h"

Phrase::Phrase()
{
    text = "NO PHRASE";
}

Phrase::Phrase(std::string text)
{
    this->text = text;
}

Phrase::Phrase(char* text)
{
    this->text += text;
}

void Phrase::info()
{
    std::cout << text.c_str() << "\n";
}

Phrase::operator int()
{
    return text.length();
}

Phrase::operator std::string()
{
    return text;
}


