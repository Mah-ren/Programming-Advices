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

void ReadMatrix(int array[100][100] , int &length)
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
	for(int i = 0 ; i < length ; ++i)
	{
		for(int j = 0 ; j < length ; ++j)
			cout << setw(5) << array[i][j];
		cout << endl ;
	}
}

int CalcSumOfOneColumn(int array[100][100] , short row , short column)
{
	int sum = 0 ;
	
	for(int j = 0 ; j < row ; ++j)
	{
		sum += array[j][column] ;
	}



	return sum ;
}

void PrintSumOfEachColumn(int array[100][100] , short row , short column)
{
	
	for(int i = 0 ; i < column ; ++i)
		cout << "\nColumn " << i+1 << " Sum: " << CalcSumOfOneColumn(array , row , i) << "\n";
}
 
int main()
{
	srand((unsigned)time(NULL));
	
    int array[100][100], length ;
    int sumOfRowsInMatrix[50] ;
    int sumOfColumnsInMatrix[50] ;
	
    ReadMatrix(array , length);
	
    cout << "\nThe Following is a " << length << "*" << length << " random Matrix: \n\n";
    PrintMatrix(array , length);
    
    cout << "\nThe Following is The Sum Of Each Row : \n" ;
    PrintSumOfEachColumn(array , length , length);
}

