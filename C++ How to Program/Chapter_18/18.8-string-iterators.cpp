// 18.8: Using string iterators
// Write a program that Demonstrates the use of string functions rbegin and rend.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const string msg("This is a C++ string.");
	cout << msg << "\nReversed using rbegin and rend:\n";
	string::const_reverse_iterator  it = msg.rbegin();
	while (it != msg.rend())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}