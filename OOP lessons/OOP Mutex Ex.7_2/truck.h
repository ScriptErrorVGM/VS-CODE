#ifndef TRUCK_H
#define TRUCK_H
#include "terminal.h"
#include <thread>
#include <mutex>

class Truck
{
private:
    int id; 
    std::thread thr; 
    static std::mutex con_mu;
    int cargoLoaded;  
    Terminal* t_terminal;
    Truck(); 
public:
    Truck(Terminal* terminal, int id); 
    void static loading(Truck& vehical); 
    int getCargoLoaded();
    std::thread* getThreadReference();
};

#endif // TRUCK_H