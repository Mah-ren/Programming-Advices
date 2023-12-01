//! Palindrome Number is The number when you read from the left-right is the same as from right-left

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

short GetValidPositiveshortegerInRange(string message , short min , short max)
{
    short number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-shorteger input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive shorteger." << endl;
            continue; // Prompt user again
        }
  
    } while (number < min || number > max );

    return number;
}

void PrintHyphen(short length)
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

void PrintMatrix(short matrix[100][100] , short rows , short columns)
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

void FillMatrixWithPositiveshortegersByUser(short matrix[100][100] , short &rows , short &columns)
{
    short counter = 1 ;

    for(short i = 0 ; i < rows ; ++i)
    {
        for(short j = 0 ; j < columns ; ++j)
        {
            matrix[i][j] = GetValidPositiveshortegerInRange("\nPlease Enter shorteger " + to_string(counter) + " : \n",0,100);
            counter ++ ;
        }
    }
}
 
bool isPalindromeMatrix(short matrix[100][100] , short rows , short columns)
{
    for(int i = 1 ; i < rows ; ++i)
    {
        for(int j = 0 ; j < floor(columns/2.0) ; ++j)
        {
            if(matrix[i][j] != matrix[j][columns-1-j])
                return false ; 
        }

    }

    return true ;
}

void PrintResult(short matrix[100][100] , short rows , short columns)
{
    if(isPalindromeMatrix(matrix , rows , columns))
        cout << "\nYes, This is a Palindrome Matrix\n";
    else 
        cout << "\nNo, This is not a Palindrome Matrix\n";
}

void Project()
{
    short matrix[100][100]  , rows = 1 , columns = 1 ; 
    
    rows = GetValidPositiveshortegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveshortegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );

    cout << "\nPlease Enter Elements of Matrix: \n";
    FillMatrixWithPositiveshortegersByUser(matrix , rows , columns);
    
    cout << "\nThis is the matrix:\n";
    PrintMatrix(matrix , rows , columns);
   
    PrintResult(matrix , rows , columns);
   

}

int main()
{
    Project();
}