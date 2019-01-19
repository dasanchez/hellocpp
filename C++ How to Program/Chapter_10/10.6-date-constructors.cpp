// Ex 10.6: Date Class Modification
// Modify Fing 10.8 to provide the following capabilities:
// a. Output the date in multiple formats such as:
// DDD YYYY
// MM/DD/YY
// June 14, 1982
// b. Use overloaded constructors to create Date objects
// initialized with dates of the formats in part a.
// c. Create a Date constructor that reads the system date using
// the standard library functions of the <ctime> header and
// sets the Date members.
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

int main()
{
     Date d1(2018, 03, 3);
     Date d2(62, 2019);
     Date d3("March", 3, 2020);
     Date d4; // sets the date to today
     
     cout << "Date d1:" << endl;
     d1.printDayYear();
     cout << endl;
     d1.printAmerican();
     cout << endl;
     d1.printVerbose();
     cout << endl << endl;

     cout << "Date d2:" << endl;
     d2.printDayYear();
     cout << endl;
     d2.printAmerican();
     cout << endl;
     d2.printVerbose();
     cout << endl << endl;

     cout << "Date d3:" << endl;
     d3.printDayYear();
     cout << endl;
     d3.printAmerican();
     cout << endl;
     d3.printVerbose();
     cout << endl << endl;

     cout << "Date d4:" << endl;
     d4.printDayYear();
     cout << endl;
     d4.printAmerican();
     cout << endl;
     d4.printVerbose();
     cout << endl;

} // end main