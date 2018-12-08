// Ex 9.9: DateAndTime.cpp

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DateAndTime.h"
using namespace std;

// Date constructor (should do range checking)
DateAndTime::DateAndTime(int y, int m, int d,
                         int hh, int mm, int ss)
{

    // do date first:
    if (y > 1)
        year = y;
    else
        year = 1;

    if (m >= 1 && m <= 12)
        month = m;
    else
        month = 1;

    if (d >= 1 && d <= daysInMonth(month, year))
        day = d;
    else
        day = 1;

    // do time next:
    setTime(hh, mm, ss);
} // end  constructor Date

// increment the date by one day
void DateAndTime::nextDay()
{
    day += 1;
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;
        if (month>12)
        {
            month = 1;
            year++;
        }
    }
}

// checks if the year in the argument is a leap one
bool DateAndTime::isLeapYear(const int year)
{
    if (year % 4 != 0) // common year
        return false;
    else if (year % 100 != 0) // leap year
        return true;
    else if (year % 400 != 0) // common year
        return false;
    else // leap year
        return true;
}

// returns the number of days  given the month and year
int DateAndTime::daysInMonth(const int month, const int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (isLeapYear(year))
            return 29;
        else
            return 28;
        break;
    default:
        return 28;
        break;
    }
}

// set new Time value using universal time
void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);   // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private  field second
} // end function setTime

// set hour value
void DateAndTime::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be  0-23");
} // end function setHour

// set minute value
void DateAndTime::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
} // end function setMinute

// set second value
void DateAndTime::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must  be 0-59");
}

// return hour value
int DateAndTime::getHour()
{
    return hour;
} // end function getHour

// return minute value
int DateAndTime::getMinute()
{
    return minute;
} // end function getMinute

// return second value
int DateAndTime::getSecond()
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void DateAndTime::printUniversal()
{
    cout << setfill('0') << setw(4) << year << '/' << setw(2) << month 
         << '/' << setw(2) << day << ' ';
    cout << setfill('0') << setw(2) << getHour() << ":"
         << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void DateAndTime::printStandard()
{
    cout << setfill('0') << setw(4) << year << '/' << setw(2) << month 
         << '/' << setw(2) << day << ' ';
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
         << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
         << getSecond() << (getHour() < 12 ? " AM" : " PM");
} // end function printStandard

// iincrement second by one
void DateAndTime::tick()
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
                nextDay();
            }
        }
    }
}