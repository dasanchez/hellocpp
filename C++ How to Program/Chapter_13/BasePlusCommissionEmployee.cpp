// Fig 13.16: BasePlusCommmissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include "BasePlusCommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    // explicitly call base-class constructor
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
} // end BasePlusCommissionEmployee cconstructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
} // end function getBaseSalary

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
    // derived class cannot access the base class's private data
    return getBaseSalary() + CommissionEmployee::earnings();
} // ed function earnings

// print  CommissionEmployee object
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print(); // code reuse
    cout << "\nbase salary: " << getBaseSalary();
} // end function print