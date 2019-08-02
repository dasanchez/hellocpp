// Ex 11.6: Memory Allocation and Deallocation Operators
// Compare and ccontrast dynamic memory allocation and
// deallocation operators new, new [], delete, and delete [].

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // The difference between the new and new [] operators is that
    // the former allocates memory for a single object, while
    // the latter allocates memory for an array.
    string *myString = new string;
    myString->append("Hi!");
    cout << *myString << endl;
    delete myString;

    string *strings = new string[3];
    strings[0] = "Hi ";
    strings[1] = "there, ";
    strings[2] = "partner!";

    cout << *strings << *(strings+1) << *(strings+2) << endl;

    delete [] strings;
}