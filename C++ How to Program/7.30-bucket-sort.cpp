// 7.30: Bucket Sort
// Write a function bucketSort that takes an integer array and
// the array size as arguments and performs as follows:
// a. Place each value of the  one-dimensional array into a row
// of the bucket array based on the value's ones digit.
// For example, 97 is placed in row 7, 3 is placed in row 3
// and 100 is placed in row 0. This is called a "distribution pass"
// b. Loop through the bucket array row by row, and copy the values
// back to the original array. This is called a "gathering pass".
// The new order of the preceding values in the one-dimensional
// array is 100, 3, and 97.
// c. Repeat this process for each subsequent digit position
// (tens, hundreds, thousands, etc.).

#include <iostream>
using namespace std;

const int digits = 10;
const int entries = 5;
void bucketSort(int array[]);
void printArray(int array[]);
void printBucket(int array[digits][entries]);

int main()
{
    int sortArray[entries];
    
    cout << "Enter " << entries << " integers:" << endl;
    for (int i=0; i<entries; ++i)
        cin >> sortArray[i]; 

    cout << "Array before sorting:" << endl;
    printArray(sortArray);

    bucketSort(sortArray);

    cout << "Array after sorting:" << endl;
    printArray(sortArray);
}

void bucketSort(int array[])
{
    int bucketArray[digits][entries]; // = {0};
    const int pow10[5] = {1, 10, 100, 1000, 10000};

    for (int octaveCounter = 0; octaveCounter < 5; octaveCounter++)
    {
        // empty bucket
        for (int row = 0; row < digits; ++row)
        {
            for (int col = 0; col < entries; ++col)
            {
                bucketArray[row][col] = 0;
            }
        }

        // Distribution pass
        int columnCounter[digits] = {};
        for (int i = 0; i < entries; ++i)
        {
            int row = (array[i] / pow10[octaveCounter]) % 10;
            bucketArray[row][columnCounter[row]++] = array[i];
        }

        // Gathering  pass
        int k = 0;
        for (int i = 0; i < digits; ++i)
        {
            for (int j = 0; j < columnCounter[i]; ++j)
            {
                array[k++] = bucketArray[i][j];
            }
        }
    }
}

void printArray(int array[])
{
    for (int i = 0; i < entries; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void printBucket(int bucket[digits][entries])
{
    cout << "\nPrinting bucket:" << endl;

    // Print bucket
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < entries; ++j)
        {
            cout << bucket[i][j] << " ";
        }
        cout << endl;
    }
}
