/*
 * Create and Destroy class definition.
 * Member functions defined in CreateAndDestroy.cpp.
*/
#include <string>
using namespace std;

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy
{
  public:
    CreateAndDestroy(int, string); // constructor
    ~CreateAndDestroy();           // destructor
  private:
    int objectID;   // ID number for object
    string message; // message deescribing objec
};                  // end class CreateAndDestroy

#endif