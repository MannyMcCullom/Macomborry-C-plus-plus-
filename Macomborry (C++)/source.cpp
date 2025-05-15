/*
Sorry Video game
//*/

#include <iostream>

const int numOfCardTypes = 11;
const int numOfCards = 45;

using namespace std;

struct card {
	string label;
	string optionOne;
	string optionTwo;
};

int main()
{
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

	card deck[numOfCards];
	int cardNum = 0;

	// Add cards to deck
	for (int index = 0; index < numOfCards; index++)
	{
		switch (index)
		{
		case 4:
			cardNum = 0;
			cout << "Added 5 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 8:
			cardNum = 1;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 12:
			cardNum = 2;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 16:
			cardNum = 3;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 20:
			cardNum = 4;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 24:
			cardNum = 5;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 28:
			cardNum = 6;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 32:
			cardNum = 7;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 36:
			cardNum = 8;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 40:
			cardNum = 9;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		case 44:
			cardNum = 10;
			cout << "Added 4 " + cards[cardNum].label + " cards to deck." << endl;
			break;
		default:
			break;
		}
	}

	// Shuffle cards

	return 0;
}