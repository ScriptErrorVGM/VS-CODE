#ifndef TERMINAL_H
#define TERMINAL_H
#include <mutex>

class Terminal
{
private:
    std::mutex mu;
    int volume;
public:
    Terminal();
    Terminal(int volume);
    int Loading();
};

#endif // TERMINAL_H