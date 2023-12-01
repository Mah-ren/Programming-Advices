//! Show All Clients By My Self

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;
string fileName = "DeleteClienst.txt";

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance = 0;
    short numberOfClients = 0;
    bool markForDeleting = false;
} CD;


void DeleteClientFromFile(vector<CD> &vClients);
bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber);
void SaveCleintsDataToFile(string fileName, vector<CD> &vClients);
void SearchForClientsbyAccountNumber(vector<CD> vClients);
string GetStringInput(string prompt);
void PrintClientsData(vector<CD> vClients);
vector<string> SplitString(string str, string delimeter = "#//#");
vector<CD> LoadDataFromFileToVector(string);
string Tabs(short numberOfTabs);
void AddClients(string fileName, string delimiter = "#//#");
void AddNewClient(string fileName, string delimiter = "#//#");
void AddDataLineToFile(string fileName, string dataLine);
CD ReadNewClientData();
string ConvertRecordToLine( CD cd, string delimiter = "#//#");
CD ConvertLineToRecord(string line);
void ShowClientsStatement(size_t);
void PrintOneClientDataLongitudinallyAndtransversely(CD &cd, char);
bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber);


void Project()
{
    
    string delimiter = "#//#";
    AddClients(fileName);
    vector<CD> vClients = LoadDataFromFileToVector(fileName);
    PrintClientsData(vClients);
    SearchForClientsbyAccountNumber(vClients);

    //! Delete client From file
    DeleteClientFromFile(vClients);
    PrintClientsData(vClients);
}

int main()
{
    Project();
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void PrintClientsData(vector<CD> vClients)
{
    system("color 0f");
    ShowClientsStatement(vClients.size());
    for (CD cd : vClients)
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 't');
    }
    cout << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}

void PrintOneClientDataLongitudinallyAndtransversely(CD &cd, char LongitudinallyAndtransversely)
{
    system("color 0f");
    if (LongitudinallyAndtransversely == 't')
    {
        cout << "| " << setw(15) << left << cd.accountNumber
             << "| " << setw(10) << left << cd.pinCode
             << "| " << setw(40) << left << cd.name
             << "| " << setw(12) << left << cd.phone
             << "| " << setw(12) << left << cd.balance
             << "|" << endl;
    }
    else if (LongitudinallyAndtransversely == 'l')
    {
        cout << "\nAccount Number: " << cd.accountNumber;
        cout << "\nPin Code      : " << cd.pinCode;
        cout << "\nName          : " << cd.name;
        cout << "\nPhone         : " << cd.phone;
        cout << "\nBalance       : " << cd.balance;
    }
}

void AddClients(string fileName, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        system("cls");
        cout << "\nAdding New Client:\n\n";
        AddNewClient(fileName);

        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}

void AddNewClient(string fileName, string delimiter)
{
    AddDataLineToFile(
        fileName, ConvertRecordToLine(
                       ReadNewClientData(), delimiter));
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

string ConvertRecordToLine(CD cd, string delimiter)
{
    return (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
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

void ShowClientsStatement(size_t ClientsNumber)
{
    cout << "\n"
         << Tabs(2) << "Client List [" << ClientsNumber << "] Client(s)\n"
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl
         << "| " << setw(15) << left << "Account Number"
         << "| " << setw(10) << left << "Pin Code "
         << "| " << setw(40) << left << "Client Name"
         << "| " << setw(12) << left << "Phone "
         << "| " << setw(12) << left << "Balance"
         << "|" << endl
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
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

vector<CD> LoadDataFromFileToVector(string fileName)
{
    vector<CD> vClients;
    CD cd;

    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        string line;

        while (getline(myFile, line))
        {
            cd = ConvertLineToRecord(line);
            vClients.push_back(cd);
        }
        myFile.close();
    }

    return vClients;
}

CD ConvertLineToRecord(string line)
{
    vector<string> vClient;
    CD cd;
    vClient = SplitString(line);
    cd.accountNumber = vClient[0];
    cd.pinCode = vClient[1];
    cd.name = vClient[2];
    cd.phone = vClient[3];
    cd.balance = stod(vClient[4]);

    return cd;
}

string GetStringInput(string prompt)
{
    string str;
   
    cout << prompt;
    getline(cin, str);

    return str;
}

bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber)
{
    for (CD client : vClients)
    {
        if (client.accountNumber == accountNumber)
        {
            cd = client;
            return true;
        }
    }
    return false;
}


void SearchForClientsbyAccountNumber(vector<CD> vClients)
{
    CD cd;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Search For: ");

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
        system("color 0c");
    }
}

void DeleteClientFromFile(vector<CD> &vClients)
{
    CD cd;
    cout << "\nDelete Client\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Delete it: ");
    char answer = 'n';

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        cout << "\nAre you sure you want to delete it? [Y/N]: ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(answer) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(vClients, accountNumber);
            SaveCleintsDataToFile(fileName, vClients);

            //~ Refresh Clients
            vClients = LoadDataFromFileToVector(fileName);
            cout << "\n\nClient Deleted Successfully."; 
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
        system("color 0c");
    }
}

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber)
{
    for(CD &cd : vClients)
    {
        if(cd.accountNumber == accountNumber)
        {
            cd.markForDeleting = true;
            return true;
        }
    }
}

void SaveCleintsDataToFile(string fileName, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if(myFile.is_open())
    {
        
        for(CD &cd : vClients)
        {
            if(!cd.markForDeleting)
            {
                string lineOfRecord = ConvertRecordToLine(cd);
                myFile << lineOfRecord << endl;
            }
        }
    }
}



/*
!A150#//#1#//#Mahmoud Ahmed Abdel aal ahmed#//#01159340935#//#5000.000000
!A151#//#2#//#Mohamed Ahmed Abdel aal ahmed#//#015323#//#4000.000000
!A152#//#3#//#Mostafa Ahmed Abdel aal ahmed#//#01454935#//#3000.000000
!A153#//#4#//#Mahmoud Hamadah Abdel aal ahmed#//#01122235#//#2000.000000
!A154#//#5#//#Yousof Abdel fatah Abdel aal ahmed#//#011555935#//#1000.000000
!A155#//#6#//#Ahmed Abdel fatah Abdel aal ahmed#//#0115934345#//#900.000000
!A156#//#7#//#Mariam Abdel fatah Abdel aal ahmed#//#011555422935#//#800.000000
!A157#//#8#//#Asmaa Abdel fatah Abdel aal ahmed#//#011596665#//#700.000000
!A158#//#9#//#Fatema Abdel fatah Abdel aal ahmed#//#01122210935#//#600.000000
!A159#//#10#//#Anas Said Abdel aal ahmed#//#11104353#//#850.000000
!A161#//#12#//#Hafsa Said Abdel aal Ahmed#//#999822#//#300.000000
!A160#//#11#//#Sara Said Abdel aal Ahmed#//#0000199#//#400.000000
!A162#//#13#//#Somaia Said Abdel aal Ahmed#//#9992020#//#200.000000
!A163#//#14#//#Safia Said Abdel aal Ahmed#//#99991010#//#100.000000
!A164#//#15#//#Hna Ali Abdel hafez hasan#//#99991111#//#50.000000
!









*/