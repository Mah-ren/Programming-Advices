//!  All Functions Definitions and Decleration are ordered alphabetically ☺ ☻ :-)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
string fileName = "Bank1WithExtension.txt";

enum enMainMenue
{
    ShowClientList   = 1,
    Add_New_Client   = 2,
    DeleteClient     = 3,
    UpdateClientInfo = 4,
    FindClient       = 5,
    Transactions     = 6,
    Exit             = 7
};
enum enTransactionsMenue
{
    Deposite           = 1, 
    Withdraw           = 2, 
    BalanceOfOneClient = 3,
    TotalBalance       = 4,
    MainMenue          = 5
};

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    short balance = 0;
    short numberOfClients = 0;
    bool markForDeleting = false;
    bool markForUpdating = false;
} CD;

void AddClients(vector<CD> &vClients, string fileName, string delimiter = "#//#");
void AddNewClient(vector<CD> &vClients, string fileName, string delimiter = "#//#");
void AddDataLineToFile(string fileName, string dataLine);

CD ChangeClientRecord(string AccountNumber);
string ConvertRecordToLineForClient(CD cd, string delimiter = "#//#");
CD ConvertLineToRecord(string line);
void ClientsIsNotFoundStatement(string accountNumber);

void DeleteClientFromFileByAccountNumber(vector<CD> &vClients);

bool FindClientByAccountNumber(vector<CD> vClients, CD &cd, string accountNumber);
bool FindClientByAccountNumber(vector<CD> vClients, string accountNumber);

enMainMenue GetMainOptionByUser();
string GetStringInput(string prompt);
enTransactionsMenue GetTransactionOptionByUser();
int GetValidPositiveIntegerInRange(string message, short min, short max);
short GetValidPositiveShortIntegerInRange(string, short, short);
void GoBackToMainMenue(vector<CD> vClients);
void GoBackToTransactionsMenue(vector<CD> vClients);

bool isVectorEmpty(vector<CD> vClients);
bool isAmountExceedsTheBalance(CD cd, short withdrawAmount);
vector<CD> LoadDataFromFileToVector(string);

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber);
bool MarkClientForUpdateByAccountNumber(vector<CD> &vClients, string accountNumber);

void PrintClientsData(vector<CD> vClients);
void PrintOneClientDataLongitudinallyAndtransversely(CD cd, char LongitudinallyAndtransversely);
void PerformAddNewClient(vector<CD> &vClients);
void PerformDeposit(vector<CD> &vClients);
void PerformMainMenueOption(vector<CD> vClients);
void PerformShowClientList(vector<CD> vClients);
void PerformTransactions(vector<CD> &vClients);
void PerformTransactionsMenueOptions(vector<CD> &vClients, enTransactionsMenue option);
void PerformUpdateClient(vector<CD> &vClients);
void PerformWithdraw(vector<CD> &vClients);

CD ReadNewClientData(vector<CD> vClients);

void SaveClientsDataToFile(string fileName, vector<CD> &vClients);
void SaveClientsDataToFileForDelete(string fileName, vector<CD> &vClients);
void SaveClientsUpdateToFile(string fileName, vector<CD> &vClients, string accountNumber);
void SearchForClientsByAccountNumber(vector<CD> vClients);
bool ShowAreYouSure();
void ShowNewBalance(CD cd);
void ShowBalancesStatement(vector<CD> vClients);
void ShowBalancesList(vector<CD> vClients);
void ShowBalancesOfClients(vector<CD> vClients);
void ShowBalanceOfOneClient(vector<CD> vClients, enTransactionsMenue option);
void ShowClientsStatement(size_t);
void ShowMainMenueScreen();
void ShowMainMenueOptionsScreen(enMainMenue option);
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option);
void ShowTransactionsMenueScreen();
void ShowVectorIsEmpty();
vector<string> SplitString(string str, string delimeter = "#//#");

string Tabs(short numberOfTabs);

void UpdateClientByAccountNumber(vector<CD> &vClients);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


int main()
{
    vector<CD> vClients;
    vClients = LoadDataFromFileToVector(fileName);
    
    PerformMainMenueOption(vClients);
    return 0;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void AddClients(vector<CD> &vClients, string fileName, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        cout << "\nAdding New Client:\n\n";
        AddNewClient(vClients, fileName, delimiter);
        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}
void AddNewClient(vector<CD> &vClients, string fileName, string delimiter)
{
    AddDataLineToFile(
        fileName, ConvertRecordToLineForClient(
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
void ClientsIsNotFoundStatement(string accountNumber)
{
    cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
    cout << "\a";
    system("color 0c");
}
string ConvertRecordToLineForClient(CD cd, string delimiter)
{
    return (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
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
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        cout << "\nAre you sure you want to delete it? [Y/N]: ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(answer) == 'Y')
        {
            MarkClientForDeleteByAccountNumber(vClients, accountNumber);
            SaveClientsDataToFileForDelete(fileName, vClients);

            //~ Refresh Clients
            vClients = LoadDataFromFileToVector(fileName);
            cout << "\n\nClient Deleted Successfully.";
            system("color 0a");
        }
    }
    else
        ClientsIsNotFoundStatement(accountNumber);
}

bool FindClientByAccountNumber(vector<CD> vClients, string accountNumber)
{
    for (CD &client : vClients)
    {
        if (client.accountNumber == accountNumber)
            return true;
    }
    return false;
}
bool FindClientByAccountNumber(vector<CD> vClients, CD &cd, string accountNumber)
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

int GetValidPositiveIntegerInRange(string message, short min, short max)
{
    int number = 1;

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
short GetValidPositiveShortIntegerInRange(string message, short min, short max)
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
string GetStringInput(string prompt)
{
    string str;

    cout << prompt;
    getline(cin >> ws, str);

    return str;
}
enMainMenue GetMainOptionByUser()
{
    enMainMenue userChoose = (enMainMenue)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 7]: ", 1, 7);
    return userChoose;
}
enTransactionsMenue GetTransactionOptionByUser()
{
    enTransactionsMenue userChoose = (enTransactionsMenue)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 4]: ", 1, 5);
    return userChoose;
}
void GoBackToMainMenue(vector<CD> vClients)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformMainMenueOption(vClients);
}
void GoBackToTransactionsMenue(vector<CD> vClients)
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause > 0");
    PerformTransactions(vClients);
}
     
bool isAmountExceedsTheBalance(CD cd, short amount)
{
    while (amount > cd.balance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to: " << cd.balance 
             << "\nPlease Enter another amount: ";
        cin >> amount;
    }
    return true;
}
bool isVectorEmpty(vector<CD> vClients)
{
    return (vClients.size() == 0) ? true : false;
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

void PerformAddNewClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreen(enMainMenue::Add_New_Client);
    AddClients(vClients, fileName);
}
void PerformDeleteClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreen(enMainMenue::DeleteClient);
    DeleteClientFromFileByAccountNumber(vClients);
}
void PerformDeposit(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if(FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the client details:\n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        
        short depositAmount = 1;
        depositAmount = GetValidPositiveIntegerInRange("\n\nPlease Enter Deposit Amount: ", 1, 32000);

        if(ShowAreYouSure())
        {
            for(CD &c : vClients)
            {
                if(c.accountNumber == cd.accountNumber)
                {
                    cd.balance += depositAmount;
                    c.balance  += depositAmount;
                    break;
                }
            }
            SaveClientsDataToFile(fileName, vClients);
            ShowNewBalance(cd);
            return;
        }
    }
    else
        ClientsIsNotFoundStatement(accountNumber);
}
void PerformExit()
{
    system("cls");
    ShowMainMenueOptionsScreen(enMainMenue::Exit);
}
void PerformFindClient(vector<CD> vClients)
{
    system("cls");
    ShowMainMenueOptionsScreen(enMainMenue::FindClient);
    SearchForClientsByAccountNumber(vClients);
}
void PerformMainMenueOption(vector<CD> vClients)
{    
    system("color 0f");
    system("cls");
    
    ShowMainMenueScreen();   
    vClients = LoadDataFromFileToVector(fileName);
    
    switch(GetMainOptionByUser())
    {
    case enMainMenue::ShowClientList:
        if(isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenue(vClients);
        }
        PerformShowClientList(vClients);
        GoBackToMainMenue(vClients);
        break;
    case enMainMenue::Add_New_Client: 
        PerformAddNewClient(vClients);
        GoBackToMainMenue(vClients);
        break;
    case enMainMenue::DeleteClient:
        if(isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenue(vClients);
        }
        PerformDeleteClient(vClients);
        GoBackToMainMenue(vClients);
        break;
    case enMainMenue::UpdateClientInfo:
        if(isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenue(vClients);
        }
        PerformUpdateClient(vClients);
        GoBackToMainMenue(vClients);
        break;
    case enMainMenue::FindClient:
        if(isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenue(vClients);
        }
        PerformFindClient(vClients);
        GoBackToMainMenue(vClients);
        break;
    case enMainMenue::Transactions:
        if(isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenue(vClients);
        }
        PerformTransactions(vClients);
        break;
    case enMainMenue::Exit:
        PerformExit();
        break;
    }
}
void PerformShowClientList(vector<CD> vClients)
{
    system("cls");
    PrintClientsData(vClients);
}
void PerformTransactions(vector<CD> &vClients)
{
    system("color 0f");
    system("cls");   
    ShowTransactionsMenueScreen();
    enTransactionsMenue option;
    PerformTransactionsMenueOptions(vClients, (option = GetTransactionOptionByUser()));
}
void PerformTransactionsMenueOptions(vector<CD> &vClients, enTransactionsMenue option)
{
    system("cls");
    ShowTransactionsMenueOptionsScreen(option);
    
    switch(option)
    {
    case enTransactionsMenue::Deposite:
    {
        PerformDeposit(vClients);
        GoBackToTransactionsMenue(vClients);
        break;   
    }
    case enTransactionsMenue::Withdraw:
    {
        PerformWithdraw(vClients);
        GoBackToTransactionsMenue(vClients);
        break;
    }
    case enTransactionsMenue::BalanceOfOneClient:
    {
        ShowBalanceOfOneClient(vClients, option);
        GoBackToTransactionsMenue(vClients);
        break;
    }
    case enTransactionsMenue::TotalBalance:
    {
        ShowBalancesList(vClients);
        GoBackToTransactionsMenue(vClients);
        break;
    }
    case enTransactionsMenue::MainMenue:
    {
        GoBackToMainMenue(vClients);
        break;
    }
    }
}
void PerformUpdateClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreen(enMainMenue::UpdateClientInfo);
    UpdateClientByAccountNumber(vClients);
}
void PerformWithdraw(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if(FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
       
        short withdrawAmount = 1;
        cout << "\nPlease Enter Withdraw Amount: ";
        cin >> withdrawAmount;        
        
        if(isAmountExceedsTheBalance(cd, withdrawAmount))
        {
            for(CD &c : vClients)
            {
                if(c.accountNumber == cd.accountNumber)
                {
                    cd.balance -= withdrawAmount;
                    c.balance  -= withdrawAmount;
                    break;
                }
            }
            SaveClientsDataToFile(fileName, vClients);
            ShowNewBalance(cd);
            return;
        }
    }
    else
        ClientsIsNotFoundStatement(accountNumber);
    
}
void PrintBalanceOfOneClient(vector<CD> vClients, CD cd, char LongitudinallyAndtransversely)
{
    if (LongitudinallyAndtransversely == 't')
    {   
    cout << "| " << setw(15) << left << cd.accountNumber
         << "| " << setw(40) << left << cd.name
         << "| " << setw(30) << left << cd.balance
         << "|" << endl;
    }
    else if (LongitudinallyAndtransversely == 'l')
    {
        cout << "\nAccount Number: " << cd.accountNumber;
        cout << "\nName          : " << cd.name;
        cout << "\nBalance       : " << cd.balance;
    }
    
}
void PrintClientsData(vector<CD> vClients)
{
    system("color 0f");
    ShowClientsStatement(vClients.size());
    for (CD &cd : vClients)
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 't');
    }
    cout << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}
void PrintOneClientDataLongitudinallyAndtransversely(CD cd, char LongitudinallyAndtransversely)
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

CD ReadNewClientData(vector<CD> vClients)
{
    CD cd;
   string accountNumber = GetStringInput("Enter Account Number: ");
    
    while(FindClientByAccountNumber(vClients, accountNumber))
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

void SaveClientsDataToFile(string fileName, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out); //! الحمد لله غيرت المود للإضافة بدلا من الكتابة او القراءة 
    if (myFile.is_open())
    {
        string lineOfRecord;
        for(CD &cd: vClients)
        {
            lineOfRecord = ConvertRecordToLineForClient(cd);
            myFile << lineOfRecord << endl;
        }
    }
}
void SaveClientsDataToFileForDelete(string fileName, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {

        for (CD &cd : vClients)
        {
            if (!cd.markForDeleting)
            {
                string lineOfRecord = ConvertRecordToLineForClient(cd);
                myFile << lineOfRecord << endl;
            }
        }
    }
}
void SaveClientsUpdateToFile(string fileName, vector<CD> &vClients, string accountNumber)
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
            myFile << ConvertRecordToLineForClient(cd) << endl;
        }
        myFile.close();
    }
}
void SearchForClientsByAccountNumber(vector<CD> vClients)
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
        ClientsIsNotFoundStatement(accountNumber);     
}
bool ShowAreYouSure()
{
    char c;
    
    cout << "\nAre You Sure You want to perform this transaction? ";
    cin  >> c;

    return (tolower(c) == 'y') ? true : false;

}
void ShowBalancesList(vector<CD> vClients)
{
    ShowBalancesStatement(vClients);
    ShowBalancesOfClients(vClients);

}
void ShowBalancesOfClients(vector<CD> vClients)
{
    system("color 0f");
    if(isVectorEmpty(vClients))
        return;
    for (CD &cd : vClients)
    {
        PrintBalanceOfOneClient(vClients, cd, 't');
    }
    cout << "----------------------------------------------"
         << "----------------------------------------------" << endl;
}
void ShowBalanceOfOneClient(vector<CD> vClients, enTransactionsMenue option)
{
    system("color 0f");
    if(isVectorEmpty(vClients))
    {
        ShowVectorIsEmpty();
    }

    string accountNumber = GetStringInput("\nPlease Enter Account Number: ");
    CD cd;
    if(FindClientByAccountNumber(vClients, cd, accountNumber))
        PrintBalanceOfOneClient(vClients, cd, 'l');
    else 
        ClientsIsNotFoundStatement(accountNumber);
}
void ShowBalancesStatement(vector<CD> vClients)
{
    cout << "\n" 
         << Tabs(2) << "Balances List (" << vClients.size() <<") Client(s)." 
         << "\n____________________________________________________________________________________________\n"
         << "| " << setw(15) << left << "Account Number"
         << "| " << setw(40) << left << "Client Name" 
         << "| " << setw(30) << left << "Balance" 
         << "| " 
         << "\n____________________________________________________________________________________________"
         << endl;
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
void ShowNewBalance(CD cd)
{
    cout << "\nDone Successfully, New Balance is " << cd.balance;
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
    cout << Tabs(1) << "[6] Transactions.\n";
    cout << Tabs(1) << "[7] Exit.\n";
    cout << "===============================================================" << endl; //~ clear the buffer.
}
void ShowMainMenueOptionsScreen(enMainMenue option)
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
void ShowTransactionsMenueScreen()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Transactions Menue Screen\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] Deposite.\n";
    cout << Tabs(1) << "[2] Withdraw.\n";
    cout << Tabs(1) << "[3] Balance Of One Client.\n";
    cout << Tabs(1) << "[4] Total Balances.\n";
    cout << Tabs(1) << "[5] Main Menue.\n";
    cout << "===============================================================\n";
}
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option)
{
    switch(option)
    {
    case enTransactionsMenue::Deposite:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Depsit Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enTransactionsMenue::Withdraw:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Withdraw Screen\n";
        cout << "----------------------------------------";
        break;
    }
    case enTransactionsMenue::BalanceOfOneClient:
    {
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Balance Of One Client\n";
        cout << "----------------------------------------";
        break;
    }
    }
}
void ShowVectorIsEmpty()
{
    system("color 0c");
    cout << "\nNo Clients Available In The System, you can add by"
         << "\nclicking at 2 to add clients\n";
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

string Tabs(short numberOfTabs)
{
    string t = "";

    for (short i = 0; i < numberOfTabs; ++i)
    {
        t += t + "\t";
    }

    return t;
}

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
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        cout << "\nAre you sure you want to update it? [Y/N]: ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(answer) == 'Y')
        {
            MarkClientForUpdateByAccountNumber(vClients, accountNumber);
            SaveClientsUpdateToFile(fileName, vClients, accountNumber);

            //~ Refresh Clients
            vClients = LoadDataFromFileToVector(fileName);
            system("color 0a");
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
        ClientsIsNotFoundStatement(accountNumber);
}