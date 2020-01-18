// 17.13: sizeof Operator
// Write a program that that uses the sizeof operator to determine the sizes
// in bytes of the various types on your computer system.
// Write the results to the file data-size.dat, so that you may print
// the results later. The results should be displayed in two-column format with
// the type name in the left column and the size of the type in the right column, as in:
// char              1
// unsigned char     1
// short int         2

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    
    ofstream outFile("data-size.dat", ios::out);

    outFile << setw(24) << left << "char" << setw(3) << right << sizeof(char) << endl;
    outFile << setw(24) << left << "unsigned char" << setw(3) << right << sizeof(unsigned char) << endl;
    outFile << setw(24) << left << "short int" << setw(3) << right << sizeof(short int) << endl;
    outFile << setw(24) << left << "unsigned short int" << setw(3) << right << sizeof(unsigned short int) << endl;
    outFile << setw(24) << left << "int" << setw(3) << right << sizeof(int) << endl;
    outFile << setw(24) << left << "unsigned int" << setw(3) << right << sizeof(unsigned int) << endl;
    outFile << setw(24) << left << "long int" << setw(3) << right << sizeof(long int) << endl;
    outFile << setw(24) << left << "unsigned long int" << setw(3) << right << sizeof(unsigned long int) << endl;
    outFile << setw(24) << left << "float" << setw(3) << right << sizeof(float) << endl;
    outFile << setw(24) << left << "double" << setw(3) << right << sizeof(double) << endl;
    outFile << setw(24) << left << "long double" << setw(3) << right << sizeof(long double) << endl;

    outFile.close();
}