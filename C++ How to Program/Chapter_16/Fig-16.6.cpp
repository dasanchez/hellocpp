// Fig 16.6
// Demonstrating set_new_handler.

#include <iostream>
#include <new> // set_new_handler function prototype
#include <cstdlib> // abort function prototype
using namespace std;

// handle memory allocation failure
void customNewHandler()
{
    cerr << "customNewHandler was called" << endl;
    abort();
} // end function customNewHandler

// using set_new_handler to handle failed memory allocation
int main()
{
    double *ptr[50];

    // specify that customNewHandler should be called on
    // memory allocation failure
    set_new_handler(customNewHandler);

    // aim each ptr[i] at a big block of memory; customNewHandler will be
    // called on failed memory allocation
    for (int i=0; i< 50; ++i)
    {
    ptr[i] = new double[50000000]; // may throw exception
    cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
    } // end for
} // end main
