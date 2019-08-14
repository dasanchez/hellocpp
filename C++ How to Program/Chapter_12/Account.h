// Ex 12.10: Account class declaration
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
    public:
    Account(const double = 0.0);

    void credit(const double);
    bool debit(const double);
    double getBalance() const;

    private:
    double balance;
}; // end class Account

#endif