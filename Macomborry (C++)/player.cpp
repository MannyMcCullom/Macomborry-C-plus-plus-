#include "player.h"

void player::setColor(string newColor)
{
	color = newColor;
}

void player::setPositionStart(int pos)
{
	positionStart = pos;
}

void player::setPositionHome(int pos)
{
	positionHome = pos;
}

pawn& player::getPawn(int index)
{
	return playerPawn[index];
}

string player::getColor() const
{
	return color;
}

int player::getPositionStart() const
{
	return positionStart;
}

int player::getPositionHome() const
{
	return positionHome;
}

void player::resetPlayer()
{
	setColor("");
	setPositionStart(0);
	setPositionHome(0);
}

player::player()
{
	resetPlayer();
}
