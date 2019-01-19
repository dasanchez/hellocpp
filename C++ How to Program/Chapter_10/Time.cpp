/*
 * Fig 9.9: Time.cpp
 * Member-function definitions for class Time.
*/
#include <iostream>
#include <iomanip>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member to zero.
Time::Time(int hour, int minute, int second)
{
    // make seconds out of HMS:
    int secs = second + minute * 60 + hour * 3600;
    if (secs >= 0 && secs < 86400)
    {
        secondsSinceMidnight = secs;
    }
    else
    {
        secondsSinceMidnight = 0;
    }
} // end Time constructor

// increment second by one
void Time::tick()
{
    secondsSinceMidnight++;
    if (secondsSinceMidnight >= 86400)
        secondsSinceMidnight = 0;
}

// return hour value
int Time::getHour() const // get functions should be const
{
    return secondsSinceMidnight / 3600;
} // end function getHour

// return minute value
int Time::getMinute() const
{
    return (secondsSinceMidnight % 3600) / 60;
} // end function getMinute

// return second value
int Time::getSecond() const
{
    return (secondsSinceMidnight % 3600) % 60;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
         << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
         << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
         << getSecond() << (getHour() < 12 ? " AM" : " PM");
} // end function printStandard
