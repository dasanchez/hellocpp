/*
10.8 Time Class Modification
Modify the Time class from Fig 10.15 to represent time internally
as the number of seconds since midnight.
Show there is no visible change in functionality to the clients of the class.
*/
#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

int main()
{
     // create Time objects
     Time t1(00,10,05);
     Time t2(4, 42, 0);
     Time t3(23, 59, 59);

     cout << "Time t1 in universal format: ";
     t1.printUniversal();     
     cout << "\nTime t1 in standard format: ";
     t1.printStandard();
     cout << endl << endl;

     cout << "Time t2 in universal format: ";
     t2.printUniversal();     
     cout << "\nTime t2 in standard format: ";
     t2.printStandard();
     cout << endl << endl;

     cout << "Time t3 in universal format: ";
     t3.printUniversal();     
     cout << "\nTime t3 in standard format: ";
     t3.printStandard();
     cout << endl << endl;
} // end main