//! The matrix is a sparse matrix when the number of zeros in the matrix is bigger than the rest of the numbers;
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std ;

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

void FillMatrixWithPositiveIntegersByUser(int matrix[100][100] , int &rows , int &columns)
{
    short counter = 1 ;

    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            matrix[i][j] = GetValidPositiveIntegerInRange("\nPlease Enter Integer " + to_string(counter) + " : \n",0,10);
            counter ++ ;
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
        cout << "\n------\n";
}

void PrintMatrix(int matrix[100][100] , int rows , int columns)
{
    PrintHyphen(columns);
    for(short i = 0 ; i < rows ; ++i)                           
    {
        cout << "|" ;

        for(short j = 0 ; j < columns ; ++j)
            cout << setw(3) << right << matrix[i][j] << "|";
        
        PrintHyphen(columns);       
    }
}
  
short CountNumberRepeatationInMatrix(int matrix[100][100] , int &rows , int &columns, short searchNumber)
{
    short counter = 0 ;
     
    for(int i = 0 ; i < rows ; ++i)
    {
        for(int j = 0 ; j < columns ; ++j)
        {   
            if(matrix[i][j] == searchNumber)
                counter ++ ;
        }
    }
    return counter ;
}

bool isSparseMatrix(int matrix[100][100] , int rows , int columns)
{
    short halfOfMatrixSize = rows * columns / 2 ;
    return  CountNumberRepeatationInMatrix(matrix , rows , columns , 0) >= halfOfMatrixSize ;
//! this is better than this return zero > (rows*columns -zero) ;
}

void PrintResult(int matrix[100][100] , int rows , int columns)
{  
    if(isSparseMatrix(matrix , rows , columns))
        cout << "\nYes, This is a Sparse Matrix";
    else 
        cout << "\nNo, This is not a Sparse Matrix";
} 

void Project()
{
    int matrix[100][100] , rows = 1 , columns = 1 ;

    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
       
    FillMatrixWithPositiveIntegersByUser(matrix , rows , columns);
    PrintMatrix(matrix , rows , columns);
    PrintResult(matrix , rows , columns);
}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}