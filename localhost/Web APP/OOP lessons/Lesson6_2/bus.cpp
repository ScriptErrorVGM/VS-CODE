#include "bus.h"

Bus::Bus()
{
    busNumber = "NO NUMBER";
    busModel = "NO MODEL";
}

Bus::Bus(std::string busNumber, std::string busModel)
{
    this->busNumber = busNumber;
    this->busModel = busModel;
}

bool Bus::operator < (Bus b) const
{
    return (busNumber < b.busNumber);
}

void Bus::info() const
{
    std::cout << busModel << ", " << busNumber << "\n";
}

