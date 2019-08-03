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

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    x = y + z;
    cout << "\nx = y + z:" << x << " = " << y << " + " << z << endl;

    x = y - z;
    cout << "\nx = y - z:" << x << " = " << y << " - " << z << endl;
    
    // >> input operator:
    Complex a;
    cout << "\nEnter real and imaginary parts of a complex number:" << endl;
    cin >> a;
    
    // << output operator:
    cout << "a: " << a << endl;

    // * multiplication operator:
    Complex b(1, 1);
    cout << "\nb: " << b << endl;
    cout << "a * b = " << endl << "   " << a << endl << " * " << b << endl << " =========" << endl << "   " << a*b << endl;
    
    // == equality operator:
    Complex c(1, 1);
    cout << "\nc: " << c << endl;
    cout << "b == c : " << (b==c) << endl;
    c = Complex(2, 1);
    cout << "\nc: " << c << endl;
    cout << "b == c : " << (b==c) << endl;
    
    // != inequality operator:
    cout << "\nb: " << b << endl;
    cout << "c: " << c << endl;
    cout << "b != c : " << (b!=c) << endl;
    c = Complex(1, 1);
    cout << "\nc: " << c << endl;
    cout << "b != c : " << (b!=c) << endl;    

} // end main
