// Fig 13.9: Employee.h
// Employee abstract base class.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // C++ standard string class
#include "Date.h"
using namespace std;

class Employee
{
public:
    Employee(const string &, const string &, const string &,
             int, int, int);

    void setFirstName(const string &); // set first name
    string getFirstName() const;       // return first name

    void setLastName(const string &); // set last name
    string getLastName() const;       // return last name

    void setSocialSecurityNumber(const string &); // set SSN
    string getSocialSecurityNumber() const;       // return SSN

    void setBirthDate(int, int, int); // set birthDate
    Date getBirthDate() const;

    bool isValidSocialSecurityNumber() const; // validate SSN

    void print() const;

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    Date birthDate;
}; // end class Employee

#endif // EMPLOYEE_H