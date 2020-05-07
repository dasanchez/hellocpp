// Fig 22.42: Demonstrating function objects
#include <iostream>
#include <vector>
#include <algorithm>  // copy algorithm
#include <numeric>    // accumulate algorithm
#include <functional> // binary_function definition
#include <iterator>   // ostream_iterator

using namespace std;

// binary function adds square of its second argument and the
// running total in its first argument, then returns the sum
int sumSquares(int total, int value)
{
    return total + value * value;
} // end function sumSquares

// binary function class template defines overloaded operator()
// that adds the square of its second argument and running
// total in its first argument, then returns sum
template <typename T>
class SumSquaresClass : public binary_function<T, T, T>
{
public:
    // add square of value to total and return result
    T operator()(const T &total, const T &value)
    {
        return total + value * value;
    } // end function operator()
};    // end class SumSquaresClass

int main()
{
    vector<int> integers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ostream_iterator<int> output(cout, " ");
    int result;

    cout << "vctor integers contains:\n";
    copy(begin(integers), end(integers), output);

    // calculate sum of squares of elements of vector integers
    // using binary function sumSquares
    result = accumulate(begin(integers), end(integers), 0, sumSquares);

    cout << "\n\nSum of squares of elements in integers using "
         << "binary\nfunction sumSquares: " << result;

    // calculate sum of squares of elements of vector integers
    // using binary function object
    result = accumulate(begin(integers), end(integers), 0,
                        SumSquaresClass<int>());

    cout << "\n\nSum of squares of elements in integers using "
         << "binary\nfunction object of type "
         << "SumSquaresClass<int>: " << result << endl;

    // using a lambda function
    result = accumulate(begin(integers), end(integers), 0,
                        [](auto total, auto factor) { return total + factor * factor; });
    cout << "\n\nSum of squares of elements in integers using "
         << "lambda function: " << result << endl;

} // end main
