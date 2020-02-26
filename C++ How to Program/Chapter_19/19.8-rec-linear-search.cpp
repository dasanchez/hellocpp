// 19.8: Recursive Linear Search
// Modify Exercise 7.33 to use  recursive function recursiveLinearSearch to perform
// a linear search of the  vector. The function should receive the search key and
// starting index as arguments. If the search key is  found, return its index
// in the vector; otherwise, return -1. Each call to the recursive function
// should check one element  value in the vector.

#include <iostream>
#include <vector>

using namespace std;

int linearSearch(int, vector<int>, int);

int main()
{
    vector<int> searchVector{30, 0, 23, 80, 22, 5, 9, 75};
    int result;
    int input;

    for (size_t i=0; i < searchVector.size(); ++i)
        cout << searchVector.at(i) << " ";
    cout << endl;

    cout << "What number are you looking for? > ";
    cin >> input;
    result = linearSearch(input, searchVector, 0);

    if (result >= 0)
    {
        cout << "Found in position " << result << "." << endl;
    }
    else
        cout << "Not found." << endl;
}

int linearSearch(int key, vector<int> searchVector, int position)
{
    if (key == searchVector[position])
        return position;

    // key is not on the next position and there are still values left
    if (static_cast<int>(searchVector.size()) > (position + 1))
        return linearSearch(key, searchVector, position + 1);
    else // key is not on the next position and there are no values left
        return -1;
}