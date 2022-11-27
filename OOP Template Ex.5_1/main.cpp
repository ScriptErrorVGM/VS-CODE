/*
Определить шаблоны функций, возвращающих среднее арифметическое и
среднеквадратичное отклонение элементов массива (т.е. два шаблона функций).
Продемонстрировать работу шаблонов на массивах объектов как встроенного типа, так и
собственного класса. Для этого создать собственный класс и перегрузить в нём нужные
функции-операции.
*/

#include <iostream>
#include "mytemplate.h"
#include "person.cpp"
#include "person.h"


using namespace std;
int main()
{
    Person arrPerson[5] = {
                              Person("Vasya", 190),
                              Person("Olya", 200),
                              Person("Misha", 201),
                              Person("Dima", 197),
                              Person("Natasha", 199),
                          };
    
    
    int size = 5;   
    float result2 = average(arrPerson, size,result2);
    cout << result2 << '\n';
    //result2.info();
    
    float stDev2 = standartDeviation(arrPerson, size,result2,stDev2);
    cout << "What: " << result2 << '\n';
    cout << "Result " << stDev2 << '\n';
    //result2.info();
    return 0;
};
