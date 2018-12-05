// Fig 9.18: Date.cpp

#include <iostream>
#include "Date.h"
using namespace std;

// Date constructor (should do range checking)
Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
} // end  constructor Date

// print Date in the format mm/dd/yyyy
void Date::print()
{
    cout << month << '/' << day << '/' << year;
} // end function print

