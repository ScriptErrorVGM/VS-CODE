/*
* Описать класс «фраза», хранящий строку, например, в виде массива символов или
* поля типа string.
* Предусмотреть конструкторы, инициализирующие объект переданной в параметре
* строкой или значением по умолчанию.
* Предусмотреть метод info(), выводящий на экран информацию об объекте.
* Создать следующие методы класса: возвращающий число гласных букв в строке,
* проверяющий, равны ли хранимые в объектах строки (типа isEqual).
*/

#include <iostream>
#include "phrase.cpp"
#include "phrase.h"

using namespace std;

int main()
{
    Phrase ph1;
    Phrase ph2("Hey, hello!");

    ph1.info();
    ph2.info();

    cout << "Vowel numbers in ph2 is " << ph2.vowelNumbers() << "\n";

    Phrase ph3("Hey, hello!");

    cout << ph2.isEqual(ph3) << "\n";
    cout << ph3.isEqual(ph1) << "\n";

    return 0;
}

