// Fig 22.5: Demonstrating input and output with iterators.

#include <iostream>
#include <iterator> // ostream_iterator and istream_iterator

using std::cout;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
using std::endl;

int main()
{
    cout << "Enter two integers: ";

    // create istream_iterator for reading int values from cin
    istream_iterator<int> inputInt(cin);

    int number1 = *inputInt; // read int from standard input
    ++inputInt; // move iterator to next input value
    int number2 = *inputInt; // read int from standard input

    // create ostream_iterator for writing int values to cout
    ostream_iterator<int> outputInt(cout);

    cout << "The sum is: ";
    *outputInt = number1 + number2; // output result to cout
    cout << endl;
} // end main