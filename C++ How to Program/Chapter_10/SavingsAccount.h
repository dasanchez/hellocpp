// Ex 10.7: SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

using namespace std;

class SavingsAccount
{
  public:
    SavingsAccount(double); // constructor
    
    double getSavingsBalance() const;
    // static member function
    static void setInterestRate(double);
    static double getInterestRate() { return annualInterestRate;};
    double calculateMonthlyInterest() const;
    void advanceMonth();  

  private:
    double savingsBalance;
    
    // static data
    static double annualInterestRate;

}; // end class SavingsAccount

#endif