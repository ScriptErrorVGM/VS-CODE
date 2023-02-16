#include "phrase.h"

Phrase::Phrase()
{
    text = "NO PHRASE";
}

Phrase::Phrase(std::string text)
{
    this->text = text;
}

void Phrase::info()
{
    std::cout << text.c_str() << "\n";
}

int Phrase::vowelNumbers()
{
    int result = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == 'a' || text[i] == 'A' ||
            text[i] == 'e' || text[i] == 'E' ||
            text[i] == 'i' || text[i] == 'I' ||
            text[i] == 'o' || text[i] == 'O' ||
            text[i] == 'u' || text[i] == 'U' )
        {
            result++;
        }
    }
    return result;
}

bool Phrase::isEqual(Phrase p)
{
    if (text.length() != p.text.length())
    {
        return false;
    }
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != p.text[i])
        {
            return false;
        }
    }
    return true;
}

