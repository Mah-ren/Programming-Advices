#include <iostream>
using namespace std;


class classEmployee
{
private:
    string _fullName;
    string GetID()
    {
        return "\nID: 30311292104553";
    }
    string GetPasswordOfMyVisa()
    {
        return "\n01159340935.google.com";
    }
public:
    void WelComeMessage(string fullName)
    {
        _fullName = fullName;
        cout << "\nHello " << _fullName;

    }
    friend void GET_ID(classEmployee Employee);
};

void GET_ID(classEmployee Employee)
{
    cout << Employee.GetID();
}


int main()
{
    classEmployee Employee;


    cout << "\nThis is the friend function: \" GetID from external function\"";
    GET_ID(Employee);
}