// Fig 15.20: Demonstrating the flags member function.

#include <iostream>
using namespace std;

int main()
{
    int integerValue = 1000;
    double doubleValue = 0.0947628;

    // display flags value, int and double values (original format)
    cout << "The vlaue of the flags variable is: " << cout.flags()
        << "\nPrint int and  double in original format:\n"
        << integerValue << '\t' << doubleValue << endl << endl;

    // use cout flags function to save orginal format
    ios_base::fmtflags originalFormat = cout.flags();
    cout << showbase << oct << scientific; // change format

    // display flags value, int, and fouble values (new format)
    cout << "The value of the flags variable is: " << cout.flags()
        << "\nPrint int and double in a new format:\n"
        << integerValue << '\t' << doubleValue << endl << endl;
    
    cout.flags(originalFormat); // restore format

    // display flags value, int and double values (original format)
    cout << "The restored value of the flags variable is:"
        << cout.flags()
        << "\nPrint values in original format again:\n"
        << integerValue << '\t' << doubleValue << endl;
} // end main