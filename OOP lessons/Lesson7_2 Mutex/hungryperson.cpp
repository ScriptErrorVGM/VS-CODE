#include "hungryperson.h"
#include "plate.h"
#include <thread>
#include <iostream>

std::mutex HungryPerson::con_mu;

HungryPerson::HungryPerson()
{

}

HungryPerson::HungryPerson(Plate* p_plate, int id)
{
     this->p_plate = p_plate;
     this->id = id;
     riceEated = 0;
     // Как только человек создан - он начинает есть
     thr = std::thread(eat, std::ref(*this));
}

int HungryPerson::getRiceEated()
{
    return riceEated;
}

void HungryPerson::eat(HungryPerson& person)
{
    int itemEated = 0;
    srand(person.id);
    while(1)
    {
        // Сначала подождём случайное время (1-3 сек)
        std::this_thread::sleep_for(std::chrono::seconds(rand()%3 + 1));
        // Потом едим
        itemEated = person.p_plate->Eat();
        if (itemEated == 0) break;
        person.riceEated = person.riceEated + itemEated;

        // Для красивого вывода данных тоже используем мутекс
        // Разные потоки не будут выводить на консоль одновременно
        con_mu.lock();
        std::cout << person.id << " person has eated " << itemEated << " rices ("<< person.riceEated << " all)\n";
        con_mu.unlock();
    }
}

std::thread* HungryPerson::getThreadReference()
{
    return &thr;
}
