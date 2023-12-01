#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
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
    PrintHyphen(columns);
    for(short i = 0 ; i < rows ; ++i)                           
    {
        cout << "|" ;

        for(short j = 0 ; j < columns ; ++j)
            cout << setw(3) << right << matrix[i][j] << "|";
        PrintHyphen(columns);  
    }
}
 
void FillMatrixWithPositiveIntegersByUser(int matrix[100][100] , int &rows , int &columns)
{
    short counter = 1 ;

    for(int i = 0 ; i < rows ; ++i)
    {
        for(int j = 0 ; j < columns ; ++j)
        {
            matrix[i][j] = GetValidPositiveIntegerInRange("\nPlease Enter Integer " + to_string(counter) + " : \n",0,100);
            counter ++ ;
        }
    }
}

bool isNumberFoundInMatrix(int matrix[100][100] , int &rows , int &columns, short searchNumber)
{
    for(int i = 0 ; i < rows ; ++i)
    {
        for(int j = 0 ; j < columns ; ++j)
        {
            if(matrix[i][j] == searchNumber)
                return true ;
            else 
                continue;
        }
    }
    return false ;
}

void PrintIntersectedNumbersInMatrices(int matrix1[100][100] , int matrix2[100][100] , int rows , int columns)
{
    cout << "{ " ;
    
    for(int i = 0 ; i < rows ; ++i)
    {   
        for(int j = 0 ; j < columns ; ++j)
        {
            if(isNumberFoundInMatrix(matrix1 , rows , columns , matrix2[i][j]))
                cout  << matrix2[i][j] << " "  ;
        }
    }

    cout << "}\n";
}

void Project()
{
    int matrix1[100][100] , matrix2[100][100] , rows = 1 , columns = 1 ; 
    
    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );

    cout << "\nPlease Enter Elements of Matrix: \n";
    FillMatrixWithPositiveIntegersByUser(matrix1 , rows , columns);
    
    cout << "\nPlease Enter Elements of Matrix: \n";
    FillMatrixWithPositiveIntegersByUser(matrix2 , rows , columns);
    
    PrintMatrix(matrix1 , rows , columns);
    PrintMatrix(matrix2 , rows , columns);

    cout << "\nIntersectedt Numbers Are In Matrices:\n";
    PrintIntersectedNumbersInMatrices(matrix1 , matrix2 , rows , columns);
}

int main()
{
    Project();
}