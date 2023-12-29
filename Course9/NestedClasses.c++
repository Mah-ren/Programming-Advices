#include <iostream>
using namespace std;


class classHumanbeing
{
    virtual void Print() = 0;
    virtual void PrintAddress() = 0;
};

class classPerson : public classHumanbeing
{
    string _FullName;
    class classAddress
    {
    public:
        string Street;
        string Country;
        string Government;
        string ZipCode;
        string PoBox;
         
        void PrintAddress()
        {
       cout << "\nStreet   : " << Street  
            << "\nPoBox    : " << PoBox
            << "\nZipCode  : " << ZipCode
            << "\nCountry  : " << Country
            << "\nGovernment: " <<Government 
            << endl;
        }
    };
    public:
        classAddress Address;
        classPerson(string fullName, string country, string government, string pobox, string zipCode, string street)
        {
           _FullName            = fullName;
            Address.Country     = country;
            Address.Government  = government;
            Address.PoBox       = pobox;
            Address.ZipCode     = zipCode;
            Address.Street      = street;
        }
        void Print()
        {
            cout << "\nFull Name: " << _FullName;
            Address.PrintAddress();
        }
        void PrintAddress()
        {
            
        }
};

int main()
{
    classPerson Person("Mahmoud ahmed Abdel aal Ahmed", "Egypt", "Giza", "9292", "02343", "El_Ahmed_Street");
    Person.Print();
}


