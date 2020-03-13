// Ex 20.10: Printing a Sentence in Reverse Order with a Stack
// Write a program that inputs a line of text and uses a stack object
// to print the line reversed.

#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
    Stack<char> stack;
    string line;

    // user enters line
    cout << "Enter line of text: \n> ";
    getline(cin, line);

    // stack is populated
    for (size_t i =0; i<line.length(); ++i)
    {
        stack.push(line.at(i));
    }

    // stack is printed, FILO reverses the string
    cout << "Your line backwards:" << endl;
    for (int i=0; stack.getStackSize(); ++i)
    {
        char character;
        stack.pop(character);
        cout << character;
    }
    cout << endl;
}
