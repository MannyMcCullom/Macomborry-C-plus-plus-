#ifndef H_gameManager
#define H_gameManager

#include <iostream>
#include <string>

#include "player.h"
#include "deck.h"

using namespace std;

const int MAX_NUM_OF_PLAYERS = 4;
const int MAX_NUM_OF_PAWNS = 4;
const int BOARD_SPACES = 60;
const int SAFE_ZONE_SPACES = 60;
const int NUM_OF_SLIDE_POSITIONS = 8;

class gameManager
{
public:
	void skipLines(int num);
	void longLine();
	void printTempMessage();
	void selectionCheck(int& selection, int numOfSelections);
	void selectionControlVertical(string response, bool& exit, int& selection, int numOfSelections);
	void displayOptions(string selections[], int selection, int numOfSelections);

	void setCurrentPlayer(int);
	void setNumberOfPlayers(int);

	int getCurrentPlayer() const;
	int getNumberOfPlayers() const;
	int getPositionStart(int) const;
	int getPositionHome(int) const;
	int getPositionSlide(int) const;

	// Menus
	void menuStart();

	// Game Functions
	void playGame();
	void chooseColors();
	void promptPlay();
	void makeChoice(card);
	void optionOne(string cardLabel);
	void optionTwo(string cardLabel);
	void forefeitTurn(string cardLabel);
	void pawnStatus(int);
	void checkPositionForOwnPawn(bool&, pawn);
	void takeOverPosition();
	void selectPawn();
	void movePawnForward(int);
	void startGame();

	// Constructor
	gameManager();

private:
	string tempMessage;

	void setPositionStart();
	void setPositionHome();
	void setPositionSlide();
	void resetPawns();
	void setBoard();
	void setGame();

	player player[MAX_NUM_OF_PLAYERS];
	deck gameDeck;

	int currentPlayer;
	int currentPawn;
	int numOfPlayers;
	int spacesLeftToMove;
	bool choiceMade;

	int positionStart[MAX_NUM_OF_PLAYERS];
	int positionHome[MAX_NUM_OF_PLAYERS];
	int positionSlide[NUM_OF_SLIDE_POSITIONS];
};

#endif