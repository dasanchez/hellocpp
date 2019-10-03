// Fig 15.15: Printing an integer with internal spacing and plus sign.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // display value with internal spacing and plus sign
    cout << internal << showpos << setw(10) << 123 << endl;
} // end main