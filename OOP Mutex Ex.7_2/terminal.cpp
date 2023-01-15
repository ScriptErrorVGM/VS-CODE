#include "terminal.h"
#include <math.h>
#include <thread>

Terminal::Terminal()
{
    volume = 100;
}

Terminal::Terminal(int volume)
{
    this->volume = volume;
}

int Terminal::Loading()
{
    mu.lock();
    int cargoLoaded = rand()%10 + 1;

    if (volume >= cargoLoaded)
    {
        volume = volume - cargoLoaded;
    }
    else
    {
        cargoLoaded = volume;
        volume = 0;
    }
    // Время еды - 1 секунда
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mu.unlock();
    return cargoLoaded;
}
