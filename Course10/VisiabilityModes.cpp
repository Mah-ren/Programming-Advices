#include <iostream>
using namespace std;


class classPerson
{
private:
    void PrivateFunction()
    {
        cout << "\nthis is a private function.";
    }
protected: 
    void ProtectedFunction()
    {
        cout << "\nThis is a protected function.";
    }
public: 
    void PublicFunction()
    {
        cout << "\nThis is a public function.";
    }
};

class classEmployee : private classPerson
{
private:

    void PrivateFunctionForEmployee()
    {
        cout << "\nthis is a private function for employee.";    
    }

protected: 
    void ProtectedFunctionForEmployee()
    {
        cout << "\nthis is a protected function for employee.";    
    }
    
public: 
    void PublicFunctionForEmployee()
    {
        cout << "\nthis is a public function for employee.";    
        ProtectedFunction();
    }
       
};

int main()
{
    classPerson Person;
    Person.PublicFunction();

    classEmployee Employee;
    Employee.PublicFunctionForEmployee();

    // Employee.PublicFunction();
    
}