//! fibonacci Series 1 1 2 3 5 8 13 21 34 you add the last two numbers 1+0 = 1 , 1+1= 2 , 2+1=3, etc.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

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
  
void PrintFibonacciSeriesUsingLoop(short &length)
{ 
    short febNumber = 0 , prev2 = 0 , prev1 = 1 ; 
    cout << "\n{ 1 ";
	for(short i = 2 ; i <= length+1 ; i++)
	{
        febNumber = prev2 + prev1 ;
        cout << ", " << febNumber << " ";
        prev2 = prev1 ; 
        prev1 = febNumber ;
    }
    cout << "}\n";
} 
 
void Project()
{ 
    short length = GetValidPositiveIntegerInRange("\nPlease Enter a Positive Ineger: \n" , 1 , 100);
    PrintFibonacciSeriesUsingLoop(length);
}

int main()
{
    Project();
}