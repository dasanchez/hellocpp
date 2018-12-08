// Fig 9.18: Date.cpp

#include <iostream>
#include "Date.h"
using namespace std;

// Date constructor (should do range checking)
Date::Date(int y, int m, int d)
{
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
} // end  constructor Date

// print Date in the format yyyy/mm/dd
void Date::print()
{
    cout << year << '/' << month << '/' << day;
} // end function print

// increment the date by one day
void Date::nextDay()
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
bool Date::isLeapYear(const int year)
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
int Date::daysInMonth(const int month, const int year)
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