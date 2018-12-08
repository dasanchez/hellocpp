/*
 * Ex 9.9: Combining Class Time and Class Date.
 * Combine the Time and Date classes into one called DateAndTime.
 * Modify the tick function to call the nextDay function if the time
 * increments into the next day.
 * Modify functions printStandard and printUniversal to output the
 * date and time. 
 * Write a program to test the new class DateAndTime.
*/

#include <iostream>
#include "DateAndTime.h"
using namespace std;

int main()
{
    const int loopCount = 10;
    DateAndTime dt(1999, 12, 31, 23, 59, 52);
    cout << "Starting date and time: ";
    dt.printStandard();
    cout << " | ";
    dt.printUniversal();
    cout  << endl;

    for (int i = 0; i < loopCount; ++i)
    {
        dt.tick();
        dt.printUniversal();
        cout << endl;
    }
} // end main
