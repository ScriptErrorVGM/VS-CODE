/*
    Описать класс «фраза», хранящий строку, например, в виде массива символов или поля
    типа string.
    Предусмотреть конструкторы, инициализирующие объект переданной в параметре
    строкой или значением по умолчанию.
    Предусмотреть метод info(), выводящий на экран информацию об объекте.
    Создать следующие методы класса: возвращающий число символов в строке, самое
    длинное слово и самое короткое слово.
*/

#include <iostream>
#include "phrase.cpp"
#include "phrase.h"

using namespace std;

int main()
{   
    Phrase ph1;
    Phrase ph2("Hey, hello there!");

    ph1.info();
    ph2.info();

    cout << "Number of symbols in ph2 is " << ph2.symbolNumbers() << endl;

    cout << "Max word in ph2 is " << ph2.isMax() << endl;
    cout << "Min word in ph2 is " << ph2.isMin() << endl;





    return 0;
}