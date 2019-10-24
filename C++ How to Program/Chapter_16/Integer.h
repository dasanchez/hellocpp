// Fig 16.7: Integer.h
// Integer class definition

class Integer
{
    public:
        Integer(int i=0); // Integer default constructor
        ~Integer(); // Integer destructor
        void setInteger(int i); // function to set Integer
        int getInteger() const; // function to return Integer

    private:
        int value;
}; // end class Integer