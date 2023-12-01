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


int GenerateRandomIntegerInRange(int min, int max)
{
    return rand() % (max - min + 1) + min ;
}
 
void FillMatrixWithRandomNumbers(int matrix[100][100] , int &rows , int &columns)
{
    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            matrix[i][j] = GenerateRandomIntegerInRange(1,10);
    
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

bool isMatricesTypical(int matrix1[100][100] , int matrix2[100][100] , int rows , int columns)
{
    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            if(matrix1[i][j] != matrix2[i][j])
                return false ;
        
    return true ;
}

void PrintResultOfTypicalMatrix(int matrix1[100][100] , int matrix2[100][100] , int rows , int columns)
{
    isMatricesTypical(matrix1, matrix2 , rows , columns) ? cout << "\nThey are Typical\n" : cout << "\nThey Are Not Typical\n";
}
void Project()
{
    int matrix1[100][100] , matrix2[100][100], rows = 1 , columns = 1 ;
   
    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
    
    cout << "\nThis is Matrix1: \n";
    FillMatrixWithRandomNumbers(matrix1 , rows , columns);
    PrintMatrix(matrix1 , rows , columns);
    
    cout << "\nThis is Matrix2: \n";
    FillMatrixWithRandomNumbers(matrix2 , rows , columns);
    PrintMatrix(matrix2 , rows , columns);
    
    PrintResultOfTypicalMatrix(matrix1 , matrix2 , rows , columns);
}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}