#include "plate.h"
#include <math.h>
#include <thread>

Plate::Plate()
{
    volume = 100;
}

Plate::Plate(int volume)
{
    this->volume = volume;
}

int Plate::Eat()
{
    // Используем мутекс для блокировки одновременной еды из тарелки
    // у каждой тарелки - свой мутекс
    mu.lock();
    int foodEated = rand()%10 + 1;

    if (volume >= foodEated)
    {
        volume = volume - foodEated;
    }
    else
    {
        foodEated = volume;
        volume = 0;
    }
    // Время еды - 1 секунда
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mu.unlock();
    return foodEated;
}


