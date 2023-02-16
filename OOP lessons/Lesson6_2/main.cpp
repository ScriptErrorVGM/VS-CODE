/* 
Описать класс «Автобус». Написать программу моделирования работы автобусного парка.
Программа должна обеспечивать начальное формирование данных о всех автобусах в парке в виде списка.
Кроме того, программа должна обеспечивать имитацию выезда автобуса из парка: вводится номер автобуса,
программа удаляет данные об этом автобусе из списка автобусов, находящихся в парке и записывает данные
в список автобусов, находящихся на маршруте. Для представления необходимых списков использовать
шаблонный класс set.
*/

#include<iostream>
#include"bus.h"
#include<set>

using namespace std;

int main()
{
    set<Bus> inPark;
    set<Bus> onLine;

    inPark.insert(Bus("T132BA125rus", "Toyota"));
    inPark.insert(Bus("T238HB127rus", "Toyota"));
    inPark.insert(Bus("M282TB125rus", "Nissan"));
    inPark.insert(Bus("T187MM127rus", "Nissan"));
    inPark.insert(Bus("B357HA125rus", "Icarus"));
    inPark.insert(Bus("H132TM127rus", "Icarus"));

    // Просим пользователя ввести номер автобуса для выхода из парка
    cout << "Input bus number to go to line \n";
    std::string busNumber;
    cin >> busNumber;

    // Ищем в парке автобус с введённым номером, если он есть включаем его
    // в список автобусов на линии
    for (set<Bus>::iterator it = inPark.begin(); it != inPark.end(); it++)
    {
       if (it->busNumber == busNumber)
       {
            onLine.insert(*it);
       }
    }
    // Удаляем из автобусов в парке все, находящиеся на линии
    for (set<Bus>::iterator it = onLine.begin(); it != onLine.end(); it++)
    {
        inPark.erase(*it);
    }

    // Выводим на консоль списки автобусов в парке и на линии
    cout << "----Buses in park----\n";
    for (set<Bus>::iterator it = inPark.begin(); it != inPark.end(); it++)
    {
        it->info();
    }
    cout << "----Buses on line----\n";
    for (set<Bus>::iterator it = onLine.begin(); it != onLine.end(); it++)
    {
        it->info();
    }

    return 0;
}
