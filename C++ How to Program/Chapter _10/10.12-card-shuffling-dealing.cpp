/*
10.12 Card Shuffling and Dealing
Use the functions from Exercise 10.11 to write a program that deals two five-card
poker hands, evaluates each hand and determines which is the better hand.
8: Straight flush
7: 4 of a kind
6: Full house (pair, 3 of a kind)
5: Flush
4: Straight
3: 3 of a kind
2: Two pairs
1: One pair
0: High card
*/
#include <iostream>
#include "DeckOfCards.h"
using namespace std;

void sortFaces(int *);
int countForward(int *);
int countBackward(int *);
bool isStraight(int *);
int rateHand(vector<Card>, int *);

int main()
{

    int rateOne, rateTwo;
    int facesOne[5], facesTwo[5];
    // initialize deck object
    DeckOfCards deck;

    cout << "\nShuffling deck...\n\n";
    deck.shuffle();

    cout << "Dealing five cards: " << endl;
    vector<Card> handOne = deck.dealFiveCards();
    vector<Card> handTwo = deck.dealFiveCards();

    cout << "\nHand one:" << endl;
    rateOne = rateHand(handOne, facesOne);
    cout << "\nHand two:" << endl;
    rateTwo = rateHand(handTwo, facesTwo);

    cout << "\nHand one: " << rateOne << ", hand two: " << rateTwo << endl;

    if (rateOne > rateTwo)
        cout << "Hand one wins." << endl;
    else if (rateOne < rateTwo)
        cout << "Hand two wins." << endl;
    else
    {
        rateOne = facesOne[4];
        rateTwo = facesTwo[4];
        if (rateOne > rateTwo)
            cout << "Hand one wins." << endl;
        else if (rateOne < rateTwo)
            cout << "Hand two wins." << endl;
    }

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

bool isStraight(int *faces)
{
    // check for adjacent faces
    int forCount = countForward(faces);
    if (forCount < 5 && faces[0] == 0)
    {
        // first face is an ace, cout backwards from the end of the array
        forCount += countBackward(faces);
    }

    if (forCount == 5)
        return true;
    return false;
}

int rateHand(vector<Card> fiveCards, int *handFaces)
{
    int faceCount[13] = {0};
    int suitCount[4] = {0};
    int pairCount = 0;
    int triadCount = 0;
    int quadCount = 0;
    int faces[5] = {0};
    bool isFlush = false;

    for (size_t i = 0; i < fiveCards.size(); ++i)
    {
        cout << fiveCards.at(i).toString() << endl;
        faceCount[fiveCards.at(i).getFace()]++;
        suitCount[fiveCards.at(i).getSuit()]++;
        faces[i] = fiveCards.at(i).getFace();
    }

    // sort faces array
    sortFaces(faces);

    // count faces
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

    // cout << "Counting suits..." << endl;
    for (int i = 0; i < 4; ++i)
    {
        if (suitCount[i] == 5)
        {
            isFlush = true;
        }
    }

    if (isStraight(faces))
    {
        // cout << "Hand is straight";
        if (isFlush)
            return 8;
        else
            return 4;
    }
    else if (quadCount == 1)
        return 7;
    else if (pairCount == 1 && triadCount == 1)
        return 6;
    else if (isFlush)
        return 5;
    else if (triadCount == 1)
        return 3;
    else if (pairCount == 2)
        return 2;
    else if (pairCount == 1)
        return 1;

    handFaces = faces;

    return 0;
}