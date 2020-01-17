// 17.12: Telephone Number Word Generator
// Write a program that, given a seven-digit number writes to a file every possible
// seven-letter word corresponding to that number. There are 2187 (3 to the seventh
// power) such words. Avoid numbers with the digits 0 and 1.
// The numbers 2 through 9 each have three letters associated with them, as is
// indicated by the following table:
// 2: ABC
// 3: DEF
// 4: GHI
// 5: JKL
// 6: MNO
// 7: PQRS
// 8: TUV
// 9: WXYZ

#include <iostream>
#include <fstream>

using namespace std;

string letters(char);
bool increaseIndices(int[], const int[], int);
string assembleWord(const string, const int[]);

int main()
{
    int letterCounts[7] = {0};
    int letterIndices[7] = {0};
    long int comboCount = 0;
    string phoneNumber;

    cout << "Enter your phone number (7 digits only):\n> ";
    cin >> phoneNumber;

    // validate length
    while (phoneNumber.length() != 7)
    {
        cout << "Enter your phone number (7 digits only):\n> ";
        cin >> phoneNumber;
    }

    ofstream outNewMaster("phone-results.txt", ios::out);
    // end program if program cannot open file
    if (!outNewMaster)
    {
        cerr << "phone-results.txt could not be created." << endl;
        exit(1);
    } // end if
    else
    {
        cout << "Saving words..." << endl;
    }

    // set index limits
    for (int i = 0; i < 7; ++i)
    {
        letterCounts[i] = letters(phoneNumber[i]).length();
    }

    // set first combination
    outNewMaster << assembleWord(phoneNumber, letterIndices) << endl;
    comboCount++;

    while (!increaseIndices(letterIndices, letterCounts, 6))
    {
        outNewMaster << assembleWord(phoneNumber, letterIndices) << endl;
        comboCount++;
    }

    outNewMaster.close();
    cout << comboCount << " combinations found." << endl;
}

// returns letters assigned to a given digit
string letters(const char digit)
{
    switch (digit)
    {
    case '2':
        return string("ABC");
        break;
    case '3':
        return string("DEF");
        break;
    case '4':
        return string("GHI");
        break;
    case '5':
        return string("JKL");
        break;
    case '6':
        return string("MNO");
        break;
    case '7':
        return string("PQRS");
        break;
    case '8':
        return string("TUV");
        break;
    case '9':
        return string("WXYZ");
        break;
    case '0':
        return string("0");
        break;
    case '1':
        return string("1");
        break;
    default:
        break;
    }
    // 2: ABC

    return string("\0");
} // end function letters

// recursive function increases index array
bool increaseIndices(int indices[], const int limits[], int index)
{
    indices[index]++;

    if (indices[index] == limits[index])
    {
        if (index == 0)
        {
            indices[index]--;
            return true;
        }
        else
        {
            indices[index] = 0;
            return increaseIndices(indices, limits, index - 1);
        }
    }
    return false;
} // end function increaseIndices

string assembleWord(const string digits, const int indices[])
{
    // digits represents the phone number
    // indices represents the letter we want for a given digit
    string newWord;
    for (int i = 0; i < 7; ++i)
    {
        newWord.append(1, (letters(digits[i])[indices[i]]));
    }
    return newWord;
} // end function assembleWord