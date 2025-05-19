#ifndef H_player
#define H_player

#include <iostream>

#include "pawn.h"

using namespace std;

const int NO_OF_PAWNS = 4;

class player
{
public:
	void setColor(string);
	void setPositionStart(int);
	void setPositionHome(int);

	pawn& getPawn(int);
	string getColor() const;
	int getPositionStart() const;
	int getPositionHome() const;

	void resetPlayer();

	player();

private:
	pawn playerPawn[NO_OF_PAWNS];
	string color;
	int positionStart;
	int positionHome;
};

#endif