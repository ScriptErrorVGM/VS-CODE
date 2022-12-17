#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include <iostream>

class BankCustomer
{
    public:
    enum bankPrior {child=2,aged=3,business=4,invalid=1};
    std::string customerName;
    bankPrior customerPrior;
    BankCustomer();
    BankCustomer(std::string customerName, bankPrior customerPrior);
    bool operator < (BankCustomer b) const;
    void info() const;
};



#endif // BANK_CUSTOMER_H