// Ex 12.3: CommmissionEmployeeComposition.cpp
// Class CommissionEmployeeComposition member-function definitions.
#include <iostream>
#include "EmployeeComposition.h" // CommissionEmployee class definition
using namespace std;

// constructor
EmployeeComposition::EmployeeComposition(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
{
    commissionEmployee = CommissionEmployee(first, last, ssn, sales, rate);
    setBaseSalary(salary);
} // end BasePlusCommissionEmployee cconstructor

// set base salary
void EmployeeComposition::setBaseSalary(double salary)
{
    if (salary >= 0.0)
    baseSalary = salary;
    else
    throw  invalid_argument("Salary must be >= 0.0");
} // end function setBaseSalary

// return base salary
double EmployeeComposition::getBaseSalary() const
{
    return baseSalary;
} // end function getBaseSalary

// calculate earnings
double EmployeeComposition::earnings() const
{
    // derived class cannot access the base class's private data
    return baseSalary + commissionEmployee.earnings();
} // ed function earnings

// print  CommissionEmployee object
void EmployeeComposition::print() const
{
    cout << "base-salaried ";
    commissionEmployee.print();
    cout << "\nbase salary: " << getBaseSalary();
} // end function print
