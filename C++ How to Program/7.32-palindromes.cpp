// 7.32: Palindromes
// Write a recursive function testPalindrome that returns:
// true if a string is a palindrome,
// false otherwise.
// Like an array, the square brackets operator can be used
// to iterate therough the characters in a string.

#include <iostream>
using namespace std;

bool testPalindrome(string testWord);

int main()
{
    string testWordA = "radar";
    string testWordB = "able was i ere i saw elba";
    string testWordC = "palindrome";

    string stringArray[3] = {testWordA, testWordB, testWordC};
    for (int i = 0; i < 3; i++)
    {
        cout << "\"" << stringArray[i] << "\" is ";
        if (!testPalindrome(stringArray[i]))
        {
            cout << "not ";
        }
        cout << "a palindrome" << endl;
    }
}

bool testPalindrome(string testWord)
{
    if (testWord.length() == 1)
    {
        return true;
    }
    else
    {
        // check first and last characters
        if (testWord[0] == testWord[testWord.length() - 1])
        {
            if (testWord.length() == 2)
            {
                return true;
            }
            else
            {
                string subWord = testWord.substr(1, testWord.length() - 2);
                return testPalindrome(subWord);
            }
        }
    }

    return false;
}
