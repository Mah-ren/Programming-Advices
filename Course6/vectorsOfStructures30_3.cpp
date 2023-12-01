#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
    string firstName ;
    string lastName ;
    short salary ;
};



int main()
{
    vector<stEmployee> vEmployee ;
    stEmployee tempEmployee ;
    
    cout << "\nEnter Your First Name: \n";
    cin >> tempEmployee.firstName ;

    cout << "\nEnter Your Last Name: \n";
    cin >> tempEmployee.lastName ;

    cout << "\nEnter His Salary : \n";
    cin >> tempEmployee.salary ;

    vEmployee.push_back(tempEmployee);
    vEmployee.clear();
    cout << "\nEnter Your First Name: \n";
    cin >> tempEmployee.firstName ;

    cout << "\nEnter Your Last Name: \n";
    cin >> tempEmployee.lastName ;

    cout << "\nEnter His Salary : \n";
    cin >> tempEmployee.salary ;

    vEmployee.push_back(tempEmployee);
    
    cout << "\nEnter Your First Name: \n";
    cin >> tempEmployee.firstName ;

    cout << "\nEnter Your Last Name: \n";
    cin >> tempEmployee.lastName ;

    cout << "\nEnter His Salary : \n";
    cin >> tempEmployee.salary ;

    vEmployee.push_back(tempEmployee);


    for(stEmployee &employee : vEmployee)
    {
        cout << "\nFirst Name: " << employee.firstName << "\n";
        cout << "\nLast Name: " << employee.lastName << "\n";
        cout << "\nSalary: " << employee.salary << "\n";
    }
     
        vEmployee.clear();
    
    
}