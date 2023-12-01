//! Show All Clients By My Self

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
string fileName = "Bank1AfterElAser.txt";

enum enMainMenue
{
    ShowClientList = 1,
    Add_New_Client = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Exit = 6
};

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance = 0;
    short numberOfClients = 0;
    bool markForDeleting = false;
    bool markForUpdating = false;
} CD;

void AddClients(vector<CD> &vClients, string fileName, string delimiter = "#//#");
void AddNewClient(vector<CD> &vClients, string fileName, string delimiter = "#//#");
void AddDataLineToFile(string fileName, string dataLine);

CD ChangeClientRecord(string AccountNumber);
string ConvertRecordToLine(CD cd, string delimiter = "#//#");
CD ConvertLineToRecord(string line);

void DeleteClientFromFileByAccountNumber(vector<CD> &vClients);

bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber);
bool FindClientByAccountNumber(vector<CD> &vClients, string accountNumber);

string GetStringInput(string prompt);
short GetValidPositiveIntegerInRange(string, short, short);

vector<CD> LoadDataFromFileToVector(string);

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber);
bool MarkClientForUpdateByAccountNumber(vector<CD> &vClients, string accountNumber);

void PrintClientsData(vector<CD> &vClients);
void PrintOneClientDataLongitudinallyAndtransversely(vector<CD> &vClients, CD &cd, char LongitudinallyAndtransversely);

CD ReadNewClientData(vector<CD> &vClients);

void SaveCleintsDataToFile(string fileName, vector<CD> &vClients);
void SaveCleintsUpdateToFile(string fileName, vector<CD> &vClients, string accountNumber);
void SearchForClientsByAccountNumber(vector<CD> &vClients);
void ShowMainMenueScreen();
void ShowClientsStatement(size_t);
void ShowOptionsScreen(enMainMenue option);
void ShowPauseStatement();
vector<string> SplitString(string str, string delimeter = "#//#");

string Tabs(short numberOfTabs);

void UpdateClientByAccountNumber(vector<CD> &vClients);

void Project()
{
    vector<CD> vClients;
    string delimiter = "#//#";
    bool continueLoop = true;
    while (continueLoop)
    {
        system("cls");
        ShowMainMenueScreen();
        enMainMenue userChoose = (enMainMenue)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 6]: ", 1, 6);

        if (userChoose == enMainMenue::ShowClientList)
        {
            system("cls");
            vClients = LoadDataFromFileToVector(fileName);
            PrintClientsData(vClients);
            ShowPauseStatement();
            continueLoop = true;
        }
        else if (userChoose == enMainMenue::Add_New_Client)
        {

            system("cls");
            ShowOptionsScreen(enMainMenue::Add_New_Client);
            AddClients(vClients, fileName);
            vClients = LoadDataFromFileToVector(fileName);
            PrintClientsData(vClients);
            ShowPauseStatement();
            continueLoop = true;
        }
        else if (userChoose == enMainMenue::DeleteClient)
        {
            system("cls");

            ShowOptionsScreen(enMainMenue::DeleteClient);
            vClients = LoadDataFromFileToVector(fileName);
            DeleteClientFromFileByAccountNumber(vClients);
            ShowPauseStatement();
            continueLoop = true;
        }
        else if (userChoose == enMainMenue::UpdateClientInfo)
        {
            system("cls");

            ShowOptionsScreen(enMainMenue::UpdateClientInfo);
            vClients = LoadDataFromFileToVector(fileName);
            UpdateClientByAccountNumber(vClients);
            ShowPauseStatement();
            continueLoop = true;
        }
        else if (userChoose == enMainMenue::FindClient)
        {
            system("cls");

            ShowOptionsScreen(enMainMenue::FindClient);
            vClients = LoadDataFromFileToVector(fileName);
            SearchForClientsByAccountNumber(vClients);
            ShowPauseStatement();
            continueLoop = true;
        }
        else if (userChoose == enMainMenue::Exit)
        {
            system("cls");
            ShowOptionsScreen(enMainMenue::Exit);
            continueLoop = false;
        }
    }
}

int main()
{
    Project();
    return 0;
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void ShowPauseStatement()
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
}
void ShowMainMenueScreen()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Main Menue Screen\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] Show Client List.\n";
    cout << Tabs(1) << "[2] Add New Client.\n";
    cout << Tabs(1) << "[3] Delete Client.\n";
    cout << Tabs(1) << "[4] Update Client Info.\n";
    cout << Tabs(1) << "[5] Find Client.\n";
    cout << Tabs(1) << "[6] Exit.\n";
    cout << "===============================================================" << endl; //~ clear the buffer.
}

void PrintClientsData(vector<CD> &vClients)
{
    system("color 0f");
    ShowClientsStatement(vClients.size());
    for (CD &cd : vClients)
    {
        PrintOneClientDataLongitudinallyAndtransversely(vClients, cd, 't');
    }
    cout << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}

void PrintOneClientDataLongitudinallyAndtransversely(vector<CD> &vClients, CD &cd, char LongitudinallyAndtransversely)
{
    system("color 0f");

    if (vClients.size() == 0)
    {
        cout << "\n\t\t\t\t\aNo Clients Available In the System.";
        system("color 0c");
    }
    else if (LongitudinallyAndtransversely == 't')
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

void ShowOptionsScreen(enMainMenue option)
{
    switch (option)
    {
    case enMainMenue::Add_New_Client:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Add New Clients Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enMainMenue::DeleteClient:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Delete Client Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enMainMenue::UpdateClientInfo:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Update Client Info Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enMainMenue::FindClient:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Find Client Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enMainMenue::Exit:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Program Ends:-)\n";
        cout << "----------------------------------------\n";
        break;
    }
    }
}

void AddClients(vector<CD> &vClients, string fileName, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        cout << "\nAdding New Client:\n\n";
        AddNewClient(vClients, fileName, delimiter);
        vClients = LoadDataFromFileToVector(fileName);
        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}

void AddNewClient(vector<CD> &vClients, string fileName, string delimiter)
{
    AddDataLineToFile(
        fileName, ConvertRecordToLine(
                      ReadNewClientData(vClients), delimiter));
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

CD ReadNewClientData(vector<CD> &vClients)
{
    CD cd;
    string accountNumber = GetStringInput("Enter Account Number: ");

    while (FindClientByAccountNumber(vClients, accountNumber))
    {
        cout << "\a";
        system("color 0c");
        cout << "Client With[" << cd.accountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, accountNumber);
    }

    cd.accountNumber = accountNumber;

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
    getline(cin >> ws, str);

    return str;
}

bool FindClientByAccountNumber(vector<CD> &vClients, string accountNumber)
{
    for (CD &client : vClients)
    {
        if (client.accountNumber == accountNumber)
            return true;
    }
    return false;
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

void SearchForClientsByAccountNumber(vector<CD> &vClients)
{
    CD cd;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Search For: ");

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(vClients, cd, 'l');
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
        cout << "\a";
        system("color 0c");
    }
}

void DeleteClientFromFileByAccountNumber(vector<CD> &vClients)
{
    CD cd;
    cout << "\nDelete Client\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Delete it: ");
    char answer = 'n';

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(vClients, cd, 'l');
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
            system("color 0a");
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
        cout << "\a";
        system("color 0c");
    }
}

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber)
{
    for (CD &cd : vClients)
    {
        if (cd.accountNumber == accountNumber)
        {
            cd.markForDeleting = true;
            return true;
        }
    }
    return false;
}

bool MarkClientForUpdateByAccountNumber(vector<CD> &vClients, string accountNumber)
{
    for (CD &cd : vClients)
    {
        if (cd.accountNumber == accountNumber)
        {
            cd.markForUpdating = true;
            return true;
        }
    }
    return false;
}

void SaveCleintsDataToFile(string fileName, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {

        for (CD &cd : vClients)
        {
            if (!cd.markForDeleting)
            {
                string lineOfRecord = ConvertRecordToLine(cd);
                myFile << lineOfRecord << endl;
            }
        }
    }
}
//! //////////////////////////////////////////////////////////////////////////////////
void UpdateClientByAccountNumber(vector<CD> &vClients)
{

    CD cd;
    cout << "\nUpdate Client\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Update it: ");
    char answer = 'n';

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(vClients, cd, 'l');
        cout << "\nAre you sure you want to update it? [Y/N]: ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(answer) == 'Y')
        {
            MarkClientForUpdateByAccountNumber(vClients, accountNumber);
            SaveCleintsUpdateToFile(fileName, vClients, accountNumber);

            //~ Refresh Clients
            vClients = LoadDataFromFileToVector(fileName);
            system("color 0a");
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
        cout << "\a";
        system("color 0c");
    }
}

short GetValidPositiveIntegerInRange(string message, short min, short max)
{
    short number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive integer." << endl;
            continue; // Prompt user again
        }

    } while (number < min || number > max);

    return number;
}

void SaveCleintsUpdateToFile(string fileName, vector<CD> &vClients, string accountNumber)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {
        for (CD &cd : vClients)
        {
            if (cd.markForUpdating)
            {
                // Update the specific client data marked for updating
                cd = ChangeClientRecord(accountNumber);
            }
            myFile << ConvertRecordToLine(cd) << endl;
        }
        myFile.close();
    }
}
CD ChangeClientRecord(string AccountNumber)
{
    CD cd;
    
    cd.accountNumber = AccountNumber;
    cout << "\n\nEnter PinCode: ";
    getline(cin >> ws, cd.pinCode);
    cout << "Enter Name: ";
    getline(cin, cd.name);
    cout << "Enter Phone: ";
    getline(cin, cd.phone);
    cout << "Enter Account Balance: ";
    cin >> cd.balance;

    return cd;
}
