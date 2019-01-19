// Fig 10.9: Date.cpp

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <ctime>
#include "Date.h"
using namespace std;

string Date::spelledMonths[12] = {"January", "February", "March", "April",
                                  "May", "June", "July", "August",
                                  "September", "October", "November", "December"};

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int yr, int mn, int dy)
{
    if (mn > 0 && mn <= monthsPerYear) // validate the month
        month = mn;
    else
        throw invalid_argument("month must be 1-12");

    year = yr;          // could validate yr
    day = checkDay(dy); // validate the day

    // output Date object  to show when its constructor is called
    cout << "Date object constructor for date ";
    print();
    cout << endl;
} // end Date constructor

// constructor for DDD YYYY format
Date::Date(int dy, int yr)
{
    year = yr;
    int newDay = dy;
    // extract day and month
    int monthCount = 1;
    int dim = 31;
    day = 0;
    while (newDay > dim)
    {
        cout << "daysInMonth: " << dim << ", newDay: " << newDay << ", day: " << day << ", month: " << monthCount << endl;
        newDay -= dim;
        monthCount++;
        dim = daysInMonth(monthCount, year);
    }
    day = newDay;
    month = monthCount;
}

Date::Date(string mo, int dy, int yr)
{
    year = yr;
    day = dy;
    month = monthFromWord(mo);
}

// calls ctime to populate day, month, and year
Date::Date()
{
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
}

// output Date object to show when its destructor is called
Date::~Date()
{
    cout << "Date object destructor for date ";
    print();
    cout << endl;
} // end ~Date destructor

void Date::print() const
{
    cout << year << '/' << month << '/' << day;
}

int Date::monthFromWord(string mo) const
{
    // string months[monthsPerYear] = {"January", "February", "March", "April",
    //                                 "May", "June", "July", "August",
    //                                 "September", "October", "November", "December"};

    for (int i = 0; i < monthsPerYear; ++i)
    {
        if (mo == Date::spelledMonths[i])
            return i + 1;
    }
    return 1;
}

// returns the days in the specified month
int Date::daysInMonth(int mo, int yr) const
{
    int daysPerMonth[monthsPerYear + 1] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mo == 2)
    {
        if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0))
            return 29;
        else
            return 28;
    }
    else
        return daysPerMonth[mo];
}

// print Date object in form month/day/year
void Date::printAmerican() const
{
    // cout << month << '/' << day << '/' << year;
    cout << month << '/' << day << '/' << year % 100;
} // end function print

void Date::printDayYear() const
{
    int dayCount = day;
    int daysPerMonth[monthsPerYear + 1] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < month; ++i)
    {
        if (i == 2)
        {
            // leap year?
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                dayCount += 29;
            }
            else
                dayCount += 28;
        }
        else
            dayCount += daysPerMonth[i];
    }
    cout << setfill('0') << setw(3) << dayCount << ' ' << year;
}

void Date::printVerbose() const
{
    // string months[] = {"January", "February", "March", "April", "May", "June",
                    //    "July", "August", "September", "October", "November", "December"};
    cout << Date::spelledMonths[month - 1] << ' ' << day << ", " << year;
}

// utility function to confirm proper day value based  on
// month and year; handles leap years, too
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[monthsPerYear + 1] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // February 29 check for leap year
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("Invalid day for current month and year");
} // end function checkDay
