// Ex 18.20: Replacing punctuation and tokenizing strings
// Write a program that inputs a line of text, replaces all
// punctiation marks with spaces and uses the C-string library
// function strtok to tokenize the string into indivdual words.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void removePunctuation(string&);

int main() {

    string lineIn;
    char  *token;
    const char delimiter[2] = " ";
    cout  << "Enter a line of text:" << endl;
    getline(cin, lineIn);

    // replace punctuation marks with sspaces
    removePunctuation(lineIn);

    // tokenize with strtok
    cout << "The tokens are:" << endl;
    token = strtok(lineIn.data(), delimiter);

    while (token != NULL)
    {
        cout << "> " << token << endl;
        token = strtok(NULL, delimiter);
    }
}

void removePunctuation(string& text)
{
    // look for: [ , . ! ? ; : -]
    string punctuation(",.!?:;-");
    string::const_iterator it = punctuation.begin();
    while (it != punctuation.end())
    {
        size_t result = text.find(*it, 0);
        while (result != string::npos)
        {
            text.replace(result, 1, " ");
            result = text.find(*it, 0);
        } // end npos check
        it++;
    } // end punctuation iteration
}