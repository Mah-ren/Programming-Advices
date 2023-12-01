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
 
bool IsDigitEqual(int referenceValue , int comparisonValue)
{
    return referenceValue == comparisonValue ;
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



void PrintResultOfCountRepeatedNumbersInMatrix(int matrix[100][100] , int rows , int columns)
{
    short searchNumber = GetValidPositiveIntegerInRange("\nPlease Enter Number To See it's Repeatation: \n" , 0 , 100);
    short c = CountNumberRepeatationInMatrix(matrix , rows , columns , searchNumber) ;

    if(c == 0)
        cout << "\nNumber " << searchNumber << " is Not found in This Matrix\n";
    else
        cout << "\nNumber " << searchNumber << " is Repeated " << c << " Time[s]\n";        
} 

void Project()
{
    int matrix[100][100] , rows = 1 , columns = 1 ;

    rows = GetValidPositiveIntegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveIntegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );
       
    FillMatrixWithPositiveIntegersByUser(matrix , rows , columns);
    PrintMatrix(matrix , rows , columns);
    PrintResultOfCountRepeatedNumbersInMatrix(matrix , rows , columns);

}

int main()
{
    srand((unsigned)time(NULL));
    Project();
}