// 18.7: Simple encryption
// Some information on the Internet may be encrypted with a simple algorithm
// known as "rot13", which rotates each character by 13 positions in the alphabet.
// Thus, 'a' corresponds to 'n', and 'x' corresponds to 'k'. rot13 is an example of
// symmetric key encryption. With symmetric key encryption, both the encrypter and the
// decrypter use the same key.
// a. Write a program that encrypts a message using rot13.
// > Done
// b. Write a program that decrypts the scrambled message using 13 as the key.
// > Done- the encryption and decryption mechanisms are identical; it's just a toggle function.
// c. Briefly answer the following question: If you did not know the key for
// part b, how difficult do you think it would be to break the code? What if
// you had access to substantial computing power?
// > if we didn'r know the encryption key but we had a huge amount of processing power
// we could:
// - try different rotation lengths
// - run statistical analysis to identify common words (e.g. "the', 'and')

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void toggle_rot13(string &);

int main()
{
    string messageIn;
    cout << "Enter message:\n";
    getline(cin, messageIn);
    cout << "rot13 encryption:\n";
    toggle_rot13(messageIn);
    cout << messageIn << endl;
}

void toggle_rot13(string& msg)
{
	string::iterator iter = msg.begin();
	while (iter != msg.end())
	{
		char c = *iter;
		if ((c >= 'a' && c <= 'm' ) || (c >= 'A' && c <= 'M'))
		    *iter += 13;
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		    *iter -= 13;
		iter++;
	}
} // end toggle_rot13
