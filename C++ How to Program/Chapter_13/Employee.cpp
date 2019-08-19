// Fig 13.10: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee.h"
using namespace std;

// constructor
Employee::Employee(const string &first, const string &last,
                   const string &ssn, int year, int month, int day)
    : firstName(first), lastName(last), socialSecurityNumber(ssn),
      birthDate(year, month, day)
{
    // empty body
} // end Employee constructor

Employee::~Employee()
{
    // empty body
}

// set first name
void Employee::setFirstName(const string &first)
{
    firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
    return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName(const string &last)
{
    lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
    return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

void Employee::setBirthDate(int mo, int dy, int yr)
{
    birthDate = Date(yr, mo, dy);
}

Date Employee::getBirthDate() const
{
    return birthDate;
}

// print Employee's information(virtual, but not pure virtual)
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\nbirth date: " << getBirthDate();
} // end function print