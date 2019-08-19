// Fig 13.11: SalariedEmployee.h
// SalariedEmployee class derived from Employee.
#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee : public Employee
{
    public:
    SalariedEmployee(const string &, const string &,
    const string &, int, int, int, double = 0.0);
    void setWeeklySalary(double); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print SalariedEmployee object

    private:
    double weeklySalary; //salary per week
}; //end class SalariedEmployee

#endif // SALARIED_H