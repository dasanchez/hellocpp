// Fig 18.11: Using an ostringstream object.

#include <iostream>
#include <string>
#include <sstream> // header for string stream processing
using namespace std;

int main()
{
    ostringstream outputString; // create ostringstream instance

    string string1("Output of several data types ");
    string string2("to an ostringstream object:" );
    string string3("\n        double: ");
    string string4("\n           int: ");
    string string5("\naddress of int: ");
    double double1 = 123.4567;
    int integer = 22;

    // output strings, double and int to ostringstream outputString
    outputString << string1 << string2 << string3 << double1
        << string4 << integer << string5 << &integer;

    // call str to obtain string contents of the ostringstream
    cout << "outputString contains:\n" << outputString.str();

    // add additional characters and call str to output string
    outputString << "\nmore characters added";
    cout << "\n\nafter additional stream insertions,\n"
        << "outputString contains:\n" << outputString.str() << endl;
} // end main