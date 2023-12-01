#include <iostream>
#include <limits>
using namespace std ; 

struct stEmployees
{
    string firstName ;
    string lastName ; 
    short salary ;
};



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

int main()
{
    short array[4]{1,2,3,4};
    void *ptr ; 
    ptr = array ; 

    for(short i = 0 ; i < 4 ; ++i)
    {
        cout << (ptr+i) << endl ; 
    }

    for(short i = 0 ; i < 4 ; ++i)
    {
        cout << *(static_cast<short*>(ptr+i)) << endl ;
    }

    stEmployees Employees , *ptr ;
    short length = GetValidPositiveIntegerInRange("\nPlease Enter how many employees do you have ? " , 1 , 10 );
    for(short i = 0 ; i <  length ; ++i)
    {
        cout << "\nfirst name  : " ; 
        cin >> Employees.firstName ; 

        cout << "\nlast name   : " ;
        cin >> Employees.lastName ; 

        cout << "\nenter salary: " ;
        cin >> Employees.salary ; 
        ptr = &Employees ;
    } 


}