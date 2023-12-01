#include <iostream>
#include <iomanip>
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

void PrshortHyphen(short length)
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

void PrshortMatrix(short matrix[100][100] , short rows , short columns)
{
    PrshortHyphen(columns);
    for(short i = 0 ; i < rows ; ++i)                           
    {
        cout << "|" ;

        for(short j = 0 ; j < columns ; ++j)
            cout << setw(3) << right << matrix[i][j] << "|";
        PrshortHyphen(columns);  
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

short FindMaxNumberInMatrix(short matrix[100][100] , short rows , short columns)
{ 
    short max = matrix[0][0] ;
    
    for(short i = 0 ; i < rows ; i++)
    {
        for(short j = 0 ; j < columns ; ++j)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j] ;
            }
        }
    }
    
    return max ; 
}

short FindMinNumberInMatrix(short matrix[100][100] , short rows , short columns)
{
    short min = matrix[0][0] ;
    
    for(short i = 0 ; i < rows ; i++)
    {
        for(short j = 0 ; j < columns ; ++j)
        {    
            if(matrix[i][j] < min)
            {
                min = matrix[i][j] ;
            }
        }
    }
    
    return min ;
}

void PrshortMaxNumberInMatrix(short matrix[100][100] , short &rows , short &columns)
{
    cout << "\nThis is The Max Number in The Matrix: " << FindMaxNumberInMatrix(matrix , rows , columns);
}

void PrshortMinNumberInMatrix(short matrix[100][100] , short &rows , short &columns)
{
    cout << "\nThis is The Min Number in The Matrix: " << FindMinNumberInMatrix(matrix , rows , columns);
}

void Project()
{
    short matrix[100][100]  , rows = 1 , columns = 1 ; 
    
    rows = GetValidPositiveshortegerInRange("\nPlease Enter How many Rows Matrix has: \n" , 1 , 100 );
    columns = GetValidPositiveshortegerInRange("\nPlease Enter How many Columns Matrix has: \n" , 1 , 100 );

    cout << "\nPlease Enter Elements of Matrix: \n";
    FillMatrixWithPositiveshortegersByUser(matrix , rows , columns);
    
    PrshortMatrix(matrix , rows , columns);
   

  
    PrshortMaxNumberInMatrix(matrix , rows , columns);
    PrshortMinNumberInMatrix(matrix , rows , columns);

}

int main()
{
    Project();
}