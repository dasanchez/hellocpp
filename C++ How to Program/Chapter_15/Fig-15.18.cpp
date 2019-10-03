// Fig 15.18: Displaying floating-point values in system default.

#include <iostream>
using namespace std;

int main()
{
    double x = 0.001234567;
    double y = 1.946e9;

    // display x and y in default format
    cout << "Displayed in default format:" << endl
        << x << '\t' << y << endl;
    
    // display x and y in scientific format
    cout << "\nDisplayed in scientific format:" << endl
        << scientific << x << '\t' << y << endl;

    // display x and y in fixed format
    cout << "\nDisplayed in fixed format:" << endl 
        << fixed << x << '\t' << y << endl;
} // end main