#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int GetValidPositiveIntegerInRange(string message , int min , int max)
{
    int number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive integer." << endl;
            continue; // Prompt user again
        }
  
    } while (number < min || number > max );

    return number;
}

void FillMatrixWithOrderedNumbers(int matrix[100][100], int &length)
{
    length = GetValidPositiveIntegerInRange("\nPlease Enter Matrix Number: " , 1 , 100);
    short counter = 0 ;
    for(short i = 0 ; i <= length ; ++i)                  
    {                                                   
        for(short j = 0 ; j < length ; ++j)                               
        {    counter++;
            matrix[i][j] = counter ;                            
        }
    }                                                                   
}                                                         



void PrintTwoDimensionalArray(int array[100][100] , int length)
{
	for(short i = 0 ; i < length ; ++i)                           
	{
        cout << "|" ;

		for(short j = 0 ; j < length ; ++j)
			cout << setw(3) << right << array[i][j] << "|";
		cout << endl ;
	}
}


void Project()
{
    int matrix[100][100] , length = 1 ;
    FillMatrixWithOrderedNumbers(matrix , length);
    PrintTwoDimensionalArray(matrix , length);
}

int main()
{
    Project();
}
 