#include <iostream>
using namespace std;

enum enAddress
{
    Street      = 1,
    Building = 2,
    PoBox = 3, 
    ZipCode = 4, 
    Country    = 5,
    Government = 6, 
};

class classAddress
{
private:
    string _building;
    string _poBox;
    string _street;
    string _government;
    string _country;
    string _zipCode;
    
public:
    classAddress(string building, string street, string poBox, string zipCode, string country, string government)
    {
        cout << "\nHi i'm the constructor.";

        _building = building;
        _street   = street;
        _poBox    = poBox;
        _zipCode  = zipCode;
        _country  = country;
        _government = government;
    }
  
    void PrintAddress()
    {
        cout << "\nAddress Card: ";
        cout << "\nBuilding  : " << _building;
        cout << "\nStreet    : " << _street;
        cout << "\nPoBox     : " << _poBox;
        cout << "\nZipCode   : " << _zipCode;
        cout << "\nCountry   : " << _country;
        cout << "\nGovernment: " << _government;
    }



    void Street(string street)
    {
        _street = street;
    }
    void Building(string building)
    {
        _building = building;
        
    }
    void PoBox(string poBox)
    {
        _poBox = poBox;
    }
    void ZipCode(string zipCode)
    {
        _zipCode = zipCode;
    }
    void Country(string country)
    {
        _country = country;
    }
    void Government(string government)   
    { 
        _government = government;
    }

};

void Project()
{
    
    system("color 0f");
    system("cls");

    classAddress Address1("Our House", "Abu Baker El Siedieq", "11192", "0238676460", "Egypt", "Giza");
    classAddress Address2 = Address1;

    Address1.PrintAddress();
    Address2.PrintAddress();
    cout << endl;
    system("pause>0");
}
int main()
{ 
    Project();
} 
