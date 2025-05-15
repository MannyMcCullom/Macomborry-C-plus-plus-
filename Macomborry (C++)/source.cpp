/*
Sorry Video game
//*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int numOfCardTypes = 11;
const int numOfCards = 45;

struct card {
	string label;
	string optionOne;
	string optionTwo;
};

void printDeck(card*);
void shuffleDeck(card*);

int main()
{
	srand(time(0));
	card cards[numOfCardTypes];

	// Set card values
	for (int index = 0; index < numOfCardTypes; index++)
	{
		switch (index)
		{
		case 0:
			cards[index].label = "1";
			cards[index].optionOne = "Move one of your pawns forward one from START.";
			cards[index].optionTwo = "if in play, move foward one space.";
			break;
		case 1:
			cards[index].label = "2";
			cards[index].optionOne = "Move one of your pawns forward two from START.";
			cards[index].optionTwo = "if in play, move foward two spaces.";
			break;
		case 2:
			cards[index].label = "3";
			cards[index].optionOne = "Move one of your pawns forward three spaces.";
			cards[index].optionTwo = "n/a";
			break;
		case 3:
			cards[index].label = "4";
			cards[index].optionOne = "Move one of your pawns backward four spaces.";
			cards[index].optionTwo = "n/a";
			break;
		case 4:
			cards[index].label = "5";
			cards[index].optionOne = "Move one of your pawns forward five spaces.";
			cards[index].optionTwo = "n/a";
			break;
		case 5:
			cards[index].label = "7";
			cards[index].optionOne = "Move one of your pawns forward seven spaces.";
			cards[index].optionTwo = "split the forward move between two of your pawns.";
			break;
		case 6:
			cards[index].label = "8";
			cards[index].optionOne = "Move one of your pawns forward eight spaces.";
			cards[index].optionTwo = "n/a";
			break;
		case 7:
			cards[index].label = "10";
			cards[index].optionOne = "Move one of your pawns forward ten spaces.";
			cards[index].optionTwo = "Move one of your pawns backward one space.";
			break;
		case 8:
			cards[index].label = "11";
			cards[index].optionOne = "Move one of your pawns forward 11 spaces.";
			cards[index].optionTwo = "Switch any one of your pawns with an opponent's.";
			break;
		case 9:
			cards[index].label = "12";
			cards[index].optionOne = "Move one of your pawns forward 12 spaces.";
			cards[index].optionTwo = "n/a";
			break;
		case 10:
			cards[index].label = "SORRY!";
			cards[index].optionOne = "Move a pawn from your start area to take the place of another player's pawn, which must return to its own start area.";
			cards[index].optionTwo = "Move one of your pawns forward four spaces.";
			break;
		default:
			break;
		}
	}

	card* pDeck;
	pDeck = new card[numOfCards];
	int cardNum = 0;

	// Add cards to deck
	for (int index = 0; index < numOfCards; index++)
	{
		cardNum = 0;

		switch (index)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			cardNum = 0;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
			cardNum = 1;
			break;
		case 9:
		case 10:
		case 11:
		case 12:
			cardNum = 2;
			break;
		case 13:
		case 14:
		case 15:
		case 16:
			cardNum = 3;
			break;
		case 17:
		case 18:
		case 19:
		case 20:
			cardNum = 4;
			break;
		case 21:
		case 22:
		case 23:
		case 24:
			cardNum = 5;
			break;
		case 25:
		case 26:
		case 27:
		case 28:
			cardNum = 6;
			break;
		case 29:
		case 30:
		case 31:
		case 32:
			cardNum = 7;
			break;
		case 33:
		case 34:
		case 35:
		case 36:
			cardNum = 8;
			break;
		case 37:
		case 38:
		case 39:
		case 40:
			cardNum = 9;
			break;
		case 41:
		case 42:
		case 43:
		case 44:
			cardNum = 10;
			break;
		default:
			break;
		}

		pDeck[index] = cards[cardNum];
		cout << "Added " + pDeck[index].label + " card to deck." << endl;
	}

	printDeck(pDeck);

	shuffleDeck(pDeck);
	shuffleDeck(pDeck);
	shuffleDeck(pDeck);

	printDeck(pDeck);

	return 0;
}

// Print deck
void printDeck(card* deck)
{
	for (int index = 0; index < numOfCards; index++)
	{
		cout << deck[index].label << endl;
	}

	cout << endl;
}

// Shuffle deck
void shuffleDeck(card* deck)
{
	bool switched = false;

	int cardTrack[numOfCards];
	int randomCard = 0;

	card* pNewDeck;
	pNewDeck = new card[numOfCards];

	for (int index = 0; index < numOfCards; index++)
	{
		cardTrack[index] = 0;
	}

	for (int index = 0; index < numOfCards; index++)
	{
		switched = false;

		while (switched == false)
		{
			randomCard = rand() % numOfCards;

			if (cardTrack[randomCard] == 0)
			{
				switched = true;
				cardTrack[randomCard] = 1;
				pNewDeck[index] = deck[randomCard];
			}
		}
	}

	for (int index = 0; index < numOfCards; index++)
	{
		deck[index] = pNewDeck[index];
	}
}