* Description: This program (including all other class files such as Ship.cpp and Ship.hpp) provides the class objects necessary to play a game of Battleship.
 * ********************************************************************************************************************************************************************/

#include <iostream>
#include "Ship.hpp"
#include "BBoard.hpp"

using std::cin;
using std::cout;
using std::endl;

BBoard::BBoard() // Default Constructor.
{
	for(int i = 0; i < 10; i++) // Initializes boolean array to false.
	{
		for(int j = 0; j < 10; j++)	
		{
			board[i][j] = false;
		}
	}

	for(int i = 0; i < 10; i++) // Initializes pointer array to null.
	{
		for(int j = 0; j < 10; j++)	
		{
			shiparr[i][j] = NULL;
		}
	}
	checksink = 0;
}

BBoard::BBoard(bool pBoard[10][10], Ship* pShiparr[10][10]) // Nondefault constructor (Just in case)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)	
		{
			pBoard[i][j] = false;
		}
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)	
		{
			pShiparr[i][j] = NULL;
		}
	}
	checksink = 0;
}

bool BBoard::getAttacksArrayElement(int r, int c)
{
	return board[r][c];
}

Ship* BBoard::getShipsArrayElement(int r, int c)
{
	return shiparr[r][c];
}

int BBoard::getNumShipsRemaining()
{
	return checksink;
}

bool BBoard::placeShip(Ship *shipAdd, int r, int c, char ORI)
{
	bool placed = false;
	bool shipSpaceTaken = false;
	while(placed == false) // While the ship has not been placed
	{
		if(ORI == 'r' || ORI == 'R') // If the orientation of the ship is rowwise:
		{
			for(int j = 0; j < shipAdd->Ship::getLength(); j++) // Checks if the placement will overlap another ship
			{
				if(shiparr[r][c+j] == NULL)
					shipSpaceTaken = false;
				else
				{
					shipSpaceTaken = true;
					break;
				}
			}
			if(shipSpaceTaken == false) // If there is no other ship in the way:
			{
				for(int i = 0; i < shipAdd->Ship::getLength(); i++)
				{
					shiparr[r][c+i] = shipAdd;
					placed = true; // Ship has been placed.
				}
				checksink++; // Ship count increased by one.
				return true;
			}
			else // There is a ship already and it cannot be placed.
				return false;
		}
		else if(ORI == 'c' || ORI == 'C') // If the orientation of the ship is columnwise:
		{
			for(int j = 0; j < shipAdd->Ship::getLength(); j++) // Checks if the placement will overlap another ship
			{
				if(shiparr[r+j][c] == NULL)
					shipSpaceTaken = false;
				else
				{
					shipSpaceTaken = true;
					break;
				}
			}
			if(shipSpaceTaken == false) // If there is no other ship in the way:
			{
				for(int i = 0; i < shipAdd->Ship::getLength(); i++)
				{
					shiparr[r+i][c] = shipAdd;
					placed = true; // Ship has been placed.
				}
				checksink++; // Ship count increased by one.
				return true;
			}
			else // There is a ship already and it cannot be placed.
				return false;
		}
	}
}

bool BBoard::attack(int r, int c)
{
	if(board[r][c] == true) // If the square has already been hit:
		board[r][c] = true;
	else if(board[r][c] == false) // If the square is fresh:
	{
		board[r][c] = true;
		if(shiparr[r][c] != NULL) // If there is a ship placed in the array:
		{
			shiparr[r][c]->Ship::takeHit();
			if(shiparr[r][c]->Ship::getDamage() == shiparr[r][c]->Ship::getLength()) // If the ship length is equal to the damage (every square possible has been hit):
			{
				cout << "They sank " << shiparr[r][c]->Ship::getName() << " !" << endl;
				checksink--; // Total number of ships on the board goes down by one.
			}
			else
				return true;
		}
		else
			return false;
	}
}

bool BBoard::allShipsSunk()
{
	if(BBoard::getNumShipsRemaining() == 0) // If checksink is equal to 0
		return true;
	else
	{
		return false;
	}
}
