// 18.10: String concatenation
// Demonstrate string concatenation by merging a first name and a
// last name using two different techniques.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string first;
	string last;
	string full;
	
	cout << "Enter your first and last name:\n";
	cin >> first >> last;
	
	full = first + " " + last;
	cout << "Hello, " << full << "!\n";

	full.clear();
	
	full.append(first);
	full.append(" ");
	full.append(last);
	cout << "Hello, " << full << "!\n";
}