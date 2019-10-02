// Fig 15.7: Unformatted I/O using read, gcount and write.

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 80;
    char buffer[SIZE]; // create array of 80 characters

    // use function read to input characters into buffer
    cout << "Enter a sentence:" << endl;
    cin.getline(buffer, 20);

    // use functions write and gcount to display buffer characters
    cout << endl << "The sentence entered was:" << endl;
    cout.write(buffer, cin.gcount());
    cout << endl;
} // end main