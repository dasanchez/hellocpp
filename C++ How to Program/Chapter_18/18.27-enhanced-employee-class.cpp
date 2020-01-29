// Ex. 18.27: Enhanced Emplyee Class
// Modify class Employee in Fgs. 13.2-13.3 by adding a private
// utility function called isValidSocialSecuurityNumber. This member
// function should validate the format of a social security number
// (e.g., ###-##-####, where # is a digit). If the format is valid,
// return true; otherwise return false.

#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    Employee validWorker("Sue", "Jones", "222-22-2222", 1982, 10, 22);
    // Employee invalidWorker("Peter", "Sleaze", "123-45-678", 1970, 1, 1); // no good
    // Employee invalidWorker("Peter", "Sleaze", "123 45 6789", 1970, 1, 1); // no good
    Employee invalidWorker("Peter", "Sleaze", "12E-45-6789", 1970, 1, 1); // no good
    validWorker.print();

    cout << validWorker.getFirstName() << "'s SSN is valid: "
         << boolalpha << validWorker.isValidSocialSecurityNumber() << "\n\n";

    invalidWorker.print();
    cout << invalidWorker.getFirstName() << "'s SSN is valid: "
         << boolalpha << invalidWorker.isValidSocialSecurityNumber() << endl;
}