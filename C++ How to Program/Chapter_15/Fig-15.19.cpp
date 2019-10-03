// Fig 15.19: Stream manipulator uppercase.

#include <iostream>
using namespace std;

int main()
{
    cout << "Printing uppercase letters in scientific" << endl
        << "notation exponents and hexadecimal values:" << endl;

    // use std::uppercase to display uppercase letters; use std::hex and
    // std::showbase to display hexadecimal value and its base
    cout << uppercase << 4.345e10 <<endl
        << hex << showbase << 123456789 << endl;
} // end main