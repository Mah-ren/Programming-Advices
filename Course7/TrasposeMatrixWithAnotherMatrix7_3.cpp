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

void FillMatrixWithOrderedNumbers(int matrix[100][100] , int &rows , int &columns)
{
    rows = GetValidPositiveIntegerInRange("\nPlease Enter Columns Matrix Numbers: " , 1 , 100);
    columns = GetValidPositiveIntegerInRange("\nPlease Enter Rows Matrix Numbers: " , 1 , 100);
    
    short counter = 0 ;

    for(short i = 0 ; i <= rows ; ++i)                  
    {                                                   
        for(short j = 0 ; j < columns ; ++j)                               
        {    counter++;
            matrix[i][j] = counter ;                            
        }
    }                                                                   
}                                                         

void PrintMatrix(int array[100][100] , int rows , int columns)
{
	for(short i = 0 ; i < rows ; ++i)                           
	{
        cout << "|" ;

		for(short j = 0 ; j < columns ; ++j)
			cout << setw(3) << right << array[i][j] << "|";
		cout << endl ;
	}
}

void FillTrasPoseMatrix(int matrix[100][100] , int trasPoseMatrix[100][100] , int rows , int columns)
{    
	for(short i = 0 ; i < rows ; ++i)                           
	{
		for(short j = 0 ; j < columns ; ++j)
			trasPoseMatrix[j][i] = matrix[i][j] ;
	}
}

void Project()
{
    int matrix[100][100] , trasPoseMatrix[100][100] , rows = 1 , columns = 1 ;
   
    FillMatrixWithOrderedNumbers(matrix , rows , columns);
    PrintMatrix(matrix , rows , columns);

    cout << "\nThis is the traspose Matrix: \n" ;
    FillTrasPoseMatrix(matrix , trasPoseMatrix , rows , columns);
    PrintMatrix(trasPoseMatrix , rows , columns);
}

int main()
{
    Project();
}
 