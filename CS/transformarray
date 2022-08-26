 * Description: This program transforms an array into twice its size by reference and by dynamically allocating memory to change the size of the array.
 * ********************************************************************************************************************************************************************/

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

/***********************************************************************************************************************************************************************
 * Description: This function is what changes the array by taking a value for each space in the array and adding it to the end of the array.
 * ********************************************************************************************************************************************************************/
void transformArray(int (*&arr), int sizeArray) //Dynamically allocated array which is also taken in reference.
{
	int* x = new int[sizeArray];
	for(int i = 0; i < sizeArray; i++)
		x[i] = arr[i];
	delete[] arr;
	arr = new int[sizeArray*2]; 
	for(int i = 0; i < sizeArray; i++)
		arr[i] = x[i];
	delete[] x;
	int p = ((sizeArray*2) - sizeArray);
	for(int i = 0; i < p; i++)
		arr[i+p] = arr[i] + 1;
}
/*
int main()
{
	int* myArray = new int[6];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;
	myArray[3] = 6;
	myArray[4] = 14;
	myArray[5] = 1700;

	transformArray(myArray, 6);
	for (int i=0; i<12; i++)
	{
		cout << myArray[i] << endl;
	}
	delete[] myArray;
	return 0;
} */
