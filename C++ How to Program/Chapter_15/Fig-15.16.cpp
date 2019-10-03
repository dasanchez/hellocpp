// Fig 15.16: Using member function fill and stream manipulator setfill to chnage
// the padding character for fields larger than the printed value.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x = 10000;

    // display x
    cout << x << " printed as int right and left justified\n"
        << "and as hex with internal justification.\n"
        << "Using the default pad character (space):" << endl;
    
    // display x with base
    cout << showbase << setw(10) << x << endl;

    // display x with left justification
    cout << left << setw(10) << x << endl;

    // display x as hex with internal justification
    cout << internal << setw(10) << hex << x << endl << endl;

    cout << "Using various padding characters:" << endl;

    // display x using padded characters (right justification)
    cout << right;
    cout.fill('*');
    cout << setw(10) << dec << x << endl;

    // display x using padded characters (left justification)
    cout << left << setw(10) << setfill('%') << x << endl;

    // display x using padded characters (internal justification)
    cout << internal << setw(10) << setfill('^') << hex
        << x << endl;
} // end main