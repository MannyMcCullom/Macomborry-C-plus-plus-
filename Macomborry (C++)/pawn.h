#ifndef H_pawn
#define H_pawn

#include <iostream>

using namespace std;

class pawn
{
public:
	pawn operator=(pawn);
	void setBoardPosition(int);
	void setSafeZonePosition(int);
	void setAtStart(bool);
	void setInSafeZone(bool);
	void setAtHome(bool);

	int getBoardPostition() const;
	int getSafeZonePostition() const;
	bool getAtStart() const;
	bool getInSafeZone() const;
	bool getAtHome() const;

	void resetPawn();

	pawn();

private:
	int boardPosition;
	int safeZonePosition;
	bool atStart;
	bool inSafeZone;
	bool atHome;
};

#endif