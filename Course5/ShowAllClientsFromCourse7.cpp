//! Show All Clients By My Self 

#include <iostream>
#include <iomanip>
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
    double balance = 0;
    short numberOfClients = 0;
} CD;

vector<string> SplitString(string str, string delimeter = " ");
void PrintClientsData(CD Clients[100][5], vector<string> &vFileContent);
void PrintOneClientData(CD Clients[100][5], short clientNumber);
void LoadDataFromVectorOfLinesOfStringsToVectorOfStruct(CD Clients[100][5], vector<string> &, string);
void LoadDataFromFileToVector(string, vector<string> &);
string Tabs(short numberOfTabs);
void AddClients(string &fileName, string &delimiter);
void AddNewClient(string fileName, string &delimiter);
void AddDataLineToFile(string fileName, string dataLine);
CD ReadNewClientData();
string ConvertRecordToLine(string delimiter, CD cd);
string GetStringInput(string prompt);
void ShowClientsStatement(size_t , CD Clients[100][5]);

void Project()
{
    //! أول حاجة بملئ الاستركت ثم احوله لاسترنج عبارة عن نص ثم اطبع الاسترنج للملف 
    CD cd, Clients[100][5];
    vector<string> vFileContent;
    string fileName = "ShowClients.txt";
    string delimiter = "#//#";
    AddClients(fileName, delimiter);
    
    //! عشان اخزن فيها الاسطر اللي في الملف vFileContent  ثم اعمل فكتور اللي هو اسمه
    LoadDataFromFileToVector(fileName, vFileContent);

    //! اخزن فيه عناصر السطر يعني هو بيقسم السطر على حسب ال vLine كده أنا معايا فكتور متخزن فيه اسطر , محتاج اعمل فكتور اسمه 
    //!  Matrix اللي هو  vClients ثم يخزن هذه العناصر اللي هي مكونات الاستركت فيتم تخزينها في  delimiter or separatorعشان

    LoadDataFromVectorOfLinesOfStringsToVectorOfStruct(Clients, vFileContent, delimiter);
    //! Matrix ثم اطبع هذه المصفوفة او 
    PrintClientsData(Clients, vFileContent);
}

int main()
{
    Project();
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void LoadDataFromVectorOfLinesOfStringsToVectorOfStruct(CD Clients[100][5], vector<string> &vFileContent, string delimiter)
{
    vector<string> vLine;

    for (short i = 0; i < vFileContent.size(); ++i)
    {
        vLine = SplitString(vFileContent[i], delimiter);
        Clients[i][0].accountNumber = vLine.at(0);
        Clients[i][1].pinCode = vLine.at(1);
        Clients[i][2].name = vLine.at(2);
        Clients[i][3].phone = vLine.at(3);
        Clients[i][4].balance = stod(vLine.at(4));
    }
}

void PrintClientsData(CD Clients[100][5], vector<string> &vFileContent)
{
    ShowClientsStatement(vFileContent.size(), Clients);
    for (short i = 0; i < vFileContent.size(); ++i)
    {
        PrintOneClientData(Clients, i);
    }
    cout << "-----------------------------------------------"
         << "----------------------------------------------------" << endl;
}

void PrintOneClientData(CD Clients[100][5], short clientNumber)
{
    cout << "| "<< setw(15) << left << Clients[clientNumber][0].accountNumber
         << "| "<< setw(10) << left << Clients[clientNumber][1].pinCode
         << "| "<< setw(40) << left << Clients[clientNumber][2].name
         << "| "<< setw(12) << left << Clients[clientNumber][3].phone
         << "| "<< setw(12)  << left << Clients[clientNumber][4].balance
         << "|" << endl;
}

void AddClients(string &fileName, string &delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        system("cls");
        cout << "\nAdding New Client:\n\n";
        AddNewClient(fileName, delimiter);

        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}

void AddNewClient(string fileName, string &delimiter)
{
    AddDataLineToFile(
        fileName, ConvertRecordToLine(
                      delimiter, ReadNewClientData()));
}

void AddDataLineToFile(string fileName, string dataLine)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        myFile << dataLine << endl;
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

string Tabs(short numberOfTabs)
{
    string t = "";

    for (short i = 0; i < numberOfTabs; ++i)
    {
        t += t + "\t";
    }

    return t;
}

void ShowClientsStatement(size_t numberOfClients, CD Clients[100][5])
{
    cout << "\n"
         << Tabs(2) << "Client List [" << numberOfClients << "] Client(s)\n"
         << "---------------------------------------------------------------------------------------------------" << endl
         << "| " << setw(15) << left << "Account Number" 
         << "| " << setw(10) << left << "Pin Code " 
         << "| " << setw(40) << left << "Client Name"
         << "| " << setw(12) << left << "Phone " 
         << "| " << setw(12)  << left << "Balance"
         << "|" << endl
         << "---------------------------------------------------------------------------------------------------" << endl;
}

vector<string> SplitString(string str, string delimeter)
{
    vector<string> vLineOfData;
    string word;
    short position = 0;

    while ((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0, position);

        if (word != "")
        {
            vLineOfData.push_back(word);
        }

        str.erase(0, position + delimeter.length());
    }

    if (str != "")
    {
        vLineOfData.push_back(str);
    }

    return vLineOfData;
}

void LoadDataFromFileToVector(string fileName, vector<string> &vFileContent)
{
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            vFileContent.push_back(line);
        }
        myFile.close();
    }
}