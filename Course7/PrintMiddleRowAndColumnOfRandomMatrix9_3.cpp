#include <iostream>
#include <cmath>
#include <ctime>
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

void PrintMatrix(int matrix[100][100] , int rows , int columns)
{
    for(short i = 0 ; i < rows ; ++i)                           
    {
        cout << "|" ;

        for(short j = 0 ; j < columns ; ++j)
            cout << setw(3) << right << matrix[i][j] << "|";
        cout << endl ;
    }
}

void PrintMiddleRowOrColumnsOfMatrix(int matrix[100][100] , int rows , int columns , char c)
{ 
    short middleRows = rows / 2 ; 
    short middleColumns = columns / 2 ;

    if(c == 'r' || c == 'R')
        for(int j = 0 ; j < columns ; ++j)
            cout << matrix[(int)ceil(middleRows) - 1][j] << " ";
   
    else if(c == 'c' || c == 'C')
        for(int j = 0 ; j < rows ; ++j)
            cout << matrix[j][(int)ceil(middleColumns) - 1] << " ";
}

void Project()
{
    int matrix[100][100] , rows = 1 , columns = 1 ;
 
    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
    
    FillMatrixWithRandomNumbers(matrix , rows , columns);
    PrintMatrix(matrix , rows , columns);
 
    cout << "\nThe middle Row is :\n"; 
    PrintMiddleRowOrColumnsOfMatrix(matrix , rows , columns , 'r');

    cout << "\nThe middle Column is :\n"; 
    PrintMiddleRowOrColumnsOfMatrix(matrix , rows , columns , 'c');
}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}