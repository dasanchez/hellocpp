/*
10.7 SavingsAccount Class
Create a SavingsAccount class.
Use a static data member anualInterestRate to store the annual
interest rate for each of the savers.
Each member of the class contains a private data member savingsBalance
indicating the amount the saver currently has on deposit.
Provide member function calculateMonthlyInterest that calculates the
monthly interest by multiplying the balance by annualInterestRate
divided by 12; this interest should be added to savingsBalance.
Provide a static member function modifyInterestRate that sets the static
annualInterestRate to a new value.
Write a driver program to test class SavingsAccount:
Instantiate two different objects  of class SavingsAccount, saver1 and saver2,
with balances  of $2000.00 and $3000.00, respectively.
Set the annualInterestRate to 3 percent. Then calculate the monthly interest and
print the new balances for each of the savers.
Then set the annualInterestRate to 4 percent, calculate the next month's interest
and print the new balances for each of the savers.
*/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

int main()
{
     // instantiate saver1 and saver2
     SavingsAccount saver1(2000);
     SavingsAccount saver2(3000);

     cout << "saver1 starting balance: " << setprecision(2) << fixed << saver1.getSavingsBalance() << endl;
     cout << "saver2 starting balance: " << setprecision(2) << fixed << saver2.getSavingsBalance() << endl;     
     cout << "Annual interest rate: " << setprecision(2) << fixed << saver1.getInterestRate() << endl;

     cout << "saver1 monthly interest rate: " << setprecision(2) << fixed << saver1.calculateMonthlyInterest() << endl;
     cout << "saver2 monthly interest rate: " << setprecision(2) << fixed << saver2.calculateMonthlyInterest() << endl;

     saver1.advanceMonth();
     saver2.advanceMonth();
     cout << "saver1 new balance: " << setprecision(2) << fixed << saver1.getSavingsBalance() << endl;
     cout << "saver2 new balance: " << setprecision(2) << fixed << saver2.getSavingsBalance() << endl;

     saver1.setInterestRate(4);
     cout << "New interest rate: " << setprecision(2) << fixed << saver2.getInterestRate() << endl;

     cout << "saver1 monthly interest rate: " << setprecision(2) << fixed << saver1.calculateMonthlyInterest() << endl;
     cout << "saver2 monthly interest rate: " << setprecision(2) << fixed << saver2.calculateMonthlyInterest() << endl;

     saver1.advanceMonth();
     saver2.advanceMonth();
     cout << "saver1 new balance: " << setprecision(2) << fixed << saver1.getSavingsBalance() << endl;
     cout << "saver2 new balance: " << setprecision(2) << fixed << saver2.getSavingsBalance() << endl;

} // end main