// 18.24: Letter Pyramid
// Write a program that generates the following from the string
// "abcdefghijklmnopqrstuvwxyz":
//
//              a
//             bcb
//            cdedc
//           defgfed
//             ...
// nopqrstuvwxyz{zyxwvutsrqpon

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printPyramidRow(const unsigned int, const unsigned int);

int main()
{
    // The pyramid is made up of lines of increasing length with
    // an odd count of characters, starting with 1.
    unsigned int maxWidth = 27;
    for (unsigned int i = 1; i <= maxWidth; i += 2)
    {
        printPyramidRow(i, maxWidth);
    }
}

void printPyramidRow(const unsigned int rowWidth, unsigned const int maxWidth)
{
    const string alphabet("abcdefghijklmnopqrstuvwxyz");

    // cout << rowWidth << ": ";
    // fill space:
    for (size_t i = 0; i < (maxWidth - rowWidth) / 2; ++i)
        cout << " ";

    // extract relevant alphabet section
    const string sub(alphabet.substr((rowWidth - 1) / 2, rowWidth / 2));

    // print left half
    cout << sub;

    // print middle character
    try
    {
        cout << alphabet.at(rowWidth - 1);
    }
    catch (out_of_range)
    {
        cout << "{";
    }

    // print right half
    string::const_reverse_iterator revit = sub.rbegin();
    while (revit != sub.rend())
    {
        cout << *revit;
        *revit++;
    }
    cout << endl;
}
