// Ex 20.11: Palindrome Testing with Stacks
// Write a program that uses a stack object to determine if a string is a palindrome
// (i.e. the string is spelled identically backward and forward). The program should
// ignore spaces and punctuation.
// > Program will read a string from the user, and load character by character in a
// stack. The stack will then be read back and compared against the string, read
// one character at a time.

#include <iostream>
#include <string>
#include <ctype.h>
#include "Stack.h"

int main()
{
    Stack<char> stack;
    string line;

    // user enters line
    cout << "Enter line of text: \n> ";
    getline(cin, line);

    // stack is populated
    for (size_t i = 0; i < line.length(); ++i)
    {
        // letter
        if ((line.at(i) >= 'a' && line.at(i) <= 'z') || (line.at(i) >= 'A' && line.at(i) <= 'Z'))
        {
            stack.push(tolower(line.at(i)));
            line[i] = tolower(line.at(i));
        }
        // number
        else if (line.at(i) >= '0' && line.at(i) <= '9')
            stack.push(line.at(i));
    }


    for (string::iterator it = line.begin(); it != line.end(); ++it)
    {
        // only accept letters and numbers
        if ((*it >= 'a' && *it <= 'z') || (*it >= '0' && *it <= '9'))
        {
            char stack_char;
            stack.pop(stack_char);

            if (stack_char != *it)
            {
                cout << "Not a palindrome." << endl;
                return 0;
            }
        }
    }

    cout << "Palindrome." << endl;
}
