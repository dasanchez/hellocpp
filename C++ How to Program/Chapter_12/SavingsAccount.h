// Ex 12.10: SavingsAccount.h
#ifndef SAVINGS_H
#define SAVINGS_H
#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

class SavingsAccount : public Account
{
    public:
    SavingsAccount(const double = 0.0, const double = 0.01);

    double getInterestRate() const;
    double calculateInterest();

    private:
    double interestRate;
}; // end class Account

#endif