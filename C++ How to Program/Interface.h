// Fig 10.22: Interface.h
// Proxy class Interface definition
// Client sees this source code, but the source code does not reveal
// the data layout of class Implementation.

class Implementation; // forward class declaration

class Interface
{
  public:
    Interface(int);        // constructor
    void setValue(int);    // same public  inteface as
    int getValue() const; // class Implementation has
    ~Interface();          // destructor
  private:
    // requires previous forward declaration
    Implementation *ptr;
}; // end class Interface