// Fig 15.8: Using stream manipulators hex, oct, dec and setbase.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number;
    cout << "Enter a decimal number: ";
    cin >> number; // input number

    // use hex stream manipulator to show hexadecimal number
    cout << number << " in hexadecimal is: " << hex << number << endl;

    // use oct stream manipulator to show octal number
    cout << dec << number << " in octal is: " << oct << number << endl;

    // use setbase stream manipulator to show decimal number
    cout << setbase(10) << number << " in decimal is: " << number << endl;
} // end main