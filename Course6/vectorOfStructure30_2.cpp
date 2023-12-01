#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct stEmployees
{
    string firstName;
    string lastName;
    short salary;
};

void PrintVectors(vector <stEmployees> &vEmployees)
{
    int i = 1 ;
    for(stEmployees &tempemployee : vEmployees)
    {
        cout << "--------------------------------------------------------------";
        cout << setw(10) << left << "\nFirst Name [" << i << "]" << setw(1) << left << " " << setw(10) << left << tempemployee.firstName << endl;
        cout << setw(10) << left << "\nLast Name ["  << i << "]" << setw(1) << left  << " "  << setw(10) << left <<tempemployee.lastName << endl;
        cout << setw(10) << left << "\nSalary ["  << i << "]" << setw(1) << left << " "  <<  setw(10) << left <<tempemployee.salary << endl;
        cout << endl;
        i ++;
    }   
    cout << endl << endl;        
}

void ReadVectors(vector <stEmployees> &vEmployees , stEmployees &tempemployee)
{
    char notice = 'c' ;
    int counter = 1 ;
    do
    {
        cout << "\nEnter The Employee's [" << counter  << "] First Name: ";
        cin >> tempemployee.firstName ;

        cout << "\nEnter The Employee's [" << counter << "] Last Name: ";
        cin >> tempemployee.lastName ;

        cout << "\nEnter The Employee's [" << counter << "] Salary: ";
        cin >> tempemployee.salary ;

        vEmployees.push_back(tempemployee);
        counter++ ;

        cout << "\nPlease Enter 'Y' or 'y' if you want to add more Employees, else enter anything ";
        cin >> notice ;
        
    } while (notice == 'Y' || notice == 'y');
}

 



void Project()
{   
    stEmployees tempemployee;
    vector <stEmployees> vEmployees ;
    
    ReadVectors(vEmployees , tempemployee);
    cout << "\n\nEmployees Vector: \n\n" ;
    PrintVectors(vEmployees);
}

int main()
{
    Project();
}