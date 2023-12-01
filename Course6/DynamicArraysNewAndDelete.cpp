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

void ReadElementsOfDynamicArray(stEmployees *Employees)
{
    
    char addMore = 'y';
    short i = 1 ; 
    while(addMore == 'y' || addMore == 'Y')
    {
        cout << "\nPlease Enter First Name for Employee " << i << ": " ; 
        cin >> Employees[i].firstName;
        cout << "\nPlease Enter Last Name  for Employee " << i << ": " ; 
        cin >> Employees[i].lastName  ; 
        cout << "\nPlease Enter Salary     for Employee " << i << ": " ; 
        cin >> Employees[i].salary    ;

        cout << "\nDo you want to play again? " << endl ; 
        cin >> addMore ; 
    }
}

void PrintElementsOfDynamicArray(stEmployees *Employees )
{
    short length = sizeof(Employees) / sizeof(Employees[0]) ;

    for(short i = 0 ; i < length ; ++i)
    {
        cout << "\nEmployee [" << i+1 << "]: \n" ;
        cout << "\nFirst Name for Employee " << i+1 << ": " << Employees[i].firstName ; 
        cout << "\nLast Name  for Employee " << i+1 << ": " << Employees[i].lastName  ; 
        cout << "\nSalary     for Employee " << i+1 << ": " << Employees[i].salary ; 
    }
}

int main()
{
    
    
    short length = GetValidPositiveIntegerInRange("\nPlease Enter Total Employees: " , 1 , 100);
    stEmployees *Employees = new stEmployees[length] ; 
    
    ReadElementsOfDynamicArray(Employees);
    PrintElementsOfDynamicArray(Employees);
    
    delete[] Employees ;

}