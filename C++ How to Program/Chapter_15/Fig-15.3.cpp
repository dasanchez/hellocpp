// Fig 15.3: Printing the address stored in a char* variable.

#include <iostream>
using namespace std;

int main()
{
    char *word = "again"; // a constant pointer of constant characters

    // display value of char *, then display value of char *
    // static_cast to void *
    cout << "Value of word is: " << word << endl;
    cout << "Value of static_cast<void *> is: " << static_cast<void *>(word) << endl;
    // ISO C++ FORBIDS CONVERTING A STRING CONSTANT TO char*

} // end main