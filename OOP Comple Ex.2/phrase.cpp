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

int Phrase::symbolNumbers()
{
    int result = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            result++;
        }
    }
    return result;
}

int Phrase::isMax()
{
    int result = 0;
    int temp = 0;
    for (int i = 0; i < text.length(); i++)
    {   
        
        if (text[i] != ' ' && ((text[i] >= 'a' && text[i] <= 'z') 
        || (text[i] >= 'A' && text[i] <= 'Z')))
        {
            temp++;
        } 
        else if (temp > result)
        {
            result = temp;
            temp = 0;
        } 
        else 
        {
            temp = 0;
        }
        
    }
    
    if (result < temp)
    {
        result = temp;
    }
    return result;

}

int Phrase::isMin()
{
    int result = 100000;
    int temp = 0;
    for (int i = 0; i < text.length(); i++)
    {   
        
        if (text[i] != ' ' && ((text[i] >= 'a' && text[i] <= 'z') 
        || (text[i] >= 'A' && text[i] <= 'Z')))
        {
            temp++;
        } 
        else if (temp < result && temp != 0)
        {
            result = temp;
            temp = 0;
        } 
        else 
        {
            temp = 0;
        }
        
    }
    
    if (result > temp && temp != 0)
    {
        result = temp;
    }
    return result;

}