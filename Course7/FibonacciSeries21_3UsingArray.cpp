//! fibonacci Series 1 1 2 3 5 8 13 21 34 you add the last two numbers 1+0 = 1 , 1+1= 2 , 2+1=3, etc.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
using namespace std;
//! started from 2 and i want to repeat until 4 so, 0 < 2 so 0 , 1 = 2 -> 2.3.4.5 2345
short GetValidPositiveIntegerInRange(string message , short min , short max)
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
  
void FillArrayWithFibonacciSeries(short array[1000] , short &length)
{
    length = GetValidPositiveIntegerInRange("Enter the length of the array, between 1-100: " , 1 , 1000) ;
    array[0] = 1 ; 
    array[1] = 1 ;
    
	for(short i = 2 ; i <= length+1 ; i++)
	{
        array[i] = array[i-2] + array[i-1] ;
    }
} 
void PrintArray(short Array[1000] , short arrayLength)
{
    cout << "{ ";

    for(int i = 0 ; i < arrayLength ; i++)
    {
    	cout << Array[i] << " " ;
    }    
    cout << " }";    
    cout << "\n";
}

void Project()
{ 
    short array[1000] , length = 1 ; 
    FillArrayWithFibonacciSeries(array , length);
    PrintArray(array , length);
}

int main()
{
    Project();
}