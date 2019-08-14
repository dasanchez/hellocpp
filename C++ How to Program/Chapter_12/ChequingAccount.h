// Ex 12.10: ChequingAccount.h
#ifndef CHEQUING_H
#define CHEQUING_H
#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

class ChequingAccount : public Account
{
    public:
    ChequingAccount(const double = 0.0, const double = 1.0);

    void credit(const double);
    bool debit(const double);
    double getTransactionFee() const;

    private:
    double transactionFee;
}; // end class Account

#endif