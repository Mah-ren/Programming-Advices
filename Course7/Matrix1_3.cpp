#include <iostream>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int GetRandomNumberInRange(int min , int max)
{
	return rand() % (max - min + 1) + min ;
}

int GetValidPositiveNumberInRange(string prompt)
{
	int number = 0;
	
	do
	{
		cout << prompt ;
		cin >> number ;
		if(cin.fail())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cout << "Invalid input. Please enter a number." << endl;
			cin >> number ;
		}
	}while(number < 0 || number > 1000);
	
	return number ;
}

void ReadTwoDimensionalArray(int array[100][100] , int &length)
{
	length = GetValidPositiveNumberInRange("Enter the length of the array, between 1-1000: ") ;
	
	for(int i = 0 ; i < length ; i++)
	{
		for(int j = 0 ; j < length ; ++j)
			array[i][j] = GetRandomNumberInRange(1 , 100) ;
	}
}

void PrintTwoDimensionalArray(int array[100][100] , int length)
{
	for(int i = 0 ; i < length ; ++i)
	{
		for(int j = 0 ; j < length ; ++j)
			cout << setw(5) << array[i][j];
		cout << endl ;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int array[100][100], length ;
	ReadTwoDimensionalArray(array , length);
	PrintTwoDimensionalArray(array , length);
	return 0;
 }