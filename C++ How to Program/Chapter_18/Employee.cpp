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

// print Employee's information
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\nbirth date: " << getBirthDate() << endl;
} // end function print

// validates SSN
bool Employee::isValidSocialSecurityNumber() const
{
    int digitLocations[9] = {0, 1, 2, 4, 5, 7, 8, 9, 10};
    
    // check that the string is exactly 11 characters long
    if (socialSecurityNumber.length() != 11)
        return false;

    // check that there are dashes at locations 3 and 6:
    if ((socialSecurityNumber.at(3) != '-') || (socialSecurityNumber.at(6) != '-'))
        return false;

    // check that all other locations are between 0 and 9:
    for (int i=0; i < 9; ++i)
    {
        if (! (socialSecurityNumber.at(digitLocations[i]) >= '0' && 
        socialSecurityNumber.at(digitLocations[i]) <= '9'))
            return false;
    }

    return true;

}