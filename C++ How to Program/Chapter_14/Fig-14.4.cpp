// Fig 14.4: Stack class template test program.
// Function main uses  a function template to manipulate objects of type Stack<T>.

#include <iostream>
#include <string>
#include "Stack.h" // Stack class template definition
using namespace std;

// function teamplate to manipulate Stack< T>
template<typename T>
void testStack(
    Stack<T> &theStack, // reference to Stack< T >
    T value, // initial value to push
    T increment, // increment for subsequent values
    const string stackName) // name of the Stack< T > object
    {
        cout << "\nPushing elements onto " << stackName << "\n";

        // push element onto Stack
        while (theStack.push(value))
        {
            cout << value << ' ';
            value += increment;
        } // end while

    cout << "\nStack is full. Cannot push " << value
    << "\n\nPopping elements from " << stackName << '\n';

// pop elements from Stack
while (theStack.pop(value))
cout << value << ' ';

cout << "\nStack is empty. Cannot pop" << endl;
    } // end function template testStack

int main()
{
    Stack<double> doubleStack(5); // size 5
    Stack<int> intStack; // default size 10

    testStack(doubleStack, 1.1, 1.1, "doubleStack");
    testStack(intStack, 1, 1, "intStack");
} // end main