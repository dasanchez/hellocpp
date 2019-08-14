// Ex. 12.10: SavingsAccount.cpp
#include "SavingsAccount.h"
using namespace std;

// constructor
SavingsAccount::SavingsAccount(const double startingBalance, const double rate)
: Account(startingBalance)
{
    interestRate = rate;
}

double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

double SavingsAccount::calculateInterest()
{
    double interest = interestRate * getBalance();
    credit(interest);
    return interest;
}
