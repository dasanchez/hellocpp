/* 
 * CreateAndDestroy.cpp
 * CreateAndDestroy class member-function definitions.
*/

#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

// constructor
CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
{
    objectID = ID; // set object's ID number
    message = messageString; // set object's descriptive message

    cout << "Object " << objectID << " constructor runs   "
        << message << endl;
} // end CreateAndDestroy constructor

// destructor
CreateAndDestroy::~CreateAndDestroy()
{
    // output newline for certain objects; helps readability
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");
    cout << "Object " << objectID << "   destructor runs    "
        << message << endl;
} // end ~CreateAndDestroy destructor
