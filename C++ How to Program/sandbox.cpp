/*
 * Ex 9.8: Enhancing class Date.
 * Perform error checking  on the initializer values for data members
 * month, day, and year. Also, provide a member function nextDay to
 * increment the day by one.
 * Write a program that tests the `nextDay` member function in a loop 
 * that prints the date during each iteration of the loop.
*/

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    const int loopCount = 10;
    Date date(2001, 2, 24);
    cout << "Starting date: ";
    date.print();
    cout  << endl;

    for (int i = 0; i < loopCount; ++i)
    {
        date.nextDay();
        date.print();
        cout << endl;
    }
} // end main
