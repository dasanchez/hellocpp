// Fig 15.20: Demonstrating stream manipulators boolalpha and noboolalpha.

#include <iostream>
using namespace std;

int main()
{
    bool booleanValue = true;

    // display default true booleanValue
    cout << "booleanValue is " << booleanValue << endl;

    // display booleanValue after using boolalpha
    cout << "booleanVale (after using boolalpha) is "
        << boolalpha << booleanValue << endl << endl;

    cout << "switch booleanValue and use noboolalpha" << endl;
    booleanValue = false; // change booleanValue
    cout << noboolalpha << endl; // use noboolalpha

    // display default false booleanValue after using noboolalpha
    cout << "booleanValue is " << booleanValue << endl;

    // display booleanValue after using boolalpha again
    cout << "booleanValue (after using boolalpha) is "
        << boolalpha << booleanValue << endl;
} // end main