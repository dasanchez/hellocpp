// Fig 12.10: BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee class derived from class
// CommissionEmployee
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h"
using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &,
                               const string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary

    virtual double earnings() const; //calculate earnings
    virtual void print() const;      // print CommissionEmployee object

private:
    double baseSalary;     // base salary
};                         // end class BasePlusCommissionEmployee

#endif 