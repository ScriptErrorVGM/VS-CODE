#ifndef HUNGRYPERSON_H
#define HUNGRYPERSON_H
#include "plate.h"
#include <thread>
#include <mutex>

class HungryPerson
{
private:
    int id; // Номер человека (вместо имени)
    std::thread thr; // Поток, в котором человек "ест" из тарелки
    static std::mutex con_mu; // служебный мутекс, для красивого вывода на консоль из разных потоков
    int riceEated;  // сколько риса съел человек
    Plate* p_plate; // Тарелку из которой едим передаём по указателю, так как невозможно скопировать мутекс
    HungryPerson(); // Перемещаем конструктор без параметров в приватную секцию, чтобы было невозможно его вызвать
public:
    HungryPerson(Plate* plate, int id);  // конструктор задаёт номер (имя) человека и из какой тарелки он ест
    void static eat(HungryPerson& person); // Метод потока должен быть статической функцией
    int getRiceEated();
    std::thread* getThreadReference();
};

#endif // HUNGRYPERSON_H
