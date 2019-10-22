// Fig 16.4
// Demonstrating stack unwinding
// ISO C++17 DOES NOT ALLOW DYNAMIC EXCEPTION SPECIFICATIONS

#include <iostream>
#include <exception>
using namespace std;

// function3 throws runtime error
void function3() 
{
    cout << "In function 3" << endl;
    // no try block, stack unwinding occurs, return control to function 2
    throw  runtime_error("runtime error in function3"); // no print
} // end function3

void function2()
{
    cout << "function3 is called inside function2" << endl;
    function3(); // stack unwinding occurs, return control to function1
} // end function2

// function1 invokes function2
void function1()
{
    cout << "function2 is called inside function1" << endl;
    function2(); // stack unwinding occurs, return control to main
} // end function1

// demonstrate stack unwinding
int main()
{
    // invoke function1
    try
    {
        cout << "function1 is called inside main" << endl;
        function1(); // call function1 which throws runtime_error
    } // end try
    catch(runtime_error &error) // handle runtime error
    {
        cout << "Exception occurred: " << error.what() << endl;
        cout << "Exception handled in main" << endl;
    } // end catch    
} // end main

