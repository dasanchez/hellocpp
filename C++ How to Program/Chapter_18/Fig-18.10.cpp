// Fig 18.10: Using an iterator to ouput a string.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1("Testing iterators");
    string::const_iterator iterator1 = string1.begin();

    cout << "string1 = " << string1
        << "\n(Using iterator iterator1) string1 is: ";

    // iterate through string
    while (iterator1 != string1.end())
    {
        cout << *iterator1; // dereference iterator to get char
        ++iterator1; // advance iterator to next char
    } // end while

    cout << endl;
} // end main