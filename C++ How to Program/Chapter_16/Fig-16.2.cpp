// Fig 16.2 A simple exception-handling example that checks for
// divide-by-zero exceptions.

#include <iostream>
#include "DivideByZeroException.h"
using namespace std;

// perform division and throw  DivideByZeroException object if
// divide-by-zero exception occurs
double quotient(int numerator, int denominator)
{
    // throw DivideByZeroExceptioinn object if 
    // divide-by-zero exception occurs
    if (denominator == 0)
        throw DivideByZeroException(); // terminate function
    
    // return division result
    return static_cast<double>(numerator) / denominator;
} // end function quotient

int main()
{
    int number1; // user-specified numerator
    int number2; // user-specified denominator
    double result; // result of division

    cout << "Enter two integers (end-of-file to end): ";

    // enable user to enter two integers to divide
    while (cin >> number1 >> number2 )
    {
        // try block contains code that might throw exception
        // and code that will not execute if an exception occurs
        try
        {
            result = quotient(number1, number2);
            cout << "The quotient is: " << result << endl;
        } // end try
        catch(DivideByZeroException &divideByZeroException)
        {
            cout << "Exception occurred: "
                << divideByZeroException.what() << endl;
        } // end catch
        cout << "\nEnter two integers (end-of-file to end): ";
    } // end while
    cout << endl;
} // end main