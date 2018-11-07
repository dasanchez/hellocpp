/*
 * Fig 8.4
 * Pointer operators & and *.
*/
#include <iostream>
using namespace std;

int main()
{
    int a; // a is an integer
    int *aPtr; // aPtr is an int * which is a pointer to an integer

    a = 7; // assigned 7 to a
    aPtr = &a; // assigned the address of a to aPtr

    cout << "The address of a is " << &a << endl;
    cout << "The value of aPtr is " << aPtr << endl;
    cout << "\nThe value of a is " << a << endl;
    cout << "The value of *aPtr is " << *aPtr << endl;
    cout << "\nShowing that * and & are inverses of each other:" << endl;
    cout << "&*aPtr = " << &*aPtr << "\n*&aPtr = " << *&aPtr << endl;
}
