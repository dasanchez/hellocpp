// 11.8: Date class test program

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date d1(12, 27, 2010); // December 27, 2010
    Date d2;               // defaults to Januray 1, 1900

    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\n\nd1 += 7 is " << (d1 += 7);

    d2.setDate(2, 28, 2008);
    cout << "\n\nd2 is now " << d2 << endl;
    cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3(7, 13, 2010);
    cout << "\n\nTesting the prefix increment operator:\n"
         << "  d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;
    cout << "  d3 is " << d3;

    cout << "\n\nTesting the postfix increment operator:\n"
         << "  d3 is " << d3 << endl;
    cout << "d3++ is " << d3++ << endl;
    cout << "  d3 is " << d3 << endl;
} // end main