/*
 * Fig 9.9: Time.cpp
 * Member-function definitions for class Time.
*/
#include <iostream>
#include <iomanip>
#include <stdexcept> // for invalid_argument exception class
#include "Time.h"    // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member to zero.
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second); // validate and set time
} // end Time constructor

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
    try
    {
        setHour(h); // set private field hour
    }
    catch (invalid_argument &ex)
    {
        cout << "Invalid hour value, setting to 0..." << endl;
        setHour(0);
    }
    try
    {
        setMinute(m);
    }
    catch (invalid_argument &ex)
    {
        cout << "Invalid minute value, setting to 0..." << endl;
        setMinute(0);
    }
    try
    {
        setSecond(s);
    }
    catch (invalid_argument &ex)
    {
        cout << "Invalid second value, setting to 0..." << endl;
        setSecond(0);
    }
} // end function setTime

// iincrement second by one
void Time::tick()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
}

// set hour value
void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be  0-23");
} // end function setHour

// set minute value
void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
} // end function setMinute

// set second value
void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must  be 0-59");
}

// return hour value
int Time::getHour() const // get functions should be const
{
    return hour;
} // end function getHour

// return minute value
int Time::getMinute() const
{
    return minute;
} // end function getMinute

// return second value
int Time::getSecond() const
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
         << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
         << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
         << getSecond() << (getHour() < 12 ? " AM" : " PM");
} // end function printStandard
