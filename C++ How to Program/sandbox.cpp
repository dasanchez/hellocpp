/*
 * Fig 10.13: Friends can access private members of a class.
*/
#include <iostream>
using namespace std;

// Count class definition
class Count
{
    friend void setX(Count &, int);

  public:
    // constructor
    Count()
        : x(0) // initialize x to 0
    {
        // empty body
    } // end constructor Count

    // output x
    void print() const
    {
        cout << x << endl;
    } // end function print
  private:
    int x; // data member
};         // end class Count

// function setX can modify private data  of Count
// because setX is declared as a friend of Count
void setX(Count &c, int val)
{
    c.x = val; // alloed because setX is a frend of Count
} // end function setX

int main()
{
    Count counter; // create Count object
    cout << "counter.x after instantiation: ";
    counter.print();
    setX(counter, 8); // set x using a friend function
    cout  << "counter.x after call to setX friend function: ";
    counter.print();
} // end main
