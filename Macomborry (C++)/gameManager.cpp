#include "gameManager.h"

void gameManager::printTempMessage()
{
	longLine();
	cout << tempMessage << endl;

	tempMessage = "";
}

void gameManager::longLine()
{
	cout << "----------------------------------------" << endl;
}

void gameManager::skipLines(int num)
{
#ifdef _WIN32
	system("cls");

#else
	for (int index = 0; index < num; index++)
		cout << endl;

#endif
}

void gameManager::selectionCheck(int& selection, int numOfSelections)
{
	if (selection < 0)
		selection = numOfSelections - 1;

	else if (selection >= numOfSelections)
		selection = 0;
}

void gameManager::selectionControlVertical(string response, bool& exit, int& selection, int numOfSelections)
{
	if (toupper(response[0]) == 'Q')
		exit = true;

	else if (toupper(response[0]) == 'W')
		selection--;

	else if (toupper(response[0]) == 'S')
		selection++;

	selectionCheck(selection, numOfSelections);
}

void gameManager::displayOptions(string selections[], int selection, int numOfSelections)
{
	longLine();

	for (int index = 0; index < numOfSelections; index++)
	{
		if (index == selection)
			cout << '[' << selections[index] << ']' << endl;

		else
			cout << ' ' << selections[index] << ' ' << endl;
	}
}

void gameManager::setCurrentPlayer(int num)
{
	currentPlayer = num;
}

void gameManager::setNumberOfPlayers(int num)
{
	numOfPlayers = num;
}

int gameManager::getCurrentPlayer() const
{
	return currentPlayer;
}

int gameManager::getNumberOfPlayers() const
{
	return numOfPlayers;
}

int gameManager::getPositionStart(int index) const
{
	return positionStart[index];
}

int gameManager::getPositionHome(int index) const
{
	return positionHome[index];
}

int gameManager::getPositionSlide(int index) const
{
	return positionSlide[index];
}

void gameManager::setPositionStart()
{
	int position = 0;

	for (int index = 0; index < MAX_NUM_OF_PLAYERS; index++)
	{
		switch (index)
		{
		case 0:
			position = 0;
			break;
		case 1:
			position = 15;
			break;
		case 2:
			position = 31;
			break;
		case 3:
			position = 46;
			break;
		}

		positionStart[index] = position;
		player[index].setPositionStart(position);
	}
}

void gameManager::setPositionHome()
{
	int position = 0;

	for (int index = 0; index < MAX_NUM_OF_PLAYERS; index++)
	{
		switch (index)
		{
		case 0:
			position = 59;
			break;
		case 1:
			position = 13;
			break;
		case 2:
			position = 29;
			break;
		case 3:
			position = 44;
			break;
		}

		positionHome[index] = position;
		player[index].setPositionHome(position);
	}
}

void gameManager::resetPawns()
{
	for (int index = 0; index < MAX_NUM_OF_PLAYERS; index++)
	{
		for (int index1 = 0; index1 < MAX_NUM_OF_PAWNS; index1++)
		{
			player[index].getPawn(index1).setBoardPosition(player[index].getPositionStart());
		}
	}
}

void gameManager::setPositionSlide()
{
	int position = 0;

	for (int index = 0; index < NUM_OF_SLIDE_POSITIONS; index++)
	{
		switch (index)
		{
		case 0:
			position = 58;
			break;
		case 1:
			position = 5;
			break;
		case 2:
			position = 12;
			break;
		case 3:
			position = 20;
			break;
		case 4:
			position = 27;
			break;
		case 5:
			position = 35;
			break;
		case 6:
			position = 42;
			break;
		case 7:
			position = 50;
			break;
		}

		positionSlide[index] = position;
	}
}

void gameManager::setBoard()
{
	setPositionSlide();
	setPositionStart();
	setPositionHome();
	resetPawns();
}

void gameManager::setGame()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 4;
	string selections[numOfSelections] = { "2", "3", "4", "EXIT"};

	// Choose Number of players
	//int numOfPlayers = 0;
	setNumberOfPlayers(0);

	while (exit == false)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "How many players are playing?" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		selectionControlVertical(response, exit, selection, numOfSelections);

		if (toupper(response[0]) == 'E')
		{
			// Action
			switch (selection)
			{
			case 0:
				setNumberOfPlayers(2);
				break;
			case 1:
				setNumberOfPlayers(3);
				break;
			case 2:
				setNumberOfPlayers(4);
				break;
			case 3:
				exit = true;
				break;
			}

			if (selection != 3)
			{
				tempMessage = "Number of players is: " + to_string(numOfPlayers) + "\n";
				chooseColors();
				exit = true;
			}

			//playGame();
		}

		// 
		// Play game
	}
}

// Menus
void gameManager::menuStart()
{
	string response;
	bool exit = false;

	while (exit == false)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Macomborry" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to play game"
			<< endl
			<< "q to EXIT"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'E')
		{
			playGame();
		}
	}
}

void gameManager::playGame()
{
	setGame();
}

void gameManager::chooseColors()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 5;
	string selections[numOfSelections] = { "Blue", "Yellow", "Green", "Red", "EXIT" };

	string color = "";
	currentPlayer = 0;

	while (exit == false)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Color" << endl;

		tempMessage += "Please choose a color for Player " + to_string(currentPlayer + 1) + "\n";

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		selectionControlVertical(response, exit, selection, numOfSelections);

		if (toupper(response[0]) == 'E')
		{
			// Action
			switch (selection)
			{
			case 0:
				color = "Blue";
				break;
			case 1:
				color = "Yellow";
				break;
			case 2:
				color = "Green";
				break;
			case 3:
				color = "Red";
				break;
			case 4:
				exit = true;
				break;
			}

			if (selection != 4)
			{
				bool good = true;

				for (int index = 0; index < MAX_NUM_OF_PLAYERS; index++)
				{
					if (color == player[index].getColor())
					{
						good = false;
						tempMessage = "Player " + to_string(index + 1) + "'s Color is " + color + "\n";
						break;
					}
				}

				if (good == true)
				{
					tempMessage = "Player " + to_string(currentPlayer + 1) + "'s Color is " + color + "\n";
					player[currentPlayer].setColor(color);
					currentPlayer++;
				}
			}

			if (currentPlayer >= getNumberOfPlayers())
			{
				exit = true;
				startGame();
			}
		}
	}
}

void gameManager::promptPlay()
{

}

void gameManager::makeChoice(card drawnCard)
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 3;

	choiceMade = false;

	string selections[numOfSelections];
	selections[0] = drawnCard.getOptionOne();
	selections[1] = drawnCard.getOptionTwo();
	selections[2] = "Do Nothing";

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Card Drawn: " + drawnCard.getLabel() << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		selectionControlVertical(response, exit, selection, numOfSelections);

		if (toupper(response[0]) == 'E')
		{
			// action
			switch (selection)
			{
			case 0:
				tempMessage += "Selected Option 1\n";
				optionOne(drawnCard.getLabel());
				break;
			case 1:
				optionTwo(drawnCard.getLabel());
				break;
			case 2:
				forefeitTurn(drawnCard.getLabel());
				break;
			}
		}

		if (choiceMade == true)
		{
			exit = true;
		}
	}
}

void gameManager::optionOne(string cardLabel)
{
	bool moveComplete = false;
	bool validMove = true;
	pawn tempPawn;

	while (moveComplete == false)
	{
		currentPawn = -1;
		selectPawn();
		tempPawn = player[currentPlayer].getPawn(currentPawn);

		if (currentPawn >= 0)
		{
			if (cardLabel == "1")
			{
				// Move one of your pawns forward one from START
				if (player[currentPlayer].getPawn(currentPawn).getAtHome() == false)
				{
					if (player[currentPlayer].getPawn(currentPawn).getAtStart() == true)
					{
						player[currentPlayer].getPawn(currentPawn).setAtStart(false);
					}
					else
					{
						validMove = false;
						tempMessage += "Can't make move\n";
						tempMessage += "REASON: Pawn is not at Start\n";
					}
				}
				else
				{
					validMove = false;
					tempMessage += "Can't make move\n";
					tempMessage += "REASON: Pawn is at Home\n";
				}
			}
			else if (cardLabel == "2")
			{

			}
			else if (cardLabel == "3")
			{

			}
			else if (cardLabel == "4")
			{

			}
			else if (cardLabel == "5")
			{

			}
			else if (cardLabel == "7")
			{

			}
			else if (cardLabel == "8")
			{

			}
			else if (cardLabel == "10")
			{

			}
			else if (cardLabel == "11")
			{

			}
			else if (cardLabel == "12")
			{

			}
			else if (cardLabel == "SORRY!")
			{

			}

			if (validMove)
			{
				checkPositionForOwnPawn(validMove, tempPawn);
			}

			if (validMove)
			{
				tempMessage += "Valid Move!!!\n";
				choiceMade = true;
				moveComplete = true;

				takeOverPosition();
			}
		}

		if (currentPawn == -1)
		{
			break;
		}
	}
}

void gameManager::optionTwo(string cardLabel)
{
	bool moveComplete = false;
	bool validMove = true;
	pawn tempPawn;

	while (moveComplete == false)
	{
		currentPawn = -1;
		selectPawn();
		tempPawn = player[currentPlayer].getPawn(currentPawn);

		if (currentPawn >= 0)
		{
			if (cardLabel == "1")
			{
				// If in play, move foward one space.
				if (player[currentPlayer].getPawn(currentPawn).getAtHome() == false)
				{
					if (player[currentPlayer].getPawn(currentPawn).getAtStart() == false)
					{
						movePawnForward(1);
					}
					else
					{
						validMove = false;
						tempMessage += "Can't make move\n";
						tempMessage += "REASON: Pawn is at Start\n";
					}
				}
				else
				{
					validMove = false;
					tempMessage += "Can't make move\n";
					tempMessage += "REASON: Pawn is at Home\n";
				}

				if (validMove)
				{

				}
			}
			else if (cardLabel == "2")
			{

			}
			else if (cardLabel == "3")
			{

			}
			else if (cardLabel == "4")
			{

			}
			else if (cardLabel == "5")
			{

			}
			else if (cardLabel == "7")
			{

			}
			else if (cardLabel == "8")
			{

			}
			else if (cardLabel == "10")
			{

			}
			else if (cardLabel == "11")
			{

			}
			else if (cardLabel == "12")
			{

			}
			else if (cardLabel == "SORRY!")
			{

			}

			//if (player[currentPlayer].getPawn(currentPawn).)
			checkPositionForOwnPawn(validMove, tempPawn);

			if (validMove)
			{
				tempMessage += "Valid Move!!!\n";
				choiceMade = true;
				moveComplete = true;

				takeOverPosition();
			}
		}

		if (currentPawn == -1)
		{
			break;
		}
	}
}

void gameManager::forefeitTurn(string cardLabel)
{
	if (cardLabel == "1")
	{

	}
	else if (cardLabel == "2")
	{

	}
	else if (cardLabel == "3")
	{

	}
	else if (cardLabel == "4")
	{

	}
	else if (cardLabel == "5")
	{

	}
	else if (cardLabel == "7")
	{

	}
	else if (cardLabel == "8")
	{

	}
	else if (cardLabel == "10")
	{

	}
	else if (cardLabel == "11")
	{

	}
	else if (cardLabel == "12")
	{

	}
	else if (cardLabel == "SORRY!")
	{

	}
}

void gameManager::pawnStatus(int selection)
{
	tempMessage += "Player Color: ";
	tempMessage += player[currentPlayer].getColor();
	tempMessage += "\n";

	tempMessage += "Pawn: ";
	tempMessage += to_string(selection + 1);
	tempMessage += "\n";

	tempMessage += "At Start: ";
	tempMessage += player[currentPlayer].getPawn(selection).getAtStart() == true ? "true" : "false";
	tempMessage += "\n";

	tempMessage += "In Safe Zone: ";
	tempMessage += player[currentPlayer].getPawn(selection).getInSafeZone() == true ? "true" : "false";
	tempMessage += "\n";

	tempMessage += "At Home: ";
	tempMessage += player[currentPlayer].getPawn(selection).getAtHome() == true ? "true" : "false";
	tempMessage += "\n";

	tempMessage += "Board Position: ";
	tempMessage += to_string(player[currentPlayer].getPawn(selection).getBoardPostition());
	tempMessage += "\n";

	tempMessage += "Safe Zone Position: ";
	tempMessage += to_string(player[currentPlayer].getPawn(selection).getSafeZonePostition());
	tempMessage += "\n";
}

void gameManager::checkPositionForOwnPawn(bool& validMove, pawn tempPawn)
{
	for (int index = 0; index < MAX_NUM_OF_PAWNS; index++)
	{
		if (index != currentPawn)
		{
			if (player[currentPlayer].getPawn(index).getAtHome() == false
				&& player[currentPlayer].getPawn(index).getAtStart() == false)
			{
				if (player[currentPlayer].getPawn(index).getBoardPostition() == player[currentPlayer].getPawn(currentPawn).getBoardPostition())
				{
					if (player[currentPlayer].getPawn(index).getInSafeZone() == false
						&& player[currentPlayer].getPawn(currentPawn).getInSafeZone() == false)
					{
						validMove = false;
						player[currentPlayer].getPawn(currentPawn) = tempPawn;
						tempMessage += "Can't make move\n";
						tempMessage += "REASON: End space occupied by player's pawn.\n";
						break;
					}
					else if (player[currentPlayer].getPawn(index).getInSafeZone() == true
						&& player[currentPlayer].getPawn(currentPawn).getInSafeZone() == true)
					{
						if (player[currentPlayer].getPawn(index).getSafeZonePostition() == player[currentPlayer].getPawn(currentPawn).getSafeZonePostition())
						{
							validMove = false;
							player[currentPlayer].getPawn(currentPawn) = tempPawn;
							tempMessage += "Can't make move\n";
							tempMessage += "REASON: End space occupied by player's pawn.\n";
							break;
						}
					}
				}
			}
		}
	}
}

void gameManager::takeOverPosition()
{
	for (int index = 0; index < MAX_NUM_OF_PLAYERS; index++)
	{
		if (index != currentPlayer)
		{
			for (int index1 = 0; index1 < MAX_NUM_OF_PAWNS; index1++)
			{
				if (player[index].getPawn(index1).getAtHome() == false
					&& player[index].getPawn(index1).getAtStart() == false
					&& player[index].getPawn(index1).getInSafeZone() == false
					&& player[index].getPawn(index1).getBoardPostition() == player[currentPlayer].getPawn(currentPawn).getBoardPostition())
				{
					tempMessage += "Bumped Player " + to_string(index + 1) + "'s Pawn " + to_string(index1 + 1) + " Back to Start";
					player[index].getPawn(index1).setAtStart(true);
					player[index].getPawn(index1).setBoardPosition(positionStart[index]);
				}
			}
		}
	}
}

void gameManager::selectPawn()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 4;

	string selections[numOfSelections] = { "Pawn 1", "Pawn 2", "Pawn 3", "Pawn 4" };

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Select Pawn: " << endl;

		pawnStatus(selection);

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		selectionControlVertical(response, exit, selection, numOfSelections);

		if (toupper(response[0]) == 'E')
		{
			// action
			switch (selection)
			{
			case 0:
				currentPawn = 0;
				break;
			case 1:
				currentPawn = 1;
				break;
			case 2:
				currentPawn = 2;
				break;
			case 3:
				currentPawn = 3;
				break;
			}

			exit = true;
		}

		if (toupper(response[0]) == 'Q')
		{
			currentPawn = -1;
		}
	}
}

void gameManager::movePawnForward(int numOfSpaces)
{
	while (numOfSpaces != 0)
	{
		if (player[currentPlayer].getPawn(currentPawn).getBoardPostition() == positionHome[currentPlayer])
		{
			if (player[currentPlayer].getPawn(currentPawn).getInSafeZone() == false)
			{
				player[currentPlayer].getPawn(currentPawn).setInSafeZone(true);
				player[currentPlayer].getPawn(currentPawn).setSafeZonePosition(0);
			}
			else
			{
				player[currentPlayer].getPawn(currentPawn).setSafeZonePosition(player[currentPlayer].getPawn(currentPawn).getSafeZonePostition() + 1);

				if (player[currentPlayer].getPawn(currentPawn).getSafeZonePostition() >= SAFE_ZONE_SPACES)
				{
					player[currentPlayer].getPawn(currentPawn).setAtHome(true);
				}
			}
		}
		else
		{
			player[currentPlayer].getPawn(currentPawn).setBoardPosition(player[currentPlayer].getPawn(currentPawn).getBoardPostition() + 1);

			if (player[currentPlayer].getPawn(currentPawn).getBoardPostition() > BOARD_SPACES)
			{
				player[currentPlayer].getPawn(currentPawn).setBoardPosition(0);
			}
		}

		numOfSpaces--;
	}
}

void gameManager::startGame()
{
	bool gameOver = false;
	int currentCard = 0;
	gameDeck.shuffleDeck();

	while (gameOver == false)
	{
		for (currentPlayer = 0; currentPlayer < numOfPlayers; currentPlayer++)
		{
			if (currentCard <= numOfCards)
			{
				gameDeck.getCard(currentCard);
				makeChoice(gameDeck.getCard(currentCard));
				currentCard++;
			}

			else
			{
				gameDeck.shuffleDeck();
				currentCard = 0;
			}
		}
	}
}

gameManager::gameManager()
{
	spacesLeftToMove = 0;
	choiceMade = false;
	currentPawn = -1;
	setCurrentPlayer(0);
	setBoard();
	menuStart();
}
