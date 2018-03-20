#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int gcd( int x, int y);

int main()
{
    // Write a recursive function gcd that returns the greatest common divisor of x and y, defined recursively as follows:
    // If y is equal to 0, then gcd( x, y ) is x; otherwise, gcd( x, y ) is gcd( y, x % y )
    // x must be larger than y.
    int x;
    int y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    // Swap if necessary
    if (y > x)
    {
        int temp = y;
        y = x;
        x = temp;
    }
    cout << "GCD of " << x << " and " << y << ": " << gcd( x, y ) << endl;

    return 0; // indicate successful termination
} // end main

int gcd( int x, int y )
{
    cout << "x: " << x << " y: " << y << endl;
    if ( y == 0 )
    {
        return x;
    }

    else
    {
        return gcd( y, x % y );
    }
    
}