// Fig 18.7: Demonstrating string member functions erase and replace.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // compiler concatenates all parts into one string
    string string1("The values in any left subtree"
    "\nare less than the value in the"
    "\nparent node and the values in"
    "\nany right subtree are greater"
    "\nthan the value in the parent node");

    cout << "Original string:\n" << string1 << endl << endl;

    // remove all characters from (and including) location 62
    // through the end of string1
    string1.erase(62);

    // output new string
    cout << "Original string after erase:\n" << string1
        << "\n\nAfter first replacement:\n";

    int position = string1.find(" "); // find first space

    // replace all spaces with period
    while (position != string::npos)
    {
        string1.replace(position, 1, ".");
        position = string1.find(" ", position + 1);
    } // end while

    cout << string1 << "\n\nAfter second replacement:\n";

    position = string1.find("."); // find first period

    // replace all periods with two semicolons
    // NOTE: this will overwrite characters
    while (position != string::npos)
    {
        string1.replace(position, 2, "noise;yyy", 5, 2);
        position = string1.find(".", position + 1);
    }

    cout << string1 << endl;
} // end main