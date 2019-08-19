// Ex 13.12: Payroll System Modification
// Modify the payroll system to include private data member birthDate in
// class Employee. Use class Date to represent an employee's birthday.
// Assume that payroll is processed once per month.
// Create a vector of Employee references to store the various employee objects.
// In a loop, calculate the payroll for each Employee, and add a $100.00 bonus
// to the person's payroll amount if the current month is the month in which
// the Employee's birthday occurs.

#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main()
{
    vector<Employee *> employees;

    employees.push_back(new SalariedEmployee("John", "Doe", "000-00-0000", 1970, 04, 20, 200));
    employees.push_back(new CommissionEmployee("Susan", "Jones", "111-11-1111", 1982, 8, 2, 1000, 0.03));
    employees.push_back(new BasePlusCommissionEmployee("Duncan", "Rapinoe", "222-22-2222", 1989, 2, 27, 1000, 0.03, 300));

    for (size_t j = 0; j < 12; ++j)
    {

        cout << "For the month of " << Date::spelledMonths[j] << ":\n\n";
        for (size_t i = 0; i < employees.size(); ++i)
        {
            employees[i]->print();
            if (employees[i]->getBirthDate().getMonth() == static_cast<int>(j+1))
            {
                cout << "\nHappy Birthday, " << employees[i]->getFirstName() << "! You get a bonus.";
                cout << "\nThis month you made $" << 2*employees[i]->earnings() + 100 << endl;
            }
            else
            {
                cout << "\nThis month you made $" << 2*employees[i]->earnings() << endl;
            }
            
            cout << "\n";
        }
        cout << "\n";
    }

} // end main