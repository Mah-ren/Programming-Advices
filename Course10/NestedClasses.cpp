#include <iostream>
using namespace std;


class classPerson
{
private:
    class classAddress
    {
    public: 
        string street;
        string city;
        string country;
        string zipCode;

        void Print()
        {
            cout << "\n\t\tAddress";
            cout << "\nStreet : " << street;
            cout << "\nCity   : " << city;
            cout << "\nCountry: " << country;
            cout << "\nZipCode: " << zipCode;
        }
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
    classAddress Address;
    void WelComeMessage(string fullName)
    {
        _fullName = fullName;
        cout << "\nHello " << _fullName;

    }
};
 

int main()
{
    classPerson Person;
    Person.Address.street = "Abu Baker El Sedeek";
    Person.Address.city = "Giza";
    Person.Address.country = "Egypt";
    Person.Address.zipCode = "2343";
    Person.Address.Print();   
}