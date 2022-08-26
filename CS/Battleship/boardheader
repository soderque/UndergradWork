#ifndef BBOARD_H
#define BBOARD_H
#include "Ship.hpp"

class BBoard
{
	private:
		bool board[10][10];
		Ship* shiparr[10][10];
		int checksink;
	public:
		BBoard();
		BBoard(bool pBoard[10][10], Ship* pShiparr[10][10]);
		bool getAttacksArrayElement(int r, int c);
		Ship* getShipsArrayElement(int r, int c);
		int getNumShipsRemaining();
		bool placeShip(Ship *shipAdd, int r, int c, char ORI);
		bool attack(int r, int c);
		bool allShipsSunk();
};

#endif
