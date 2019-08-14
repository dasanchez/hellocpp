// Ex 12.10: Account class function definitions

#include "Account.h"

using namespace std;

// constructor
Account::Account(double newBalance)
{
    if (newBalance >= 0)
        balance = newBalance;
    else
    {
        cout << "Starting balance is negative, setting to zero." << endl;
        balance = 0.0;
    }
}

void Account::credit(double deposit)
{
    if (deposit > 0)
        balance += deposit;
}

bool Account::debit(double withdrawal)
{
    if (balance >= withdrawal)
    {
        balance -= withdrawal;
        return true;
    }
    else
    {
        return false;
    }
}

double Account::getBalance() const
{
    return balance;
}