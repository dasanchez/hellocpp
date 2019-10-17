// Fig 15.17: Printing a table of ASCII values
// Write a program that uses a for statement to print a table of ASCII
// values for the characters in the ASCII character set from 33 to 126.
// The program should print the  decimal value, octal value, hexadecimal
// value and character value for each character.
// Use the stream manipulator dec, oct, and hex to print the integer
// values.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(4) << "DEC" << setw(4) << "OCT" << setw(4) << "HEX"
        << setw(3) << "C" << endl;
    for (int i=33; i <= 126; ++i)
    {
        cout << dec << setw(4) << i << oct << setw(4) << i 
            << hex << setw(4) << i
            << setw(3) << static_cast<char>(i) << endl;
    }

} // end main
