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
{   int arrInt[5] = {10, 5, -3, 8, 15};
    Person arrPerson[5] = {
                              Person("Vasya", 190),
                              Person("Olya", 200),
                              Person("Misha", 201),
                              Person("Dima", 197),
                              Person("Natasha", 199),
                          };
    
    
    int size = 5;
/*
    float result1 = average(arrInt, size,result1);
    cout << result1 << '\n';
    
    
    float stDev1 = standartDeviation(arrInt, size,result1,stDev1);
    cout << "What: " << result1 << '\n';
    cout << "Result " << stDev1 << '\n';
    

*/

    float result2 = average(arrPerson, size,result2);
    cout << result2 << '\n';
    
    
    float stDev2 = standartDeviation(arrPerson, size,result2,stDev2);
    cout << "What: " << result2 << '\n';
    cout << "Result " << stDev2 << '\n';
    
    return 0;
};
