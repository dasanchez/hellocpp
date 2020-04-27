// Fig 22.23: Standard Library adapter stack test program.
#include <iostream>
#include <stack>  // stack adapter definition
#include <vector> // vector class-template definition
#include <list>   // list class-template definition
using namespace std;

// pushELements function-template prototype
template<typename T> void pushElements(T &stackRef);

// popElements function-template prototype
template<typename T> void popElements(T &stackRef);

int main()
{
    // stack with default underlying deque
    stack<int> intDequeStack;

    // stack with underlying vector
    stack<int, vector<int>> intVectorStack;

    // stack with underlying list
    stack<int, list<int>> intListStack;

    // push the values 0-9 onto each stack
    cout << "Pushing onto intDequeStack: ";
    pushElements(intDequeStack);
    cout << "\nPushing onto intVectorStack:";
    pushElements(intVectorStack);
    cout << "\nPushing onto intListStack:";
    pushElements(intListStack);
    cout << endl << endl;

    // display and remove elements from each stack
    cout << "Popping from intDequeStack: ";
    popElements(intDequeStack);
    cout << "\nPopping from intVectorStack: ";
    popElements(intVectorStack);
    cout << "\nPopping from intListStack: ";
    popElements(intListStack);
    cout << endl;
} // end main

// push elements onto stack object to which stackRef refers
template<typename T> void pushElements(T &stackRef)
{
    for (int i=0; i< 10; ++i)
    {
        stackRef.push(i); // push element onto stack
        cout << stackRef.top() << ' '; // view (and display) top element
    } // end for
} // end function pushElements

// pop elements from stack object to which stackRef refers
template<typename T> void popElements(T &stackRef)
{
    while (!stackRef.empty())
    {
        cout << stackRef.top() << ' '; // view (and display) top element
        stackRef.pop(); // remove top element
    } // end while
} // end function popElements

