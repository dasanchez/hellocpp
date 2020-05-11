// Ex 22.12: Palindromes
// Write a function template palindrome that takes a vector parameter and returns
// true or false according to whether the vector does or does not read the same
// forward as backward.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
bool palindrome(const vector<T> v) 
{
    // compare first half against second half in reverse
    int half = v.size()/2;
    vector<T> first_half(half);
    vector<T> second_half(half);

    copy_n(begin(v), half, begin(first_half));
    copy_n(rbegin(v), half, begin(second_half));
    
    return equal(begin(first_half), end(first_half), begin(second_half));
}

int main()
{
    vector<char> my_vector{'a', 'b', 'z', 'b', 'a'};
    
    cout << "Vector contains:\n";
    for (auto i:my_vector)
    {
        cout << i  << " ";
    }

    cout << "\nVector "
        << (palindrome(my_vector) ? "is " : "is not ")
        << "a palindrome.\n";
}
