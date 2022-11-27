/*
Описать шаблон класса для хранения данных. Данные должны храниться, например, в
виде массива. Шаблон должен включать в себя функции добавления данных, удаления
данных, вывода данных на консоль ( info() ). При этом добавление данных должно
осуществляться так, чтобы каждый элемент встречался не более двух раз (то есть не
добавлять данное, если оно уже дважды есть в массиве). Предусмотреть обработку
следующих исключений: добавление данных в заполненный массив, удаление данных из
пустого массива, добавление в массив дважды существующего элемента.
Продемонстрировать работу шаблона на объектах как встроенного типа, так и
собственного класса. Для этого создать собственный класс и перегрузить в нём нужные
функции-операции.
*/

#include <iostream>
#include "mytemplates.h"
#include "person.h"
#include "person.cpp"

using namespace std;

int main()
{
    Container<int> contInt;

    contInt.add(10);
    contInt.add(3);
    contInt.add(8);
    contInt.add(1);
    contInt.add(5);
    contInt.add(2);
    contInt.add(7);
    contInt.info();

    contInt.del();
    contInt.del();
    contInt.del();
    contInt.del();
    contInt.del();
    contInt.info();

    contInt.del();
    contInt.info();

    contInt.del();
    contInt.info();


    Container<Person> contPerson;

    contPerson.add(Person("Ivan", 1984));
    contPerson.add(Person("Petr", 1988));
    contPerson.add(Person("Natasha", 2014));
    contPerson.add(Person("Olga", 2010));
    contPerson.add(Person("Vasily", 2001));
    contPerson.add(Person("Timofey", 1999));
    contPerson.add(Person("Kostya", 2005));
    contPerson.info();

    contPerson.del();
    contPerson.del();
    contPerson.info();

    // Тестируем исключения
    try
    {
        contInt.add(8);
        contInt.add(1);
        contInt.add(5);
        contInt.add(2);
        contInt.add(7);
        contInt.add(25);
    }
    catch (Full)
    {
        std::cout << "Contaner is full!" << "\n";
    }

    try
    {
        Container<float> contFloat;
        contFloat.add(0.5);
        contFloat.del();
        contFloat.del();
    }
    catch (Empty)
    {
        std::cout << "Contaner is empty!" << "\n";
    }

    try
    {
        Container<float> contFloat;
        contFloat.add(0.5);
        contFloat.add(0.5);
        contFloat.add(0.5);
    }
    catch (DoubleNum)
    {
        std::cout << "Identical elements found, limits two identical elements!" << "\n";
    }

    return 0;
}