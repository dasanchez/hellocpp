// Ex 12.10: Account Inheritance Hierarchy
// Create an inheritance hiearchy contaiing base class Account and derived classes
// SavingsAccount and Checking Account that inherit from class Account.
// Account should include one data member of type double to represent the balance,
// and three member functions: credit, debit, and getBalance.
// SavingsAccount should inherit Account, but also include a data member of type double
// indicating the interest rate assigned to the account, and a public member function
// calculateInterest that returrns a double indicating the interest earned.
// CheckingAccount should inherit Account, and include a data member of type double that
// represents thee fee charged per transaction. CheckingAccount should redefine debit and 
// credit so that they subtract the fee from the account balance whenever either
// transaction is performed successfully.

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

using namespace std;

int main()
{
    // instantiate a BasePlusCommissionEmployee object
    SavingsAccount sAccount(1000, 0.02);
    ChequingAccount cAccount(500, 2.5);
    
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // get commission employee data
    cout << "The savings account starting balance is " << sAccount.getBalance() 
    << ", and it has an interest rate of " << sAccount.getInterestRate()*100 << "%" << endl;

    cout << "After one year, it has earned " << sAccount.calculateInterest()
    << " in interest, for a new balance of " << sAccount.getBalance() << endl;

    cout << "The chequing account starting balance is " << cAccount.getBalance() 
    << ", and it has a transaction fee of " << cAccount.getTransactionFee() << endl;

    cAccount.credit(250);
    cout << "After depositing 250, the new balance is " << cAccount.getBalance() << endl;

    cAccount.debit(100);
    cout << "After depositing 100, the new balance is " << cAccount.getBalance() << endl;

    cout << "Now trying to withdraw 1000: ";
    cAccount.debit(1000);

} // end main