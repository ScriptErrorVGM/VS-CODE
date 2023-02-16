/*
Определить шаблоны функций, осуществляющих сортировку элементов массива по возрастанию и 
по убыванию (то есть два шаблона функций). Продемонстрировать работу шаблонов на массивах 
объектов как встроенного типа, так и собственного класса. 
Для этого создать собственный класс и перегрузить в нём нужные функции-операции.
*/

#include <iostream>
#include "mytemplates.h"
#include "person.cpp"
#include "person.h"

using namespace std;

int main()
{
    int arrInt[5] = {10, 5, -3, 8, 15};
    Person arrPerson[5] = {
                              Person("Vasya", 1986),
                              Person("Olya", 2003),
                              Person("Misha", 2012),
                              Person("Dima", 1970),
                              Person("Natasha", 1994),
                          };
    int size = 5;

    sortUp(arrInt, size);
    for(int i = 0; i < size-1; i++)
    {
        cout << arrInt[i] << ", ";
    }
    cout << arrInt[size-1] << "\n";

    sortDown(arrInt, size);
    for(int i = 0; i < size-1; i++)
    {
        cout << arrInt[i] << ", ";
    }
    cout << arrInt[size-1] << "\n";
    cout << "\n";

    sortUp(arrPerson, size);
    for(int i = 0; i < size; i++)
    {
        arrPerson[i].info();
    }
    cout << "\n";

    sortDown(arrPerson, size);
    for(int i = 0; i < size; i++)
    {
        arrPerson[i].info();
    }
    cout << "\n";



    return 0;
}

