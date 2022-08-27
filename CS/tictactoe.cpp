 * Description: This program plays a version of tic tac toe, where the player places a pieces each turn and moves it to an adjacent spaces until they reach 3 in a row.
 * ********************************************************************************************************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void boardPrint(char[][3]);  // Prototypes: Function headers are found at the function definitions

int winCondition(char[][3]);

void placePieceO(char[][3], int);

void placePieceX(char[][3]);

void movePieceO(char[][3]);

void movePieceX(char[][3]);

int main()
{
	int turn;
	int win = 0;
	char board[3][3];
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{	
			board[i][j]='.';
		}
	}
	turn = 1;
	while (win == 0) // Basic win condition: The game will continue while int win does not change.
	{
		while (turn <= 6 && win == 0) // Basic piece placement: 6 turns between 2 players equals 3 pieces to place each. Then, piece movement begins.
		{
			if (turn%2 == 1) // Player 1 is odd turn, Player 2 is even turn.
			{
				boardPrint(board);
				placePieceO(board, turn);
				win = winCondition(board); // If win condition is not met, int win does not change and the game continues.
				turn++;
			}
			else
			{
				boardPrint(board);
				placePieceX(board);
				win = winCondition(board);
				turn++;
			}
		}
		if (turn%2 == 1 && win == 0)
		{
			boardPrint(board);
			movePieceO(board);
			win = winCondition(board);
			turn++;
		}
		else if (win == 0)
		{
			boardPrint(board);
			movePieceX(board);
			win = winCondition(board);
			turn++;
		}
	}
	boardPrint(board); // Win has been changed to either 1 or 2 by function winCondition; and the game loop has broken.
	if (win == 1)
		cout << "Congratulations Player 1, you win!" << endl;
	else
		cout << "Congratulations Player 2, you win!" << endl;
	return 0;
}

/***********************************************************************************************************************************************************************
 * Description: This function prints the current board by taking the board parameter and displaying each element in a 'grid' fashion.
 * ********************************************************************************************************************************************************************/
void boardPrint(char print[][3])
{
	cout << "  0 1 2" << endl;
	for (int n=0; n<3; n++)
	{
		cout << n << " " << print[n][0] << " " << print[n][1] << " " << print[n][2];
		cout << endl;
	}
}

/***********************************************************************************************************************************************************************
 * Description: This function checks win conditions and the check is performed after each move in the game. Every possible win condition is listed below.
 [NOTE: In the game prompt, players are not allowed to move their pieces from the midpoint of any outer edge to the midpoint of an adjacent outer edge. The complete set
 of illegal moves makes the shape of a diamond on the board.]
 * ********************************************************************************************************************************************************************/
int winCondition(char board[][3])
{
	if ((board[0][0]==board[0][1]&&board[0][1]==board[0][2]&&board[0][2]=='o')||(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='o')||(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='o')||(board[1][0]==board[1][1]&&board[1][1]==board[1][2]&&board[1][2]=='o')||(board[2][0]==board[2][1]&&board[2][1]==board[2][2]&&board[2][2]=='o'))
		return 1;
	else if ((board[0][0]==board[1][0]&&board[1][0]==board[2][0]&&board[2][0]=='o')||(board[0][1]==board[1][1]&&board[1][1]==board[2][1]&&board[2][1]=='o')||(board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[2][2]=='o'))
		return 1;
	else if ((board[0][0]==board[0][1]&&board[0][1]==board[0][2]&&board[0][2]=='x')||(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='x')||(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='x')||(board[1][0]==board[1][1]&&board[1][1]==board[1][2]&&board[1][2]=='x')||(board[2][0]==board[2][1]&&board[2][1]==board[2][2]&&board[2][2]=='x'))
		return 2;
 	else if ((board[0][0]==board[1][0]&&board[1][0]==board[2][0]&&board[2][0]=='x')||(board[0][1]==board[1][1]&&board[1][1]==board[2][1]&&board[2][1]=='x')||(board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[2][2]=='x'))
		return 2;
	else
		return 0;
}

/***********************************************************************************************************************************************************************
 * Description: This function places a piece for Player 1 and checks all conditions to make sure it's a legal move.
 * ********************************************************************************************************************************************************************/
void placePieceO(char board[][3], int turn)
{
	int c, r;
	char retry = 'y';
	while (retry == 'y')
	{
		cout << "Player 1, please pick a column: ";
		cin >> c;
		if (c < 0 || c > 2)
			cout << "Invalid: Off the grid. Please try again." << endl;
		else
		{
			cout << "Now please pick a row: ";
			cin >> r;
			if (r < 0 || r > 2)
				cout << "Invalid: Off the grid. Please try again." << endl;
			else if (r==1&&c==1&&turn==1)
				cout << "Invalid: Cannot take the center of the board as the first move of the game. Please try again." << endl;
			else
			{
				if (board[r][c] == '.')
				{
					board[r][c] = 'o';
					retry = 'n';
				}
				else
				cout << "Invalid: Another piece is already there. Please try again." << endl;
			}		
		} 
	}
}

/***********************************************************************************************************************************************************************
 * Description: This function, like above, places a piece but for Player 2 and checks conditions to make sure it's a completely legal move.
 * ********************************************************************************************************************************************************************/
void placePieceX(char board[][3])
{
	int c, r;
	char retry = 'y';
	while (retry == 'y')
	{
		cout << "Player 2, please pick a column: ";
		cin >> c;
		if (c < 0 || c > 2)
			cout << "Invalid: Off the grid. Please try again." << endl;
		else
		{
			cout << "Now please pick a row: ";
			cin >> r;
			if (r < 0 || r > 2)
				cout << "Invalid: Off the grid. Please try again." << endl;
			else
			{
				if (board[r][c] == '.')
				{
					board[r][c] = 'x';
					retry = 'n';
				}
			else
			cout << "Invalid: Another piece is already there. Please try again." << endl;
			}
		}
	}
}
/***********************************************************************************************************************************************************************
 * Description: This function moves a piece that is already placed on the board, and makes sure all conditions are met for legal and meaningful moves.
 * ********************************************************************************************************************************************************************/
void movePieceO(char board[][3])
{
	int c, r;
	char retry = 'y';
	while (retry == 'y')
	{
		cout << "Player 1, please pick a column with one of your pieces on it: ";
		cin >> c;
		cout << "Player 1, please pick a row with one of your pieces on it: ";
		cin >> r;
		if (board[r][c] == 'o')
		{
			int tempr = r;
			int tempc = c;
			char alreadyThere = 'y';
			while (alreadyThere == 'y')
			{
				cout << "Please enter the column you would like to move to: ";
				cin >> c;
				cout << "Please enter the row you would like to move to: ";
				cin >> r;
				if ((tempr - r) >1||(tempr - r) < -1||(tempc - c) < -1||(tempc - c) > 1)
					cout << "Invalid: You can only move to an adjacent space. Please try again." << endl;
				else if (board[r][c] == '.')
				{
					board[r][c] = 'o';
					board[tempr][tempc] = '.';
					retry = 'n';
					alreadyThere = 'n';
				}
				else if (board[r][c] == 'o' || board[r][c] == 'x')
					cout << "Invalid: There is another piece there. Please try again." << endl;
				else
					cout << "Invalid: Off the grid. Please try again." << endl;
			}
		}
		else
			cout << "Invalid: You do not have a piece in that space. Please try again." << endl;
	}
}

/*********************************************************************************************************************************************************************** * Description: This function does exactly as the above one does, however moves a piece for Player 2 instead.
 * ********************************************************************************************************************************************************************/
void movePieceX(char board[][3])
{
	int c, r;
	char retry = 'y';
	while (retry == 'y')
	{
		cout << "Player 2, please pick a column with one of your pieces on it: ";
		cin >> c;
		cout << "Player 2, please pick a row with one of your pieces on it: ";
		cin >> r;
		if (board[r][c] == 'x')
		{
			int tempr = r;
			int tempc = c;
			char alreadyThere = 'y';
			while (alreadyThere == 'y')
			{
				cout << "Please enter the column you would like to move to: ";
				cin >> c;
				cout << "Please enter the row you would like to move to: ";
				cin >> r;
				if ((tempr - r) >1||(tempr - r) < -1||(tempc - c) < -1||(tempc - c) > 1)
					cout << "Invalid: You can only move to an adjacent space. Please try again." << endl;
				else if (board[r][c] == '.')
				{
					board[r][c] = 'x';
					board[tempr][tempc] = '.';
					retry = 'n';
					alreadyThere = 'n';
				}
				else if (board[r][c] == 'o' || board[r][c] == 'x')
					cout << "Invalid: There is another piece there. Please try again." << endl;
				else
					cout << "Invalid: Off the grid. Please try again." << endl;
			}
		}
		else
			cout << "Invalid: You do not have a piece in that space. Please try again." << endl;
	}
}
