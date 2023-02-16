#include "car.h"

Car::Car()
{
    carNumber = "NO NUMBER";
    carModel = "NO MODEL";
}

Car::Car(std::string carNumber, std::string carModel)
{
    this->carNumber = carNumber;
    this->carModel = carModel;
}

bool Car::operator < (Car c) const
{
    return (carNumber < c.carNumber);
}

void Car::info() const
{
    std::cout << carModel << ", " << carNumber << "\n";
}
