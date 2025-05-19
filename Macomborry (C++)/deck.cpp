#include "deck.h"

void deck::setCards()
{
	// Set card values
	for (int index = 0; index < numOfCardTypes; index++)
	{
		switch (index)
		{
		case 0:
			cards[index].setLabel("1");
			cards[index].setOptionOne("Move one of your pawns forward one from START.");
			cards[index].setOptionTwo("If in play, move foward one space.");
			break;
		case 1:
			cards[index].setLabel("2");
			cards[index].setOptionOne("Move one of your pawns forward two from START.");
			cards[index].setOptionTwo("If in play, move foward two spaces.");
			break;
		case 2:
			cards[index].setLabel("3");
			cards[index].setOptionOne("Move one of your pawns forward three spaces.");
			cards[index].setOptionTwo("n/a");
			break;
		case 3:
			cards[index].setLabel("4");
			cards[index].setOptionOne("Move one of your pawns backward four spaces.");
			cards[index].setOptionTwo("n/a");
			break;
		case 4:
			cards[index].setLabel("5");
			cards[index].setOptionOne("Move one of your pawns forward five spaces.");
			cards[index].setOptionTwo("n/a");
			break;
		case 5:
			cards[index].setLabel("7");
			cards[index].setOptionOne("Move one of your pawns forward seven spaces.");
			cards[index].setOptionTwo("Split the forward move between two of your pawns.");
			break;
		case 6:
			cards[index].setLabel("8");
			cards[index].setOptionOne("Move one of your pawns forward eight spaces.");
			cards[index].setOptionTwo("n/a");
			break;
		case 7:
			cards[index].setLabel("10");
			cards[index].setOptionOne("Move one of your pawns forward ten spaces.");
			cards[index].setOptionTwo("Move one of your pawns backward one space.");
			break;
		case 8:
			cards[index].setLabel("11");
			cards[index].setOptionOne("Move one of your pawns forward 11 spaces.");
			cards[index].setOptionTwo("Switch any one of your pawns with an opponent's.");
			break;
		case 9:
			cards[index].setLabel("12");
			cards[index].setOptionOne("Move one of your pawns forward 12 spaces.");
			cards[index].setOptionTwo("n/a");
			break;
		case 10:
			cards[index].setLabel("SORRY!");
			cards[index].setOptionOne("Move a pawn from your start area to take the place of another player's pawn, which must return to its own start area.");
			cards[index].setOptionTwo("Move one of your pawns forward four spaces.");
			break;
		default:
			break;
		}
	}
}

card deck::getCard(int cardNum)
{
	return pDeck[cardNum];
}

// Create deck
void deck::initializeDeck()
{
	pDeck = new card[numOfCards];
	int cardNum = 0;

	for (int index = 0; index < numOfCards; index++)
	{
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

		pDeck[index].setLabel(cards[cardNum].getLabel());
		pDeck[index].setOptionOne(cards[cardNum].getOptionOne());
		pDeck[index].setOptionTwo(cards[cardNum].getOptionTwo());

		//cout << "Added " + pDeck[index].getLabel() + " card to deck." << endl;
	}
}

// Print deck
void deck::printDeck() const
{
	for (int index = 0; index < numOfCards; index++)
	{
		cout << pDeck[index].getLabel() << endl;
	}

	cout << endl;
}

// Shuffle deck
void deck::shuffleDeck()
{
	bool switched = false;

	int randomCard = 0;
	int cardTrack[numOfCards];

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
				pNewDeck[index] = pDeck[randomCard];
			}
		}
	}

	for (int index = 0; index < numOfCards; index++)
	{
		pDeck[index].setLabel(pNewDeck[index].getLabel());
		pDeck[index].setOptionOne(pNewDeck[index].getOptionOne());
		pDeck[index].setOptionTwo(pNewDeck[index].getOptionTwo());
	}

	delete[] pNewDeck;
}

// Constructor
deck::deck()
{
	setCards();
	initializeDeck();
}

deck::~deck()
{
	delete[] pDeck;
}
