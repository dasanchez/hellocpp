// Fig 13.9: Employee.h
// Employee abstract base class.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // C++ standard string class
using namespace std;

class Employee
{
public:
Employee(const string &, const string &, const string &);
virtual ~Employee();

void setFirstName(const string &); // set first name
string getFirstName() const; // return first name

void setLastName(const string &); // set last name
string getLastName() const; // return last name

void setSocialSecurityNumber( const string &); // set SSN
string getSocialSecurityNumber() const; // return SSN

// pure virtual functons makes Employee an abstract base class
virtual double earnings() const = 0; // pure virtual
virtual void print() const; // virtual

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
}; // end class Employee

#endif // EMPLOYEE_H