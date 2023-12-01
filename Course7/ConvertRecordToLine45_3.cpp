#include <iostream>
#include <limits>
using namespace std; 

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone; 
    double balance;
}CD;


CD ReadNewClientData(string);
string ConvertRecordToLine(string , CD);
string GetStringInput(string);

void Project()
{
    CD cd ;
    string delimiter = GetStringInput("\nPlease Enter The Delimiter: ");
    cd = ReadNewClientData("\nPlease Enter Client Data:\n");
    cout << "\nClient Record for saving is: \n" << ConvertRecordToLine(delimiter , cd);
}

int main()
{
    Project();
}


CD ReadNewClientData(string prompt)
{
    CD cd ;
   
    cout << prompt ;
    
    cout << "\nEnter Account Number: ";
    getline(cin , cd.accountNumber);

    cout << "\nEnter Pin Code: ";
    getline(cin , cd.pinCode);    

    cout << "\nEnter Name: ";
    getline(cin , cd.name) ;
    
    cout << "\nEnter Phone: ";
    getline(cin , cd.phone);

    cout << "\nEnter Account Balance: ";
    cin >> cd.balance ;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //~ Clear buffer
    return cd ;
}

string ConvertRecordToLine(string delimiter , CD cd)
{
    return  (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
}

string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

