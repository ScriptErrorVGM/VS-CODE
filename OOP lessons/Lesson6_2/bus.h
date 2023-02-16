#ifndef BUS_H
#define BUS_H

#include <iostream>

class Bus
{
    public:
    std::string busNumber;
    std::string busModel;
    Bus();
    Bus(std::string busNumber, std::string busModel);
    bool operator < (Bus b) const;
    void info() const;
};

#endif // BUS_H
