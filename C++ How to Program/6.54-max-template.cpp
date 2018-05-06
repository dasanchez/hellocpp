/****
 * Write a function template called min to determine the larger of two arguments.
 * Test the program with integer, character, and floating point arguments.
 ***/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template < class T > T max( T value1, T value2 )
{
  T maximumValue = value1;
  if ( value2 > maximumValue )
      maximumValue = value2;
  return maximumValue;
}

int main()
{
    int i1, i2;
    char c1, c2;
    double d1, d2;

    cout << "Enter two integers: ";
    cin >> i1 >> i2;
    cout << "Enter two characters: ";
    cin >> c1 >> c2;
    cout << "Enter two doubles: ";
    cin >> d1 >> d2;

    cout << "The maximum of " << i1 << " and " << i2 << " is " << max( i1, i2 ) << endl;
    cout << "The maximum of " << c1 << " and " << c2 << " is " << max( c1, c2 ) << endl;
    cout << "The maximum of " << d1 << " and " << d2 << " is " << max( d1, d2 ) << endl;

    return 0; // indicate successful termination
} // end main
