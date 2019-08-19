// Fig 13.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions
#include <iostream>
#include "SalariedEmployee.h"
using namespace std;

// constructor
SalariedEmployee::SalariedEmployee(const string &first,
                                   const string &last, const string &ssn, 
                                   int year, int month, int day, double salary)
    : Employee(first, last, ssn, year, month, day)
{
    setWeeklySalary(salary);
} // end SalariedEmploee constructor

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
    if (salary >= 0.0)
        weeklySalary = salary;
    else
        throw invalid_argument("Weeekly salary must be >= 0.0");
} // end fuction setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
} // end function getWeeklySalary

// calculate earnings:
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
} // end function earnings

// print SalariedEmployee's information
void SalariedEmployee::print() const
{
    cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    cout << "\nweekly salary: " << getWeeklySalary();
} // end function print