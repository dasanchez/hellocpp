// 18.11: Hangman Game
// Write a program that plays the game of Hangman.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hangman
{
public:
	void startGame()
	{
		alive = true;
		attempts = 0;
		word = generateWord();
		guess.assign(word.length(), ' ');
		guessHistory.clear();
		drawHangman();
		drawGuesses();
	}

	void newGuess(char letter)
	{
		// user submits a new character
		guessHistory.append(1, letter);
		cout << "You have tried: [" << guessHistory << "]\n";
		bool match = false;
		for (size_t i = 0; i < word.length(); ++i)
		{
			if (letter == word.at(i))
			{
				guess.at(i) = word.at(i);
				match = true;
			}
		}
		if (!match)
			attempts++;

		drawHangman();
		drawGuesses();

		if (word == guess)
		{
			cout << "YOU WON :)" << endl;
			alive = false;
		}
		else if (attempts >= 5)
		{
			cout << "YOU LOST :(" << endl;
			alive = false;
		}
	}

	bool isAlive() const
	{
		return alive;
	}

	void drawHangman() const
	{
		// draw top brace
		cout << "_________\n";
		switch (attempts)
		{
		case 0: // only the gallows
			cout << "|\n|\n|\n|\n|\n|\n";
			break;
		case 1: // rope and head
			cout << "|    |\n";
			cout << "|    O\n";
			cout << "|\n|\n|\n|\n";
			break;
		case 2: // arms
			cout << "|    |\n";
			cout << "|    O\n";
			cout << "|   /|\\\n";
			cout << "|\n|\n|\n";
			break;
		case 3: // chest
			cout << "|    |\n";
			cout << "|    O\n";
			cout << "|   /|\\\n";
			cout << "|    |\n";
			cout << "|\n|\n";
			break;
		case 4: // legs
			cout << "|    |\n";
			cout << "|    O\n";
			cout << "|   /|\\\n";
			cout << "|    |\n";
			cout << "|   / \\\n";
			cout << "|\n";
			break;
		default:
			break;
		}
		cout << endl;
	}

	void drawGuesses() const
	{
		// iterate through all the letters in the "guess" string
		for (size_t i = 0; i < guess.size(); ++i)
		{
			cout << setw(3) << guess.at(i);
		}
		cout << endl;
		for (size_t i = 0; i < guess.size(); ++i)
		{
			cout << setw(3) << "-";
		}
		cout << endl;
	}

private:
	string word;
	string guess;
	string guessHistory;
	int attempts;
	bool alive;

	string generateWord()
	{
		string words[5] = {"crypto", "formula", "algorithm", "obfuscation", "security"};
		unsigned int word = rand() % 5;
		return words[word];
	}
};

int main()
{
	srand(time(NULL));
	Hangman game;
	game.startGame();
	while (game.isAlive())
	{
		char newLetter;
		cout << "Enter a letter: ";
		cin >> newLetter;
		game.newGuess(newLetter);

		if (!game.isAlive())
		{
			newLetter = ' ';
			while ((newLetter != 'y' && newLetter != 'n') && (newLetter != 'Y' && newLetter != 'N'))
			{

				cout << "Play again? (Y/N) > ";
				cin >> newLetter;
			}
			if (newLetter == 'y' || newLetter == 'Y')
				game.startGame();
		} // end if
	} // end while
} // end main