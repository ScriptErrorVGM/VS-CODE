#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
public:
    std::string carNumber;
    std::string carModel;
    Car();
    Car(std::string carNumber, std::string carModel);
    bool operator < (Car b) const;
    void info() const;
};

#endif // CAR_H
