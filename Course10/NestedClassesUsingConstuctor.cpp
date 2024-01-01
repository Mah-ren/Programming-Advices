#include <iostream>
using namespace std;


class classPerson
{
private:
    string _email;
    string _phoneNumber;
    string _password;

    class classAddress
    {
    private:
        string _street;
        string _city;
        string _country;
        string _zipCode;
    public: 
        classAddress(string street, string city, string country, string zipCode)
        {
            _street = street;
            _city = city;
            _country = country;
            _zipCode = zipCode;
        }
        void Print()
        {
            cout << "\n\t\tAddress";
            cout << "\nStreet : " << _street;
            cout << "\nCity   : " << _city;
            cout << "\nCountry: " << _country;
            cout << "\nZipCode: " << _zipCode;
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
    classPerson (string password, string email, string phoneNumber)
    {
        _password = password;
        _email = email;
        _phoneNumber = phoneNumber;
    }
    classAddress Address;
    void WelComeMessage(string fullName)
    {
        _fullName = fullName;
        cout << "\nHello " << _fullName;

    }
};
 

int main()
{
    classPerson Person("9209229", "om2003", "01159");
    Person.Address.Print();
}
    // classPerson Person("dkfjd);
    // Person.Address.street = "Abu Baker El Sedeek";
    // Person.Address.city = "Giza";
    // Person.Address.country = "Egypt";
    // Person.Address.zipCode = "2343";
    // Person.Address.Print();   