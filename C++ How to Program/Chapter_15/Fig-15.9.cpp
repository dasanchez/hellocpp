// Fig 15.9: Controlling precision of floating-point values.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double root2 = sqrt(2.0); // calculate square root of 2
    int places; // precision, vary from 0-9

    cout << "Square root of 2 with precisions 0-9." << endl
        << "Precision set by ios_base member function "
        << "precision:" << endl;
    cout << fixed; // use fixed-point notation

    // display square root using ios_base function precision
    for (places = 0; places <= 9; ++places)
    {
        cout.precision(places);
        cout << root2 << endl;
    } // end for

    cout << "\nPrecision set by stream manipulator "
     << "setprecision:" << endl;

     // set precision for each digit, then display square root
     for (places = 0; places <= 9; ++places)
        cout << setprecision(places) << root2 << endl;
} // end main