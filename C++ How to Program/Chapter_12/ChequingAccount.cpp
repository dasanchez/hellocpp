// Ex. 12.10: ChequingAccount.cpp

#include "ChequingAccount.h"
using namespace std;

// constructor
ChequingAccount::ChequingAccount(const double startingBalance, const double fee)
    : Account(startingBalance)
{
    transactionFee = fee;
}

void ChequingAccount::credit(const double deposit)
{
    if (getBalance() > (deposit - transactionFee))
    {
        Account::credit(deposit);
        Account::debit(transactionFee);
    }
    else
        cout << "Not enough funds to complete transaction." << endl;
}

bool ChequingAccount::debit(const double withdrawal)
{
    if (Account::debit(withdrawal + transactionFee))
        return true;
    else
    {
        cout << "Not enough funds to complete transaction." << endl;
        return false;
    }
} 

double ChequingAccount::getTransactionFee() const
{
    return transactionFee;
}