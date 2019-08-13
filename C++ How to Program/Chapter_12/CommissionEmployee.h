// Fig 12.12: CommissionEmployee.h
// CommissionEmployee class with protected data.
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ standard string class
using namespace std;

class CommissionEmployee
{
public:
CommissionEmployee(const string &, const string &, const string &,
    double = 0.0, double = 0.0);

void setFirstName(const string &); // set first name
string getFirstName() const; // return first name

void setLastName(const string &); // set last name
string getLastName() const; // return last name

void setSocialSecurityNumber( const string &); // set SSN
string getSocialSecurityNumber() const; // return SSN

void setGrossSales(double); // set gross sales amount
double getGrossSales() const; // return gross sales amount

void setCommissionRate(double); // set commission rate (percentage)
double getCommissionRate() const; // return commission rate

double earnings() const; //calculate earnings
void print() const; // print CommissionEmployee object

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
}; // end class Commission Employee

#endif