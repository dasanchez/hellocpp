// Fig 14.2: Stack.h
// Stack class template
#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
    explicit Stack(int = 10); // default constructor (Stack size 10)

    // destructor
    ~Stack()
    {
        delete[] stackPtr; // deallocate internal space for Stack
    }                      // end ~Stack destructor

    bool push(const T &); // push an element onto the Stack
    bool pop(T &);        // pop an element off the stack

    // determine whether Stack is empty
    bool isEmpty() const
    {
        return top == -1;
    } // end function isEmpty

    // determine whether Stack is full
    bool isFull() const
    {
        return top == size - 1;
    } // end function isFull

private:
    int size;    // # of elements in the stack
    int top;     // location of the top element (-1 means empty)
    T *stackPtr; // pointer to internal representation of the Stack
};               // end class template Stack

// constructor template
template <typename T>
Stack<T>::Stack(int s)
    : size(s > 0 ? s : 10), // validate size
      top(-1),              // Stack initially empty
      stackPtr(new T[size]) // allocate memory for elements
{
    // empty body
} // end Stack constructor

// push element onto Stack;
// if successful, return true; otherwise, return false
template<typename T>
bool Stack<T>::push(const T &pushValue)
{
    if (!isFull())
    {
        stackPtr[++top] = pushValue; // placeitem on Stack
        return true; // push successful
    }
    return false; // push unsuccessful
} // end function template push

// pop element off Stack;
// if successful, return true; otherwise, return false
template<typename T>
bool Stack<T>::pop(T &popValue)
{
    if (!isEmpty())
    {
        popValue = stackPtr[top--]; // remove item fro Stack
        return true; // pop successful
    } // end if
    return false; // pop unsuccessful
} // end function template pop

#endif