//! this is the Identity Matrix the diagonal with Number 1 and the rest are zeros

//! 1 0 0 0
//! 0 1 0 0
//! 0 0 1 0
//! 0 0 0 1 

#include <iostream>
#include <string>
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
 
void FillMatrixWithRandomNumbers(int matrix[100][100] , int &rows , int &columns)
{
    short counter = 1 ;

    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            matrix[i][j] = GetValidPositiveIntegerInRange("\nPlease Enter Integer " + to_string(counter) + " : \n",0,10);
            counter ++ ;
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

bool isIdentityMatrix(int matrix[100][100] , int rows , int columns)
{
    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            if(i == j && matrix[i][j] != 1)
                return false ;
            else if(i != j && matrix[i][j] != 0)
                return false ;
}

void PrintIfMatrixIsIdentity(int matrix1[100][100] , int rows , int columns)
{
    isIdentityMatrix(matrix1 , rows , columns) ? cout << "\nThis is an Identity Matrix\n" : cout << "\nThis is Not an Identity Matrix\n";
}
 
void Project()
{
    int matrix[100][100] , rows = 1 , columns = 1 ;
   
    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
    
   
    FillMatrixWithRandomNumbers(matrix , rows , columns);
    cout << "\nThis is Matrix1: \n";
    PrintMatrix(matrix , rows , columns);

    PrintIfMatrixIsIdentity(matrix , rows , columns);
    
}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}
 


