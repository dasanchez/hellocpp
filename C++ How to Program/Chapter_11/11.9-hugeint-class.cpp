// Ex 11.9: HugeInt class
// A machine with 32-bit integers can represent integers in the range of approximately
// -2 billion to +2 billion. This fixed-size restriction is rarely troublesome, but
// there are applications in which we would like to be able to use a much wider range
// of integers. This is what C++ was built to do, namelly, create powerful new data types.
// Using the class HugeInt of figs. 11.17-11.19:
// a) Describe precisely how it operates.
// b) What restrictions does the class have?
// c) Overload the * multiplication operator.
// d) Overload the  / division operator.
// e) Overload all the relational and equality operators.

/* a)
* HugeInt uses an array of short integers to store each digit.
* Constructors use one of three types as an argument: an integer, another HugeInt, or a string.
* For integers, each digit is stored by dividing the input number by 10 several times.
* For strings, each number character is stored in the integer array.
* For addition operations, each set of matching decades is added and the carry is saved
* for the next iteration if each sum goes above 10. 
* If the addition operation is called with an integer or a string, the input is converted
* to a HugeInt before calling the main addition function.
* For << ouptut streams, each digit after leading zeros is printed using cout.
* 
*  b)
* The class can only store numbers 30-digits long.
* A HugeInt number cannot be assigned with the >> stream input operator.
* The class cannot perform subtraction.
* Sum operations are cropped to 30 digits.
*/

#include <iostream>
#include "Hugeint.h"
using namespace std;

int main()
{
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999");
    HugeInt n4("1");
    HugeInt n5;

    cout << "n1 is " << n1 << endl;
    cout << "n2 is " << n2 << endl;
    cout << "n3 is " << n3 << endl;
    cout << "n4 is " << n4 << endl;
    cout << "n5 is " << n5 << endl << endl;

    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;

    // * operator:
    HugeInt n6;
    n6 = n1 * n2;
    cout << n1 << " * " << n2 << " = " << n6 << endl;

    // < operator:
    HugeInt n7(7654321);
    cout << n1 << " < " << n2 << " = " << (n1 < n2) << endl;
    cout << n2 << " < " << n1 << " = " << (n2 < n1) << endl;
    cout << n1 << " < " << n7 << " = " << (n1 < n7) << endl;

    // <= operator:
    cout << n1 << " <= " << n7 << " = " << (n1 <= n7) << endl;

    // > operator:
    cout << n1 << " > " << n2 << " = " << (n1 > n2) << endl;
    cout << n2 << " > " << n1 << " = " << (n2 > n1) << endl;
    cout << n1 << " > " << n7 << " = " << (n1 > n7) << endl;

    // >= operator:
    cout << n1 << " <= " << n7 << " = " << (n1 >= n7) << endl;

    // == operator:
    cout << n1 << " == " << n2 << " = " << (n1 == n2) << endl;
    cout << n1 << " == " << n7 << " = " << (n1 == n7) << endl;

    // != operator:
    cout << n1 << " != " << n2 << " = " << (n1 != n2) << endl;
    cout << n1 << " != " << n7 << " = " << (n1 != n7) << endl;

    // - operator:
    HugeInt n8(100);
    cout << n1 << " - " << n2 << " = " << (n1 - n2) << endl;
    cout << n2 << " - " << n1 << " = " << (n2 - n1) << endl;
    cout << n1 << " - " << n8 << " = " << (n1 - n8) << endl;
    cout << n8 << " - " << n1 << " = " << (n8 - n1) << endl;

    // / operator:
    HugeInt n9;
    n9 = n1 / n2;
    cout << n1 << " / " << n2 << " = " << n9 << endl;
    cout << n1 << " / " << n1 << " = " << (n1 / n1) << endl;
    n9 = n2 / n1;
    cout << n2 << " / " << n1 << " = " << n9 << endl;
    n9 = n3/n1;
    cout << n3 << " / " << n1 << " = " << n9 << endl;

} // end main
