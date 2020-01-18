// Fig 18.1: Demonstrating string assignment and concatenation
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1("cat");
    string string2; // initialized to the empty string
    string string3; // initialized to the empty string

    string2 = string1; // assign string1 to string2
    string3.assign(string1); // assign string1 to string3
    cout << "string1: " << string1 << "\nstring2: " << string2
        << "\nstring3: " << string3 << "\n\n";

    // modify string2 and string3
    string2[0] = string3[2] = 'r';

    cout << "After modification of string2 and string3:\n" << "string1: "
        << string1 << "\nstring2: " << string2 << "\nstring3: ";

    // demonstrating member function at
    for (int i=0; i<string3.length(); ++i)
        cout << string3.at(i);

    // declare string4 and string5
    string string4(string1 + "apult"); // concatenation
    string string5; // initialized to the empty string

    // overloaded +=
    string3 += "pet"; // create "carpet"
    string1.append("acomb"); // create "catacomb"

    // append subscript locations 4 through end of string1 to
    // create string "comb" (string5 was initially empty)
    string5.append(string1, 4, string1.length() - 4);

    cout << "\n\nAfter concatenation:\nstring1: " << string1
        << "\nstring2: " << string2 << "\nstring3: " << string3
        << "\nstring4: " << string4 << "\nstring5: " << string5 << endl;
} // end main
