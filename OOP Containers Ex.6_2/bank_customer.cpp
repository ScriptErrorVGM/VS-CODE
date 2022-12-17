#include "bank_customer.h"

BankCustomer::BankCustomer()
{
    customerName = "NO NAME";
    //customerPrior = "NO PRIOR";
}

BankCustomer::BankCustomer(std::string customerName, bankPrior customerPrior)
{
    this->customerName = customerName;
    this->customerPrior = customerPrior;
}

bool BankCustomer::operator < (BankCustomer b) const
{
    return (customerPrior < b.customerPrior);
}

void BankCustomer::info() const
{
    std::cout << customerPrior << "| " << customerName << "\n";
}

