#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cmath>
using std::sqrt;

double distance2D( double x1, double y1, double x2, double y2 );

int main()
{
    // Calculates the distance between two points (x1, y1) and (x2, y2).
    
    double x1, y1, x2, y2;
    cout << "Enter point 1 (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter point 2 (x2, y2): ";
    cin >> x2 >> y2;

    cout << "The distance between the points is " << distance2D( x1, y1, x2, y2 ) << endl;

    return 0; // indicate successful termination
} // end main

double distance2D( double x1, double y1, double x2, double y2 )
{
    return sqrt( ( y2 - y1  ) * ( y2 - y1) + ( x2 - x1 ) * (x2 - x1) );
    
}