// Fig 15.10: Demonstrating member function width.

#include <iostream>
using namespace std;

int main()
{
    int widthValue = 4;
    char sentence[10];

    cout << "Enter a sentence:" << endl;
    cin.width(5); // input only 5 characters from sentence

    // set field width, then display characters based on that width
    while (cin >> sentence)
    {
        cout.width(widthValue++);
        cout << sentence << endl;
        cin.width(5); // input 5 more characters from sentence
    } // end while
} // end main