// Ex 12.3: Composition as an Alternative to Inheritance
// Rewrite class BasePlusCommissionEmployee to use
// composition rather than inheritance.
// Assess the relative merits of the two approaches 
// for designing these classes, as well as for object-
// oriented programs in general. Which approach is more general? Why?

// This example shows how big a difference it can make to assign an 'is-a'
// relationship over a 'has-a' one to two or more classes. Using composition
// to build the class that adds a base salary presents a challenge for 
// integrating the pre-existing functionality of the EmployeeCommission class.
// I had to modify the EmployeeCommission header to add default initialization
// values so I could declare a private EmployeeCommission object within the new
// class.
// Then I had to provide new getter functions so I wouldn't have to declare
// the CommissionEmployee member as public.
// The composition approach is more general, but it requires additional work
// to bring out the access members and functions on the derived class.

#include <iostream>
#include <iomanip>
#include "EmployeeComposition.h" // CommissionEmployee class definition
using namespace std;

int main()
{
    // instantiate a BasePlusCommissionEmployee object
    EmployeeComposition employee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // get commission employee data
    cout << "Employee information obtained by get functions: \n"
    << "\nFirst name is " << employee.getFirstName()
    << "\nLast name is " << employee.getLastName()
    << "\nSocial security number is "
    << employee.getSocialSecurityNumber()
    << "\nGross sales is " << employee.getGrossSales()
    << "\nCommission rate is " << employee.getCommissionRate()
    << "\nBase salary is " << employee.getBaseSalary() << endl;

    employee.setBaseSalary(1000); // set base salary

    cout << "\nUpdated employee information output by print function: \n"
    << endl;
    employee.print(); // display the employee information

    // display the employee's earnings
    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
} // end main