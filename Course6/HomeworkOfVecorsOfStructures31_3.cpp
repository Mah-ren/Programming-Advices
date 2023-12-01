#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct stEmployee
{
    string firstName;
    string lastName;
    short salary;
};

char GetCharByUser(string prompt)
{
    char notion = 'c';

    cout << prompt;
    cin >> notion;

    return notion;
}

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

    } while (number < min || number > max);

    return number;
}
//! i want to solve this homework with recursion cuz it'll give me a run for my money
void PrintVectors(vector<stEmployee> &vEmployee)
{
    static short count = 1 ;
    
    for(stEmployee &employee : vEmployee)
    {
        cout << "\n\nEmployee[" << count <<"]:\n";
        cout << "\nFirst Name: " << employee.firstName ;
        cout << "\nLast Name : " << employee.lastName ;
        cout << "\nSalary    : " << employee.salary ; 
        ++count ; 
    }
    
}
void ReadVectors(vector<stEmployee> &vEmployee)
{

    // short length = 1 ;     length = GetValidPositiveIntegerInRange("\nPlease Enter Number of Employees[1-1000]: \n", 1 , 1000);
    stEmployee tempEmployee;
    short count = 1 ;
    char notion = 'y';
    while (notion == 'y' || notion == 'Y')
    {
        
        cout << "\nEmployee[" << count <<"]:\n";
        cout << "\nEnter Your First Name: \n";
        cin >> tempEmployee.firstName;

        cout << "\nEnter Your Last Name: \n";
        cin >> tempEmployee.lastName;

        cout << "\nEnter His Salary : \n";
        cin >> tempEmployee.salary;

        vEmployee.push_back(tempEmployee);
        
        ++count ; 

        notion = GetCharByUser("\nPlease Enter 'y' if you wanna add more Employees, otherwise enter 'n': \n");
    }

    PrintVectors(vEmployee);
}


int main()
{
    system("color 0c");
    vector<stEmployee> vEmployee ;
 
    ReadVectors(vEmployee);
    vEmployee.clear();
}