#ifndef H_deck
#define H_deck

#include <iostream>

#include "card.h"

using namespace std;

const int numOfCardTypes = 11;
const int numOfCards = 45;

class deck
{
public:
	void setCards();

	card getCard(int);

	void initializeDeck();
	void printDeck() const;
	void shuffleDeck();

	deck();
	~deck();

private:
	card cards[numOfCardTypes];
	card* pDeck;
};

#endif