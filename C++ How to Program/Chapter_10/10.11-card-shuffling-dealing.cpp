/*
10.11 Card Shuffling and Dealing
Modify the program from 10.10 so that it deals a five-card poker hand. 
Then write functions to accomplish each of the following:
a) Determine whether the hand contains a pair
b) Determine whether the hand contains two pairs.
c) Determine whether the hand contains three of a kind (e.g. three jacks).
d) Determine whether the hand contains four of a kind (e.g. four aces).
e) Determine whether the hand contains a flush (i.e., all five cards of the same suit).
f) Determine whether the hand contains a straight (i.e., five cards of consecutive
face values).
*/
#include <iostream>
#include "DeckOfCards.h"
using namespace std;

void sortFaces(int *);
int countForward(int *);
int countBackward(int *);

int main()
{
    int faceCount[13] = {0};
    int suitCount[4] = {0};
    int pairCount = 0;
    int triadCount = 0;
    int quadCount = 0;
    int fCount = 0;
    int faces[5] = {0};

    // initialize deck object
    DeckOfCards deck;

    cout << "\nShuffling deck...\n\n";
    deck.shuffle();

    cout << "Dealing five cards: " << endl;
    vector<Card> fiveCards = deck.dealFiveCards();

    for (size_t i = 0; i < fiveCards.size(); ++i)
    {
        cout << fiveCards.at(i).toString() << endl;
        faceCount[fiveCards.at(i).getFace()]++;
        suitCount[fiveCards.at(i).getSuit()]++;
        faces[i] = fiveCards.at(i).getFace();
    }

    // sort faces array
    sortFaces(faces);

    for (int i = 0; i < 5; ++i)
        cout << faces[i] << ' ';
    cout << endl;

    for (int i = 0; i < 13; ++i)
    {
        // cout << i << ": " << faceCount[i] << endl;
        if (faceCount[i] == 2)
        {
            pairCount++;
        }
        if (faceCount[i] == 3)
        {
            triadCount++;
        }
        if (faceCount[i] == 4)
        {
            quadCount++;
        }
    }
    if (pairCount == 1)
    {
        cout << "Hand has one pair." << endl;
    }
    else if (pairCount == 2)
    {
        cout << "Hand has two pairs." << endl;
    }
    if (triadCount == 1)
    {
        cout << "Hand has three of a kind." << endl;
    }
    if (quadCount == 1)
    {
        cout << "Hand has four of a kind." << endl;
    }

    // cout << "Counting suits..." << endl;
    for (int i = 0; i < 4; ++i)
    {
        if (suitCount[i] == 5)
        {
            cout << "The hand contains a flush." << endl;
            break;
        }
    }


    // check for adjacent faces
    fCount = countForward(faces);
    if (fCount < 5 && faces[0] == 0)
    {
        // first face is an ace, cout backwards from the end of the array
        fCount += countBackward(faces);
    }
    if (fCount == 5)
        cout << "Hand contains a straight." << endl;

} // end main

void sortFaces(int *faces)
{
    for (int pass = 0; pass < 5 - 1; ++pass) // number of passes
    {
        bool swaps = false;
        // cout << "Pass " << pass + 1 << ": " << endl;
        for (int i = 0; i < 5 - 1 - pass; ++i) // number of comparisons
        {
            int bubble = faces[i + 1];
            if (faces[i] > bubble) // next element is higher
            {
                // cout << "Swap " << faces[ i ] << " with " << bubble << endl;
                faces[i + 1] = faces[i];
                faces[i] = bubble;
                swaps = true;
            }
        }
        if (!swaps) // no further passes required
        {
            // cout << "Face array is in order" << endl;
            break;
        }
    }
}

int countForward(int *faces)
{
    int current = faces[0];
    int count = 1;
    while (current + 1 == faces[count])
    {
        current = faces[count];
        count++;

        if (count == 5)
            break;
    }
    return count;
}

int countBackward(int *faces)
{
    int current = faces[4];
    int count = 0;
    if (current == 12)
    {
        count = 1;
        while (current - 1 == faces[4 - count])
        {
            count++;
            if (count == 4)
                break;
        }
    }
    return count;
}
