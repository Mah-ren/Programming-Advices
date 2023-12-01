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
} CD;

void AddClients(string);
void AddNewClient();
void AddDataLineToFile(string fileName, string dataLine);
void SaveVectorToFile(string fileName, vector<string> &vString);
CD ReadNewClientData();
string ConvertRecordToLine(string delimiter, CD cd);
string GetStringInput(string prompt);


void Project()
{
    AddClients("AddClientsToFile.txt");
}

int main()
{
    Project();
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void AddClients(string fileName)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        system("cls");
        cout << "\nAdding New Client:\n\n";
        AddNewClient();

        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}

void AddNewClient()
{
    AddDataLineToFile(
        "AddClientsToFile", ConvertRecordToLine(
                                " ", ReadNewClientData()));
}

void AddDataLineToFile(string fileName, string dataLine)
{
    fstream myFile;
    myFile.open(fileName,ios::app);
    while (myFile.is_open())
    {
        myFile << dataLine << endl;
        myFile.close();
    }
}

void SaveVectorToFile(string fileName, vector<string> &vString)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        for (string &line : vString)
        {
            myFile << line << endl;
        }
        myFile.close();
    }
}

CD ReadNewClientData()
{
    CD cd;

    cout << "Enter Account Number: ";
    getline(cin >> ws, cd.accountNumber);

    cout << "Enter Pin Code: ";
    getline(cin, cd.pinCode);

    cout << "Enter Name: ";
    getline(cin, cd.name);

    cout << "Enter Phone: ";
    getline(cin, cd.phone);

    cout << "Enter Account Balance: ";
    cin >> cd.balance;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //~ Clear buffer
    return cd;
}

string ConvertRecordToLine(string delimiter, CD cd)
{
    return (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
}

string GetStringInput(string prompt)
{
    string str;

    cout << prompt;
    getline(cin, str);

    return str;
}
 