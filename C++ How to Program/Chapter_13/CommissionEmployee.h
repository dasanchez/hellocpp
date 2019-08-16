// Fig 13.13: CommissionEmployee.h
// CommissionEmployee class derived from Employee.
#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const string & = "", const string & = "", const string & = "",
                       double = 0.0, double = 0.01);

    void setCommissionRate(double);   // set commission rate (percentage)
    double getCommissionRate() const; // return commission rate

    void setGrossSales(double); // set gross saales amount
    double getGrossSales() const; // return gross sales amount 

    // keyword virtual signals intent to override
    virtual double earnings() const; //calculate earnings
    virtual void print() const;      // print CommissionEmployee object

protected:
    double grossSales;     // gross weekly sales
    double commissionRate; // commission percentage
};                         // end class Commission Employee

#endif