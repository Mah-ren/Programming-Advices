#include <iostream>
#include <cstdio>
#include <limits>
#include <iomanip>
using namespace std;

int GetValidPositiveInteger(string message)
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

    } while (number < 1);

    return number;
}

void FillTwoDimensionalArrayWithSpecificRowAndColumn(int x[10][10] , int row , int column)
{
    
   

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < column ; j++)
        { 
            x[i][j] = ((i+1) * (j+1)) ;
        }
    }
}

void Project()
{
    static int row = GetValidPositiveInteger("\nPlease Enter Row Number: \n");
    static int column = GetValidPositiveInteger("\nPlease Enter Column Number: \n");
    static int x[10][10] ;
    FillTwoDimensionalArrayWithSpecificRowAndColumn(x, row , column);

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < column ; j++)
        {
            printf("%0*d " ,2, x[i][j]);
        }   
        cout << endl ;
    }

}

int main()
{
    Project();    
}