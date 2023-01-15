// Написать программу, позволяющую имитировать работу грузового терминала. Есть
// несколько боксов терминала. В одном боксе терминала может обслуживаться только один
// грузовик. В каждом боксе есть определенное количество грузов, которые необходимо
// вывести. Каждый грузовик за один заход может вывести некоторое количество груза, он
// может совершать несколько рейсов. Программа должна выводить номер грузовика и
// количество единиц груза, вывезенных за каждый рейс. Работа завершается тогда, когда из
// всех боксов терминала вывезены все грузы.

#include <iostream>
#include "truck.h"
#include "terminal.h"
#include "truck.cpp"
#include "terminal.cpp"

using namespace std;

int main()
{
    Terminal terminal1(100); 
    Terminal terminal2(60);

    
    Truck hp1(&terminal1, 1111);
    Truck hp2(&terminal1, 2222);
    Truck hp3(&terminal1, 3333);

    
    Truck hp4(&terminal2, 4444);
    Truck hp5(&terminal2, 5555);


    
    hp1.getThreadReference()->join();
    hp2.getThreadReference()->join();
    hp3.getThreadReference()->join();

    hp4.getThreadReference()->join();
    hp5.getThreadReference()->join();

    cout << "Loading has finished!" << endl;
    return 0;
}
