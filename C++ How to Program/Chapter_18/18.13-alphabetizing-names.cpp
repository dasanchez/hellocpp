// 18.13: Alphabetizing Animal Names
// Write a program that uses the comparison capabilities
// introduced in this chapter to alphabetize a series of
// animal names.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sortVector(vector<string> &);

int main()
{
    vector<string> animals;
    animals.push_back("Koala");
    animals.push_back("Elephant");
    animals.push_back("Dog");
    animals.push_back("Cat");
    animals.push_back("Eagle");
    animals.push_back("Bear");

    cout << "Original list:" << endl;

    for (size_t i = 0; i < animals.size(); ++i)
        cout << animals.at(i) << endl;

    sortVector(animals);

    cout << "After sorting:" << endl;

    for (size_t i = 0; i < animals.size(); ++i)
        cout << animals.at(i) << endl;
}

void sortVector(vector<string> &vector1)
{
    // bubble sort: quick and dirty
    for (size_t i = 0; i < vector1.size() - 1; ++i)
    {
        for (size_t j = 0; j < vector1.size() - 1 - i; ++j)
        {
            if (vector1.at(j) > vector1.at(j + 1))
            {
                string temp(vector1.at(j));
                vector1[j] = vector1[j + 1];
                vector1[j + 1] = temp;
            }
        }
    }
}