// Overloaded stream insertion and stream extraction operators
// for class PhoneNumber
#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

// overloaded stream insertion operator; cannot be
// a member function if we would like to invoke it
// with cout << somePhoneNumber;
ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    if (cin.good())
    {
        output << "(" << number.areaCode << ") "
               << number.exchange << "-" << number.line;
    }
    return output; // enables cout << a << b << c;
} // end function operator<<

// overloaded stream extraction operator; cannot be
// a member functionif we would like to invoke it with
// cin >> somePhoneNumber;
istream &operator>>(istream &input, PhoneNumber &number)
{
    char inputArray[20];
    cin.clear();
    cin.get(inputArray, 20);

    // a) Test for number of characters entered
    if (cin.gcount() != 14)
    {
        cout << "Error: You need to enter exactly 14 characters." << endl;

        // bad format
        cin.clear(ios::failbit);
    }

    // b) Test area code and exchange do not begin with 0 or 1
    if (inputArray[1] == '0' || inputArray[1] == '1')
    {
        cout << "Error: Area code cannot start with 0 or 1." << endl;
        cin.clear(ios::failbit);
    }
    if (inputArray[6] == '0' || inputArray[6] == '1')
    {
        cout << "Error: Exchange cannot start with 0 or 1." << endl;
        cin.clear(ios::failbit);
    }

    // c) Test area code middle number is limited to 0 or 1
    if (inputArray[2] != '0' && inputArray[2] != '1')
    {
        cout << "Error: Area code middle number must be 0 or 1." << endl;
        cin.clear(ios::failbit);
    }

    if (cin.good())
    {
        string str(inputArray);
        number.areaCode.append(str, 1, 3);
        number.exchange.append(str, 6, 3);
        number.line.append(str, 10, 4);
    }
    // else
    // {
        // cout << "Format not accepted: use \"(123) 456-789\" format." << endl;
    // }

    // input.ignore(); // skip (
    // input >> setw(3) >> number.areaCode; // input areaCode
    // input.ignore(2); // skip ) and space
    // input >> setw(3) >> number.exchange; // input exchange
    // input.ignore(); // skip dash (-)
    // input >> setw(4) >> number.line; // input line
    return input; // enables cin >> a >> b >> c;
} // end function operator>>
