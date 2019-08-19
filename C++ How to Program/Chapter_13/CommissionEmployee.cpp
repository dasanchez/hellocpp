// Fig 13.14: CommmissionEmployee.cpp
// Class CommissionEmployee member-function definitions.
#include <iostream>
#include "CommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(
    const string &first, const string &last, const string &ssn,
    int year, int month, int day, double sales, double rate)
    : Employee(first, last, ssn, year, month, day)
{
    setGrossSales(sales);    // validate and store gross sales
    setCommissionRate(rate); // validate and store commission rate
} // end CommissionEmployee cconstructor

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
} // end function getGrossSales

// set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
} // end funcation setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

// calculate earnings; overrisde pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
} // ed function earnings

// print CommissionEmployee's information
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print(); // code reuse
    cout << "\ngross sales: " << getGrossSales()
         << "; commission rate: " << getCommissionRate();
} // end function print