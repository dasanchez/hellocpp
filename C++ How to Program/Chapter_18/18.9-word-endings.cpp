// 18.9: Words Ending in "r" or "ay"
// Write a program that reads in several strings and prints only those
// ending in 'r' or 'ay'. Only lowercase letters should be considered.
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string sentence;
	cout << "Enter a sentence:\n";
	getline(cin, sentence);
	istringstream inString(sentence);
	while (!inString.eof())
	{
		string newWord;
		inString >> newWord;
		if (newWord.find("r", newWord.length() - 1) != string::npos)
			cout << newWord << endl;
		else if (newWord.find("ay", newWord.length()-2) != string::npos)
			cout << newWord << endl;
	}
}
