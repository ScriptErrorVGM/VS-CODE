#include "truck.h"
#include "terminal.h"
#include <thread>
#include <iostream>

std::mutex Truck::con_mu;

Truck::Truck()
{

}

Truck::Truck(Terminal* t_terminal, int id)
{
     this->t_terminal = t_terminal;
     this->id = id;
     cargoLoaded = 0;
     thr = std::thread(loading, std::ref(*this));
}

int Truck::getCargoLoaded()
{
    return cargoLoaded;
}


void Truck::loading(Truck& vehical)
{
    int itemLoaded = 0;
    srand(vehical.id);
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(rand()%3 + 1));
        // Потом едим
        itemLoaded = vehical.t_terminal->Loading();
        if (itemLoaded == 0) break;
        vehical.cargoLoaded = vehical.cargoLoaded + itemLoaded;


        con_mu.lock();
        std::cout << vehical.id << " truck has loaded " << itemLoaded << " cargos (total : "<< vehical.cargoLoaded << ")\n";
        con_mu.unlock();
    }
}

std::thread* Truck::getThreadReference()
{
    return &thr;
}