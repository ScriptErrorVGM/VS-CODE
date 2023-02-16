/*
* Вариант задачи об обедающих философах, где разделяемым ресурсом
* является тарелка. Синхронизация потоков идёт с помощью мутексов.
* В примере создаются две тарелки. Из каждой ест своя группа людей.
*
*/


#include <iostream>
#include "hungryperson.h"
#include "plate.h"
#include "hungryperson.cpp"
#include "plate.cpp"

using namespace std;

int main()
{
    Plate plate1(100); // В конструкторе тарелки указывается ее объём
    Plate plate2(50);

    // В конструктор передаём указатель на тарелку, из которой будет есть человек
    HungryPerson hp1(&plate1, 1);
    HungryPerson hp2(&plate1, 2);
    HungryPerson hp3(&plate1, 3);

    // А эти едят из другой тарелки
    HungryPerson hp4(&plate2, 4);
    HungryPerson hp5(&plate2, 5);


    // Ждём завершения всех потоков
    hp1.getThreadReference()->join();
    hp2.getThreadReference()->join();
    hp3.getThreadReference()->join();

    hp4.getThreadReference()->join();
    hp5.getThreadReference()->join();

    cout << "Dinner has finished!" << endl;
    return 0;
}
