/*
* Описать тип - структуру «Человек», хранящую имя, фамилию и год рождения человека.
* Описать функцию, принимающую человека в качестве параметра и «красиво» выводящую
* его на консоль.
* Описать функцию, принимающую в качестве параметров массив из людей и количество
* элементов в нем и возвращающую самого старшего из них.
* Описать перечисление для задания возраста человека: ребенок, подросток, взрослый.
* Описать функцию, принимающую в качестве параметра человека и возвращающую кто он
* по возрасту.
*/

#include <iostream>
#include "person.cpp"
#include "person.h"
#include "ageenum.h"

using namespace std;

int main()
{
    Person h1;
    h1.name = "Ivan";
    h1.sirname = "Petrov";
    h1.year = 2002;
    infoPerson(h1);

    Person parr[3];

    parr[0].name = "Oleg";
    parr[0].sirname = "Popov";
    parr[0].year = 1985;

    parr[1].name = "Alexander";
    parr[1].sirname = "Sidorov";
    parr[1].year = 2005;

    parr[2].name = "Sergey";
    parr[2].sirname = "Ignatyev";
    parr[2].year = 1999;

    h1 = olderPerson(parr, 3);
    infoPerson(h1);

    ageEnum ae1;
    ae1 = agePerson(parr[1]);
    std::cout << ae1 << "\n";


    return 0;
}

