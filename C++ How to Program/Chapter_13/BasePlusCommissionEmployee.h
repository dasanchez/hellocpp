// Fig 13.15: BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee class derived from CommissionEmployee
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &,
                               const string &, int, int, int,
                               double grossSales = 0.0, double commissionRate = 0.0, double baseSalary = 0.0);

    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary

    // keyword virtual signals intent to override
    virtual double earnings() const; //calculate earnings
    virtual void print() const;      // print BasePlusCommissionEmployee object

private:
    double baseSalary; // base salary per week
};                     // end class BasePlusCommissionEmployee

#endif // BASEPLUS_H