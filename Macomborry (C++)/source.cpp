/*
Sorry Video game
//*/

#include <iostream>
#include <cstdlib>

#include "deck.h"

using namespace std;

int main()
{
	srand(time(0));

	deck deck1;

	deck1.printDeck();

	deck1.shuffleDeck();
	
	deck1.printDeck();

	return 0;
}