#include "pawn.h"

pawn pawn::operator=(pawn other)
{
	pawn newPawn;
	newPawn.atHome = other.atHome;
	newPawn.atStart = other.atStart;
	newPawn.inSafeZone = other.inSafeZone;
	newPawn.boardPosition = other.boardPosition;
	newPawn.safeZonePosition - other.safeZonePosition;
	return newPawn;
}

void pawn::setBoardPosition(int pos)
{
	boardPosition = pos;
}

void pawn::setSafeZonePosition(int pos)
{
	safeZonePosition = pos;
}

void pawn::setAtStart(bool binary)
{
	atStart = binary;
}

void pawn::setInSafeZone(bool binary)
{
	inSafeZone = binary;
}

void pawn::setAtHome(bool binary)
{
	atHome = binary;
}

int pawn::getBoardPostition() const
{
	return boardPosition;
}

int pawn::getSafeZonePostition() const
{
	return safeZonePosition;
}

bool pawn::getAtStart() const
{
	return atStart;
}

bool pawn::getInSafeZone() const
{
	return inSafeZone;
}

bool pawn::getAtHome() const
{
	return atHome;
}

void pawn::resetPawn()
{
	setBoardPosition(-1);
	setSafeZonePosition(-1);
	setAtStart(true);
	setInSafeZone(false);
	setAtHome(false);
}

pawn::pawn()
{
	resetPawn();
}