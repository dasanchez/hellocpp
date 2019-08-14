// Ex 12.3: CommissionEmployeeComposition.h
// CommissionEmployeeComposition class derived from class
// CommissionEmployee
#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h"
using namespace std;

class EmployeeComposition
{
public:
    EmployeeComposition(const string &, const string &,
                        const string &, double = 0.0, double = 0.0, double = 0.0);

    string getFirstName() const
    {
        return commissionEmployee.getFirstName();
    };

    string getLastName() const
    {
        return commissionEmployee.getLastName();
    };

    string getSocialSecurityNumber() const
    {
        return commissionEmployee.getSocialSecurityNumber();
    };

    double getGrossSales() const
    {
        return commissionEmployee.getGrossSales();
    };

    double getCommissionRate() const
    {
        return commissionEmployee.getCommissionRate();
    };

    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary

    double earnings() const; //calculate earnings
    void print() const;      // print CommissionEmployee object

private:
    double baseSalary; // base salary
    CommissionEmployee commissionEmployee;

}; // end class BasePlusCommissionEmployee

#endif 