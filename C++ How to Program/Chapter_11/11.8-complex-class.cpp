// Ex 11.8: Complex Class
// Consider class Complex. The class enables operations on so-called
// complex numbers. These are numbers of the form realPart + imaginaryPart * i,
// where i has the value of square root of -1.
// a) Enable input and output of complex numbers via overloaded >> and <<
// operators, respectively (remove the print function from the class).
// b) Overload the multiplication operator to enable multiplication of two
// complex numbers as in algebra.
// c) Overload the == and != operators to allow comparisons of complex numbers.

#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    cout << "x: ";
    x.print();
    cout << "\ny: ";
    y.print();
    cout << "\nz: ";
    z.print();

    x = y + z;
    cout << "\n\nx = y + z:" <<  endl;
    x.print();
    cout << " = ";
    y.print();
    cout << " + ";
    z.print();
    cout << endl;

    x = y - z;
    cout << "\n\nx = y - z:" << endl;
    x.print();
    cout << " = ";
    y.print();
    cout << " - ";
    z.print();
    cout << endl;

    // >> input operator:
    Complex a;
    cout << "Enter real and imaginary parts of a complex number:" << endl;
    cin >> a;
    
    // << output operator:
    cout << "a: " << a << endl;

    // * multiplication operator:
    Complex b(1, 1);
    cout << "a * b = " << endl << "   " << a << endl << " * " << b << endl << " =========" << endl << "   " << a*b << endl;
    
} // end main
