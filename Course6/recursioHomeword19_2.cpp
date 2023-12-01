#include <iostream>
#include <limits>
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

/*
void PrintNumbers(int min , int max)
{
    if(max >= min)
    {
        cout << max << "\n" ;
        PrintNumbers(min , max-1);
    }
}
*/
int CalcPowerOfNumber(int base , int exponent , int &power )
{
     
    if(exponent >= 1)
    {
        power = base * power ; 
        CalcPowerOfNumber(base , exponent-1 , power);
    }

    return power ;
}
 
int main()
{
    //PrintNumbers(1,10); 
    int power = 1 ;
    cout << CalcPowerOfNumber(2 , 3 ,power);
}

 