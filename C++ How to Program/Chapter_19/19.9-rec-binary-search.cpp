// 19.9: Recursive Binary Search
// Modify Fig 19.3 to use recursive function recursiveBinarySearch to perform a binary
// search of the vector. The function should receive the search key, starting index,
// and ending index as arguments. If the search key is found, return its index
// in the vector. If the search key is not  found, return -1.

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

class BinarySearch
{
public:
    BinarySearch(int newSize)
    {
        size = newSize;
        srand(time(0));

        // populate vector
        for (int i = 0; i < size; ++i)
        {
            searchVector.push_back(rand() % 100);
        }
        // sort vector using <algorithm> include
        sort(searchVector.begin(), searchVector.end());
    }
    int search(int key) const
    {
        return binarySearch(key, 0, searchVector.size());
    }

    int binarySearch(int key, int begin, int end) const
    {
        // 1. calculate middle value
        int middle = ((end + begin) / 2);
        cout << "middle: " << searchVector.at(middle) << endl;

        // 2. three outcomes:
        // a. middle equals key
        if (searchVector.at(middle) == key)
        {
            return middle;
        }
        else if (searchVector.at(middle) > key)
        {
            // b. middle is higher than the key
            if (middle - begin > 0)
                return binarySearch(key, begin, middle);
        }
        else if (searchVector.at(middle) < key)
        {
            // c. middle is lower than the key
            if (end - middle > 1)
                return binarySearch(key, middle + 1, end);
        }

        return -1;
    }

    void displayElements() const
    {
        for (int i = 0; i < size; ++i)
            cout << searchVector.at(i) << " ";
        cout << endl;
    }

private:
    int size;
    vector<int> searchVector;
};
int main()
{
    BinarySearch bSearch(11); // create vector with 11 elements
    bSearch.displayElements();
    int input;

    cout << "Number to search for"
         << " (-1 to exit): ";
    cin >> input;

    while (input > 0)
    {
        int result = bSearch.search(input);
        if (result >= 0)
            cout << "Found " << input << " at location " << result << "." << endl;
        else
            cout << "Number " << input << " not found." << endl;
        bSearch.displayElements();
        cout << "Number to search for:"
             << " (-1 to exit): ";
        cin >> input;
    }
}
