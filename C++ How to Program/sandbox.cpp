/*
 * Ex 9.7: Enhancing class Time.
 * Include a `tick` member function that  increments the time stored
 * in a `Time` object by one second.
 * Write a program that tests the `tick` member function in a loop 
 * that prints the time in standard format during each iteration of the loop.
*/

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time time(23, 58, 15); // set time to 23:40:15
    const int loopCount = 120;
    cout << "Starting time: ";
    time.printUniversal();
    cout  << endl;

    for (int i = 0; i < loopCount; ++i)
    {
        time.tick();
        time.printUniversal();
        cout << endl;
    }
} // end main
