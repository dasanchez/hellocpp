// Ex 14.6: Operator Overloads in Templates
// Write a simple function template for presudcate function isEqualTo
// that compares is two arguments of the same type with the equality
// operator (==) and returns true if they are equal and false otherwise.
// Use this function template in a program that calls isEqualTo only with
// a variery of fundamental types. Now write a separate version of
// the program that calls isEqualTo with a user-defined class type,
// but does not overload the equality operator. What happens when you
// attempt to run this program? > Compilation fails.
// Now overload the equality operator (with the operator function)
// operator==. Now what happens when you attempt to run this program?
// > Compilation and execution succeed.

#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

// function template isEqualTo definition
template <typename T>
bool isEqualTo(const T itemOne, const T itemTwo)
{
    if (itemOne == itemTwo)
        return true;
    else
        return false;
} // end function template isEqualTo

class myInteger
{
    public:
    
    myInteger(int number)
    : integer(number)
    {
    }

    int number() const
    {
        return integer;
    }

    bool operator==(const myInteger &op2) const
    {
        if (integer == op2.integer)
            return true;
        else
        {
            return false;
        }   
    }

    private:
    int integer;
};

int main()
{
    int a = 5;
    int b = 6;

    cout << a << " is" << (isEqualTo(a, b) ? " " : " not ")
        << "equal to " << b << endl;

    b = 5;
    cout << a << " is" << (isEqualTo(a, b) ? " " : " not ")
        << "equal to " << b << endl;

    double c = 235.302;
    double d = 211;
    cout << c << " is" << (isEqualTo(c, d) ? " " : " not ")
        << "equal to " << d << endl;

    d = 235.302;
    cout << c << " is" << (isEqualTo(c, d) ? " " : " not ")
        << "equal to " << d << endl;


    myInteger e(10);
    myInteger f(11);
    myInteger g(10);

    cout << e.number() << " is equal to " << f.number() << ": " 
    << isEqualTo(e, f) << endl;

    cout << e.number() << " is equal to " << g.number() << ": " 
    << isEqualTo(e, g) << endl;
} // end main
