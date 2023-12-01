#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <ctime>
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

int GenerateRandomIntegerInRange(int min, int max)
{
    return rand() % (max - min + 1) + min ;
}

	
void FillMatrixWithRandomNumbers(int array[100][100] , int &rows , int &columns)
{
    
    for(int i = 0 ; i < rows ; ++i)
    {
        for(int j = 0 ; j < columns ; ++j)
            array[i][j] = GenerateRandomIntegerInRange(1,100);
    }
}

void PrintHyphen(int length)
{
    if(length >= 5)
        cout << "\n-----------------------------\n";
    else if(length >=4)
        cout << "\n-----------------------\n";
    else if(length >= 3)
        cout << "\n-----------------\n";
    else if(length >=2)
        cout << "\n-----------\n";
    else 
        cout << "------";
}

void PrintMatrix(int matrix[100][100] , int rows , int columns)
{  
    PrintHyphen(rows);
	
    for(short i = 0 ; i < rows ; ++i)                           
	{
        cout << "|" ;
    
    	for(short j = 0 ; j < columns ; ++j)
	        cout << setw(5) << right << matrix[i][j] << "|";
           
        PrintHyphen(rows);
        cout << endl ;
    }
}

void MultiplyTwoMatrixesIntoThirdOne(int matrix1[100][100] , int matrix2[100][100] , int matrix3[100][100] , int rows , int columns)
{
    for(short i = 0 ; i < rows ; ++i)                           
	{
        for(short j = 0 ; j < columns ; ++j)
			matrix3[i][j] = matrix1[i][j] * matrix2[i][j] ;
    }
}

void Project()
{
    int matrix1[100][100] , matrix2[100][100] , matrix3[100][100] , rows = 1  , columns = 1 ;
    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
    
    cout << "\nThis The first Matrix: \n" ;
    FillMatrixWithRandomNumbers(matrix1 , rows , columns);
    PrintMatrix(matrix1 , rows , columns);
     
    cout << "\nThis The Second Matrix: \n" ;
    FillMatrixWithRandomNumbers(matrix2 , rows , columns);
    PrintMatrix(matrix2 , rows , columns);
    
    cout << "\nThis The Third Matrix: \n" ;
    MultiplyTwoMatrixesIntoThirdOne(matrix1 , matrix2 , matrix3 , rows , columns);
    PrintMatrix(matrix3 , rows , columns);


    


}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}
