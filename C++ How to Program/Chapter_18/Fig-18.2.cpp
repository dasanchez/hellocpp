// Fig 18.2: Demonstrating string comparison capabilities

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1("Testing the comparison functions.");
    string string2("Hello");
    string string3("stinger");
    string string4(string2);

    cout << "string1: " << string1 << "\nstring2: " << string2
        << "\nstring3: " << string3 << "\nstring4: " << string4 << "\n\n";

    // comparing string1 and string4
    if (string1 == string4)
        cout << "string1 == string4\n";
    else // string1 != string4
    {
        if (string1 > string4)
            cout << "string1 > string4\n";
        else
            cout << "string1 < string4\n";
    }  // end else

    // comparing string1 and string2
    int result = string1.compare(string2);

    if (result == 0)
        cout << "string1.compare(string2) == 0\n";
    else // result != 0
    {
        if (result  > 0)
            cout << "string1.compare(string2) > 0\n";
        else // result < 0
            cout << "string1.compare(string2) < 0\n";
    } // end else

    // comparing string1 (elements 2-5) and string3 (elements 0-5)
    result = string1.compare(2, 5, string3, 0, 5);

    if (result == 0)
        cout << "string1.compare(2, 5, string3, 0, 5) == 0\n";
    else // result != 0
    {
        if (result > 0)
            cout << "string1.compare(2, 5, string3, 0, 5) > 0\n";
        else // result < 0
            cout << "string1.compare(2, 5, string3, 0, 5) < 0\n";
    } // end else

    // comparing string2 and string4
    result = string4.compare(0 , string2.length(), string2);

    if (result == 0)
        cout << "string4.compare(0, string2.length(), "
            << "string2 ) == 0" << endl;
    else // result != 0
    {
        if (result > 0)
            cout << "string4.compare(0, string2.length(), "
                << "string2 ) > 0" << endl;
        else // result < 0
            cout << "string4.compare(0, string2.length(), "
                << "string2 ) < 0" << endl;
    } // end else

    // comparing string2 and string4
    result = string2.compare(0, 3, string4);

    if (result == 0)
        cout << "string2.compare(0, 3, string4) == 0" << endl;
    else // result != 0
    {
        if (result > 0)
            cout << "string2.compare(0, 3, string4) > 0" << endl;
        else // result < 0
            cout << "string2.compare(0, 3, string4) < 0" << endl;
    } // end else
} // end main