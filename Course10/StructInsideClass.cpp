#include <iostream>
using namespace std;


class classPerson
{
private:
    struct StructInsideClass
    {
        string street;
        string city;
        string country;
        string zipCode;
    };
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
    StructInsideClass structInsideClass;
    void WelComeMessage(string fullName)
    {
        _fullName = fullName;
        cout << "\nHello " << _fullName;

    }
    void Print()
    {
        cout << "\n\t\tAddress";
        cout << "\nStreet : " << structInsideClass.street;
        cout << "\nCity   : " << structInsideClass.city;
        cout << "\nCountry: " << structInsideClass.country;
        cout << "\nZipCode: " << structInsideClass.zipCode;
    }
};
 

int main()
{
    classPerson Person;
    Person.structInsideClass.street = "Abu Baker El Sedeek";
    Person.structInsideClass.city = "Giza";
    Person.structInsideClass.country = "Egypt";
    Person.structInsideClass.zipCode = "2343";
    Person.Print();
}