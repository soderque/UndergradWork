 * Description: This program takes three variables and sorts them by reference from smallest to greatest then ddisplays it to the user. *******************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void smallSort(int &first, int &second, int &third)
{
	int temp;
	if (first >= second) // There are five cases total, because there are six possible arrangements for the numbers to appear in, one in which nothing needs to change.
	{
		if (second >= third) //Order: 3, 2, 1
		{
			temp = first;
			first = third;
			third = temp;
		}
		else if (first >= third) //Order: 2, 3, 1
		{
			temp = first;
			first = second;
			second = third;
			third = temp;
		}
		else //Order: 2, 1, 3
		{
			temp = first;
			first = second;
			second = temp;
		}
	}
	else
	{	
		if ((third >= first)&&(second >= third)) //Order: 1, 3, 2
		{
			temp = third;
			third = second;
			second = temp;
		}
		else if (first >= third) //Oder: 3, 1, 2
		{
			temp = first;
			first = third;
			third = second;
			second = temp;
		}
	}
}

int main()
{
	int user1, user2, user3;
	cout << "Please enter 3 values you would like to order from least to greatest: " << endl;
	cin >> user1;
	cin >> user2;
	cin >> user3;
	smallSort(user1, user2, user3);
	cout << user1;
	cout << ", ";
	cout << user2;
	cout << ", ";
	cout << user3 << endl;
	return 0;
}	
