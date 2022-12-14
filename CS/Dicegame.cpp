 * Description: This program allows two players to play a simple dice game. First player to 100 wins! *****************************************************************/

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int main()
	{
	char empty = 's';
	int turn, score1, score2, d1, d2;
	turn = 1;
	score1 = 0;
	score2 = 0;
	while ((score1 < 100) && (score2 < 100)) //Preliminary winning conditions. Both must be true, else one has won the game.
		{
		char dec = 'y';
		while (dec == 'y')
			{
			if (turn%2 == 1) //Every turn is either odd or even. If it's an odd turn, it's Player 1's turn. If it's even, it's Player 2's.	
				{
				cout << "Your turn, Player 1." << endl;
				cout << "Your current score is " << score1 << "." << endl;
				cout << "Enter a character to roll: ";
				cin >> empty;
				srand(time(NULL));
				d1 = (rand()%6+1);
				d2 = (rand()%6+1);
				cout << "Rolls: " << d1 << " and " << d2 << "." << endl;
				if ((d1 == 1)&&(d2 == 1)) //This checks to see if two ones are rolled at the same time. If so, the score is reset for the player.
					{
					score1 = 0;
					cout << "Sorry, you lost all your points!" << endl; //This checks to see if only one of the dice rolls as one. If so, it is automatically the next player's turn.
					turn++;
					}
				else if ((d1 == 1)||(d2 == 1))
					{
					cout << "No score gained this turn." << endl; 
					turn++;
					}
				else //No 1's are rolled, and the score is added to Player 1's score.
					{
					score1 += (d1 + d2); //If the player meets the winning conditions:
					if (score1 >= 100)
						{
						cout << "Congratulations Player 1, you win!" << endl;
						cout << "Player 1 Final Score: " << score1 << endl;
						cout << "Player 2 Final Score: " << score2 << endl;
						dec = 'n';
						}
					else 
						{
						cout << "Player 1, your new score is: " << score1 << ". Would you like to roll again? (y/n)" << endl;
						cin >> dec;
						if (dec == 'n')
							turn++;
						}
					}
				}	
			else //Player 2's Turn.
				{
				cout << "Your turn, Player 2." << endl;
				cout << "Score: " << score2 << endl;
				cout << "Enter a character to roll: ";
				cin >> empty;
				srand (time(NULL));
				d1 = (rand()%6+1);
				d2 = (rand()%6+1);
				cout << "Rolls: " << d1 << " and " << d2 << "." << endl;
				if ((d1 == 1)&&(d2 == 1)) //This checks to see if two ones are rolled at the same time. If so, the score is reset for the player.
					{
					score2 = 0;
					cout << "Sorry, you've lost all your points!" << endl;
					turn++;
					}
				else if ((d1 == 1)||(d2 == 1)) //This checks to see if only one of the dice rolls as one. If so, it is automatically the next player's turn.
					{
					cout << "No score gained this turn." << endl;
					turn++;
					}
				else //No 1's are rolled, and the score is added to Player 2's score.
					{
					score2 += (d1 + d2);
					if (score2 >= 100) //If the player meets the winning conditions:
						{
						cout << "Congratulations Player 2, you win!" << endl;
						cout << "Player 2 Final Score: " << score2 << endl;
						cout << "Player 1 Final Score: " << score1 << endl;
						dec = 'n';
						}
					else
						{	
						cout << "Player 2, your new score is: " << score2 << ". Would you like to roll again? (y/n)" << endl;
						cin >> dec;
						if (dec == 'n')
							turn++;
						}
					}
				}
			}
		}
	return 0;	
}	
