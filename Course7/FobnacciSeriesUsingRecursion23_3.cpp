//! fibonacci Series 1 1 2 3 5 8 13 21 34 you add the last two numbers 1+0 = 1 , 1+1= 2 , 2+1=3, etc.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
using namespace std;

long long GetValidPositiveIntegerInRange(string message , long long min , long long max)
{
    long long number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-long longeger input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive long longeger." << endl;
            continue; // Prompt user again
        }
  
    } while (number < min || number > max );

    return number;
}
  
void PrintFibonacciSeriesUsingRecursion(long long &length ,long long &fibNumber , long long &prev1 , long long &prev2)
{ 
    if(length > 0)
    {
        fibNumber = prev1 + prev2 ;
        cout << ", " << fibNumber << " ";
        prev2 = prev1 ;
        prev1 = fibNumber ;
        --length ;
        PrintFibonacciSeriesUsingRecursion(length , fibNumber , prev1 , prev2);
    }
    
} 
 
void Project()
{ 
    long long length = GetValidPositiveIntegerInRange("\nPlease Enter a Positive Ineger: \n" , 1 , 100000000000000000000);
    
    long long fibNumber = 0 , prev1 = 1 , prev2 = 0 ; 
    cout << "{ 1 ";
    PrintFibonacciSeriesUsingRecursion(length , fibNumber , prev1 , prev2);
    cout << "}\n\n";
}

int main()
{
    Project();
}