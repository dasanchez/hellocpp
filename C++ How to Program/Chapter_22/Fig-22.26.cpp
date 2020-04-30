// Fig 22.25: Standard Library algorithms
// fill, fill_n, generate, and generate_n
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>  // ostream_iterator
using namespace std;

int main()
{
    vector<char> chars(10);
    ostream_iterator<char> output(cout, " ");
    fill(begin(chars), end(chars), '5'); // fill chars with 5s

    cout << "Vector chars after filling with 5s:\n";
    copy(begin(chars), end(chars), output);

    // fill first five elements of chars with As
    fill_n(begin(chars), 5, 'A');

    cout << "\n\nVector chars after filling five elements with As:\n";
    copy(begin(chars), end(chars), output);

    // generate values for all elements of chars
    char letter = 'A';
    generate(begin(chars), end(chars), [&]() { return letter++; });

    cout << "\n\nVector chars after generating letters A-J:\n";
    copy(begin(chars), end(chars), output);

    // generate values for first five elements of chars
    generate_n(begin(chars), 5, [&]() { return letter++; });

    cout << "\n\nVector chars after generating K-O for the"
         << " first five elements:\n";
    copy(begin(chars), end(chars), output);
    cout << endl;
} // end main
