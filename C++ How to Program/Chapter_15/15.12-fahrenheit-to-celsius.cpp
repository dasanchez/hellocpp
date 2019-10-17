// Fig 15.12: Converting Fahrenheit to Celsius.
// Write a program that converts integer Fahrenheit temperatures
// from 0 to 212 degrees to floating-point Celsius temperatures with
// 3 digits of precision.
// Use the formula celsius = 5.0 / 9.0 * (fahrenheit -32).
// The output should be printed in two right-justified columns
// and the Celsius temperatures should be preceded by a sign for
// both positive and negative values.

#include <iostream>
#include <iomanip>
using namespace std;

double getCelsius(int);

int main()
{
    cout << "        °F" << '\t' << "        °C" << endl;

    for (int f =0; f <= 212; ++f)
    {
        cout << setw(10) << noshowpos << f << '\t';
        cout << setw(10) << showpos << internal << fixed
            << setprecision(3) << getCelsius(f) << endl;
    }
} // end main


double getCelsius(int fValue)
{
    return (fValue - 32) * (5.0/9.0);
}