/* Описать класс «Автомобиль». Написать программу моделирования работы гаража.
 * Программа должна обеспечивать начальное формирование данных обо всех автомобилях
 * в гараже в виде списка. Кроме того, программа должна обеспечивать имитацию
 * выезда автомобиля из гаража: вводится номер автомобиля, программа удаляет
 * данные об этом автомобиле из списка автомобилей, находящихся в парке и
 * записывает данные в список автомобилей, находящихся на выезде.
 * Для представления необходимых списков использовать шаблонный класс map.
 */

#include <iostream>
#include "car.h"
#include <map>

using namespace std;

int main()
{
    map<string, Car> inPark;
    map<string, Car> onLine;

    // Добавляем записи в map. Ключом является номер автомобиля, а значением - сам автомобиль
    inPark.insert(pair<string, Car>("T132BA125rus", Car("T132BA125rus", "Toyota")));
    inPark.insert(pair<string, Car>("M282TB125rus", Car("M282TB125rus", "Toyota")));
    inPark.insert(pair<string, Car>("T187MM127rus", Car("T187MM127rus", "Toyota")));
    inPark.insert(pair<string, Car>("B357HA125rus", Car("B357HA125rus", "Toyota")));
    inPark.insert(pair<string, Car>("H132TM127rus", Car("H132TM127rus", "Toyota")));
    inPark.insert(pair<string, Car>("T238HB127rus", Car("T238HB127rus", "Toyota")));
    inPark.insert(pair<string, Car>("H183TB125rus", Car("H183TB125rus", "Toyota")));

    // Просим пользователя ввести номер машины для выхода из парка
    cout << "Input car number to go to line \n";
    std::string carNumber;
    cin >> carNumber;

    // Ищем в парке машину с введённым номером, если он есть включаем его
    // в список машин на линии и удаляем из списка машин в парке
    map<string, Car>::iterator carIterator = inPark.find(carNumber);
    if(carIterator != inPark.end())
    {
        onLine.insert(pair<string, Car>(carIterator->first, carIterator->second));
        inPark.erase(carIterator->first);
    }


    // Выводим на консоль списки машин в парке и на линии
    cout << "----Cars in park----\n";
    for (map<string, Car>::iterator it = inPark.begin(); it != inPark.end(); it++)
    {
        it->second.info();
    }
    cout << "----Cars on line----\n";
    for (map<string, Car>::iterator it = onLine.begin(); it != onLine.end(); it++)
    {
        it->second.info();
    }



    return 0;
}

