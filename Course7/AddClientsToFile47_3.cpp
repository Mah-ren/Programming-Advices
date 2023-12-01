#include <iostream>
#include <fstream>
#include <vector>
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


void SaveVectorToFile(string , vector<string>&);
void LoadDataFromVectorToFile(vector<string>&);
void ReadClientsRecordsAndSaveThemInAFile(string);
void PrintRecord(CD);
vector<string> SplitString(string , string);
CD ReadNewClientData(string);
string ConvertRecordToLine(string , CD);
string GetStringInput(string);
 

void Project()
{
    ReadClientsRecordsAndSaveThemInAFile("AddClientsToFile.txt");
}

int main()
{
    Project();
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void ReadClientsRecordsAndSaveThemInAFile(string fileName)
{ 
    char addMore = 'y';
    vector<string> vString ;
    while(toupper(addMore) == 'Y')
    {
        system("cls");
        vString.push_back
        (
            ConvertRecordToLine
            (
                " " , ReadNewClientData("\nAdding New Client Data:\n\n")
            )
        );
        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore ;
    }SaveVectorToFile(fileName , vString);
}

void SaveVectorToFile(string fileName , vector<string>& vString)
{
    fstream myFile;
    myFile.open(fileName , ios::app);
    if(myFile.is_open())
    {
        for(string &line : vString)
        {
            myFile << line << endl ;
        }
        myFile.close();
    }
}

void PrintFileContent(string fileName , vector<string>& vString)
{
    fstream myFile ;
    myFile.open(fileName , ios::in);
    if(myFile.is_open())
    {
        string line ;
        
        while(line != "")
        {
            cout << line << endl ;
        }

        myFile.close();
    }
}


CD ReadNewClientData(string prompt)
{
    CD cd ;
   
    cout << prompt ;
 
    cout << "Enter Account Number: ";
    cin >> cd.accountNumber ;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //~ Clear buffer
    cout << "Enter Pin Code: ";
    getline(cin , cd.pinCode);    

    cout << "Enter Name: ";
    getline(cin , cd.name) ;
    
    cout << "Enter Phone: ";
    getline(cin , cd.phone);

    cout << "Enter Account Balance: ";
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