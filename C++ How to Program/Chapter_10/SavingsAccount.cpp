// Ex 10.7: SavingsAccount.cpp
#include <iostream>
#include "SavingsAccount.h"
using namespace std;

// define and initialize static data member at global namespace scope
double SavingsAccount::annualInterestRate = 3;

void SavingsAccount::setInterestRate(double newRate)
{
    annualInterestRate = newRate;
}

// constructor initializes non-static data members
SavingsAccount::SavingsAccount(double sb)
: savingsBalance(sb)
{

} // end SavingsBalance constructor

// return savings balance
double SavingsAccount::getSavingsBalance() const
{
    return savingsBalance; // return private data member
}

// return monthly interest
double SavingsAccount::calculateMonthlyInterest() const
{
    return savingsBalance * (annualInterestRate/100)/12;
}

// add current montly interest to savings balance
void SavingsAccount::advanceMonth()
{
    savingsBalance += calculateMonthlyInterest();
}