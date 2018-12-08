/*
 * Exercise 7.40
 * Find the  Minimum Value in a vector
 * Write a recursive function recursiveMinimum that takes an
 * integer vector and a starting subscript as arguments,
 * and returns the smallest element of the array.
 * The function should stop processing and return when the starting
 * subscript equals the size of the vector.
*/

#include <iostream>
#include <vector>

using namespace std;

int recursiveMinimum(const vector<int> &, int);

int main()
{
    const int arraySize = 5;
    vector<int> myArray(arraySize);
    cout << "Enter " << arraySize << " integers: ";
    for (size_t i = 0; i < arraySize; ++i)
        cin >> myArray[i];
    cout << "Minimum value: " << recursiveMinimum(myArray, 0) << endl;
}

int recursiveMinimum(const vector<int> &vec, int start)
{
    // here's the trick: use a static variable
    static int min = vec[start]; 
    
    if (vec.at(start) < min)
    {
        min = vec.at(start);
    }

    if (start == static_cast<int>(vec.size())-1)
    {
        return min;
    }
    else
    {
        return recursiveMinimum(vec, start + 1);
    }
}
