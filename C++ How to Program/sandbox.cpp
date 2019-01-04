// Fig 10.24: Hiding a class's private data with a proxy class.
// of a class.
#include <iostream>
#include "Interface.h"
using namespace std;

int main()
{
    Interface i(5); // create Interface object

    cout << "Interface contains: " << i.getValue()
         << " before setValue" << endl;

    i.setValue(10);
    cout << "Interface contains: " << i.getValue()
         << " after setValue" << endl;
} // end main