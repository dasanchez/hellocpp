/*
 * Ex 9.10: Returning Error Indicators from 
 * Class Time's set functions.
 * Return appropriate  error values if an attempt
 * is made to set a data member of an object of
 * class Time to an invalid date.
 * Write a  program that tests your new version of
 * class Time. Display error messages when set functions
 * return error values.
*/

#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    int newHour = 25;
    int newMinute = 61;
    int newSecond = 200;
    Time time; 
    cout << "Setting the time to " << newHour << ":" << newMinute << ":"
         << newSecond << endl;
    time.setTime(newHour, newMinute, newSecond);
    cout << "The time was set to ";
    time.printUniversal();
    cout  << endl;
} // end main
