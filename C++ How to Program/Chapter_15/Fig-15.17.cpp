// Fig 15.17: Using stream manipulator showbase.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x = 10;

    // use showbase to show number base
    cout << "Printing integers preceded by their base:" << endl
        << showbase;

    cout << x << endl; // print decimal value
    cout << oct << x << endl; // print octal value
    cout << hex << x << endl; // print hexadecimal value
} // end main