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
	}while(number < 0 || number > 100);
	
	return number ;
}

void FillArrayWithRandomNumbers(int array[100][100] , int &length)
{
	length = GetValidPositiveNumberInRange("Enter the length of the array, between 1-100: ") ;
	 
	for(int i = 0 ; i < length ; i++)
	{
		for(int j = 0 ; j < length ; ++j)
		    array[i][j] = GetRandomNumberInRange(1 , 100) ;
    }
}

void PrintMatrix(int array[100][100] , int length)
{
    cout << "\nThe Following is a " << length << "*" << length << " random Matrix: \n";

	for(int i = 0 ; i < length ; ++i)
	{
		for(int j = 0 ; j < length ; ++j)
			cout << setw(5) << array[i][j];
		cout << endl ;
	}
}

int CalcSumOfOneRow(int array[100][100] , short rowNumber , short length)
{
	int sum = 0 ;
	
	for(int j = 0 ; j < length ; ++j)
	{
		sum += array[rowNumber][j] ;
	}
	
	return sum ;
}

void FillArrayWithSumOfRowsInMatrix(int sumOfRowsInMatrix[50] , int array[100][100] , int length)
{
    for(int rowNumber = 0 ; rowNumber < length ; ++rowNumber)
    	sumOfRowsInMatrix[rowNumber] = CalcSumOfOneRow(array , rowNumber , length) ;
}
 
void PrintSumOfEachRowInMatrix(int sumOfRowsInMatrix[] , int length)
{
    cout << "\nThe Following is the sum of each row in the matrix: \n" ;
    
    for(int j = 0 ; j < length ; ++j)
		cout << "\nRow " << j+1 << " : " << sumOfRowsInMatrix[j] ;

}

int main()
{
	srand((unsigned)time(NULL));
	
    int array[100][100], length ;
    int sumOfRowsInMatrix[50] ;
    int sumOfColumnsInMatrix[50] ;
	
    FillArrayWithRandomNumbers(array , length);
	PrintMatrix(array , length);
	FillArrayWithSumOfRowsInMatrix(sumOfRowsInMatrix ,array , length) ;
	PrintSumOfEachRowInMatrix(sumOfRowsInMatrix , length);
}

