// Fig 10.21: Implementation.h
// Implementation class definition

class Implementation
{
  public:
    // constructor
    Implementation(int v)
        : value(v) // initialize value with v
    {
        // empty body
    } // end constructor implementation

    // set value to v
    void setValue(int v)
    {
        value = v; // should validate v
    }              // end function setValue

    // return value
    int getValue() const
    {
        return value;
    } // end function getValue
  private:
    int value; // data that we would like to hide from the client
};             // end class Implementation