//!  All Functions Definitions and Decleration are ordered alphabetically ☺ ☻ :-)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

//! Define features using binary representation
#define a 0b00000001
#define b 0b00000010
#define c 0b00000100
#define d 0b00001000
#define e 0b00010000
#define f 0b00100000
#define g 0b01000000

string ClientsFile = "ClientsFile.txt";

enum enATMMainMenue
{
    QuickWithdraw = 1,
    NormalWithdraw = 2,
    Deposit = 3,
    ChckBalance = 4,
    Logout = 7
};
enum enQuickWithdraw
{
    the20 = 1,
    the50 = 2,
    the100 = 3,
    the200 = 4,
    the400 = 5,
    the600 = 6,
    the800 = 7,
    the1000 = 8,
    Exit = 9,
};

typedef struct stClientData
{
    string accountNumber;
    string name;
    string phone;
    int pinCode = 1;
    int balance = 1;
}CD;
 
 
bool AreYouAgreed(string message, char agreed, char notAgreed);

string ConvertRecordToLineForClient(CD cd, string delimiter = "#//#");
string ConvertRecordToLineForUser(stUN UN, string delimiter = "#//#");
CD ConvertClientLineToRecord(string line);
void ClientIsNotFoundStatement(string accountNumber);


bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber);
bool FindClientByAccountNumberAndPinCode(vector<CD> &vClients, CD &cd);

string GetStringInput(string prompt);
int GetValidPositiveIntegerInRange(string, int, int);
void GoBackToMainMenueForClients(CD &cd);

bool isVectorEmpty(vector<CD> &vClients);

vector<CD> LoadClientDataFromFileToVector(string);
void Log_in();

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber);
bool MarkClientForUpdateByAccountNumber(vector<CD> &vClients, string accountNumber);
bool MarkUserForDeleteByUsername(vector<stUN> &vUsers, string username);

void PerformUpdateUser(vector<stUN> &vUsers);
void PrintClientsData(vector<CD> &vClients);
void PrintOneClientDataLongitudinallyAndtransversely(CD &cd, char LongitudinallyAndtransversely);
void PrintOneUserDataLongitudinallyAndtransversely(stUN &UN, char LongitudinallyAndtransversely);
void PrintOneUserDataLongitudinallyAndtransversely(stUN &UN, char LongitudinallyAndtransversely);
void PrintUsersData(vector<stUN> &vUsers);
void PerformDeposit(vector<CD> &vClients);
void PerformExit();
void PerformFindUser(vector<stUN> &vUsers);
void PerformFindClient(vector<CD> &vClients);
void PerformMainMenueOptionForClients(CD &cd);
void PerformMainMenueOptionForUsers(stUserName &UN, CD &cd);
void PerformManageUsersMenueScreen(stUserName &UN, CD &cd);
stUN PerformPermission(stUN &UN);
void PerformShowClientList(vector<CD> &vClients);
void PerformShowUserList(vector<stUN> &vUsers);
void PerformTransactions(vector<CD> &vClients, CD &cd);
void PerformTransactionsMenueOptionsForClients(vector<CD> &vClients, CD &cd, enTransactionsMenue option);
void PerformUpdateClient(vector<CD> &vClients);
void PerformUpdateUser(vector<stUN> &vUsers);
void PerformWithdraw(vector<CD> &vClients);
void PerformWithdraw(vector<stUN> &vUsers);

void SaveCleintsDataToFile(string ClientsFile, vector<CD> &vClients);
void SaveCleintsDataToFileForDelete(string ClientsFile, vector<CD> &vClients);
void SaveCleintsUpdateToFile(string ClientsFile, vector<CD> &vClients, string accountNumber);
void SaveUsersDataToFile(string UsersFile, vector<stUN> &vUsers);
void SaveUserDataToFileForDelete(string UsersFile, vector<stUN> &vUsers);
void SaveUsersUpdateToFile(string UsersFile, vector<stUN> &vUsers, string username);
void SearchForClientsByAccountNumber(vector<CD> &vClients);
void SearchForUserByUsername(vector<stUN> &vUsers);
void ShowAccessIsDenied();
void ShowBalancesStatement(vector<CD> &vClients);
void ShowBalancesList(vector<CD> &vClients);
void ShowBalancesOfClients(vector<CD> &vClients);
void ShowBalanceOfOneClient(vector<CD> &vClients, enTransactionsMenue option);
void ShowClientsListScreen(size_t);
void ShowUsersListScreen(size_t);
void ShowLogInScreen();
void ShowMainMenueScreenForClients();
void ShowMainMenueScreenForUsers();
void ShowMainMenueOptionsScreenForClients(enMainMenueForClients option);
void ShowManageMenueOptionsScreen(enManageUsersMenue option);
void ShowManageUsersMenueScreen();
void ShowNewBalance(CD &cd);
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option);
void ShowTransactionsMenueScreenForClients();
void ShowVectorIsEmpty();
vector<string> SplitString(string str, string delimeter = "#//#");

string Tabs(short numberOfTabs);

void UpdateClientByAccountNumber(vector<CD> &vClients);
void UpdateUserByUsername(vector<stUN> &vUsers);
void UserIsNotFoundStatement(string username);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main()
{
    Log_in();
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void AddClients(vector<CD> &vClients, string ClientsFile, string delimiter)
{
    bool addMore = true;
    while (addMore)
    {
        cout << "\nAdding New Client:\n\n";
        AddNewClient(vClients, ClientsFile, delimiter);
        system("color 0a");
        addMore = AreYouAgreed("\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ", 'y', 'n');
    }
}
CD AddNewClientData(vector<CD> &vClients)
{
    CD cd;
    string accountNumber = GetStringInput("Enter Account Number: ");

    while (FindClientByAccountNumberAndPinCode(vClients, cd))
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
stUN AddNewUserData(vector<stUN> &vUsers)
{
    stUN UN;
    string username = GetStringInput("Enter Username: ");

    while (FindUserByUsername(vUsers, UN, username))
    {
        cout << "\a";
        system("color 0c");
        cout << "User With[" << UN.user_name << "] already exists, Enter another Username: ";
        getline(cin >> ws, username);
    }

    UN.user_name = username;
    UN.password = GetStringInput("\nEnter Password: ");

    UN = PerformPermission(UN);
    return UN;
}
void AddUsers(vector<stUN> &vUsers, string UsersFile, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        cout << "\nAdding New User:\n\n";
        AddNewUser(vUsers, UsersFile, delimiter);
        system("color 0a");
        addMore = AreYouAgreed("\n\aUser Added Successfuly, Do you want to add more Users? [Y/N] ", 'y', 'n');
    }
}
void AddNewClient(vector<CD> &vClients, string ClientsFile, string delimiter)
{
    AddDataLineToFile(
        ClientsFile, ConvertRecordToLineForClient(
                         AddNewClientData(vClients), delimiter));
}
void AddNewUser(vector<stUN> &vUsers, string UsersFile, string delimiter)
{
    AddDataLineToFile(ClientsFile, ConvertRecordToLineForUser(AddNewUserData(vUsers)));
}
void AddDataLineToFile(string ClientsFile, string dataLine)
{
    fstream myFile;
    myFile.open(ClientsFile, ios::app);
    if (myFile.is_open())
    {
        myFile << dataLine << endl;
        myFile.close();
    }
}
bool AreYouAgreed(string message, char agreed, char notAgreed)
{
    char choice = 'y';

    do
    {
        cout << message;
        cin >> choice;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid Char. Please enter [n, N, y, Y] only: " << endl;
            continue; // Prompt user again
        }

    } while (!(tolower(choice) == agreed || tolower(choice) == notAgreed));

    return (tolower(choice) == 'y' ? true : false);
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
stUN ChangeUserRecord(string username)
{
    stUN UN;

    UN.user_name = username;
    cout << "\n\nEnter Password: ";

    return UN;
}
void ClientIsNotFoundStatement(string accountNumber)
{
    cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
    cout << "\a";
    system("color 0c");
}
string ConvertRecordToLineForClient(CD cd, string delimiter)
{
    return (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
}
string ConvertRecordToLineForUser(stUN UN, string delimiter)
{
    return (UN.user_name + delimiter + UN.password + delimiter + to_string(UN.permissions));
}
CD ConvertClientLineToRecord(string line)
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
stUN ConvertUserLineToRecord(string line)
{
    vector<string> vLine;
    stUN UN;
    vLine = SplitString(line);
    UN.user_name = vLine[0];
    UN.password = vLine[1];

    return UN;
}

void DeleteClientFromFileByAccountNumber(vector<CD> &vClients)
{
    CD cd;
    cout << "\nDelete Client\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Delete it: ");

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');

        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            MarkClientForDeleteByAccountNumber(vClients, accountNumber);
            SaveCleintsDataToFileForDelete(ClientsFile, vClients);

            //~ Refresh Clients
            vClients = LoadClientDataFromFileToVector(ClientsFile);
            cout << "\n\nClient Deleted Successfully.";
            system("color 0a");
        }
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
void DeleteUserFromFileByUsername(vector<stUN> &vUsers)
{
    stUN UN;
    cout << "\nDelete User\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string username = GetStringInput("\nPlease Enter Username To Delete it: ");

    if (FindUserByUsername(vUsers, UN, username))
    {
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');

        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            MarkUserForDeleteByUsername(vUsers, username);
            SaveUserDataToFileForDelete(UsersFile, vUsers);

            //~ Refresh Clients
            vUsers = LoadUserDataFromFileToVector(UsersFile);
            cout << "\n\nUser Deleted Successfully.";
            system("color 0a");
        }
    }
    else
        UserIsNotFoundStatement(username);
}

void EnterUserNameAndPassword(vector<CD> &vClientsData)
{
    stUN UN;
    CD cd;

    while (true)
    {
        UN.user_name = cd.accountNumber = GetStringInput("\nEnter Account Number: ");
        UN.password = cd.pinCode = GetStringInput("\nEnter Pin Code: ");

        if (FindClientByAccountNumberAndPinCode(vClientsData, cd))
            PerformMainMenueOptionForClients(cd);
        cout << "\nInvalid Username/Password:";
    }
}

bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber)
{
    for (CD &client : vClients)
    {
        if (client.accountNumber == accountNumber)
        {
            cd = client;
            return true;
        }
    }
    return false;
}
bool FindClientByAccountNumberAndPinCode(vector<CD> &vClients, CD &cd)
{
    for (CD client : vClients)
    {
        if (client.accountNumber == cd.accountNumber && client.pinCode == cd.pinCode)
            return true;
    }
    return false;
}
bool FindUserByUsername(vector<stUN> &vUsers, stUN &UN, string user_name)
{
    for (stUserName &UserName : vUsers)
    {
        if (UserName.user_name == user_name)
        {
            UN = UserName;
            return true;
        }
    }
    return false;
}
bool FindUserByUserNameAndPassword(vector<stUserName> &vUsers, stUN &UN)
{
    for (stUserName &UserName : vUsers)
    {
        if (UserName.user_name == UN.user_name && UserName.password == UN.password)
            return true;
    }

    return false;
}

int GetValidPositiveIntegerInRange(string message, int min, int max)
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
string GetStringInput(string prompt)
{
    string str;

    cout << prompt;
    getline(cin >> ws, str);

    return str;
}
enManageUsersMenue GetManageUsersOption()
{
    enManageUsersMenue option = (enManageUsersMenue)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 8]: ", 1, 6);
    return option;
}
enMainMenueForClients GetMainOptionByUserForClients()
{
    enMainMenueForClients userChoose = (enMainMenueForClients)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 7]: ", 1, 7);
    return userChoose;
}
enMainMenueForUsers GetMainOptionByUserForUsers()
{
    enMainMenueForUsers option = (enMainMenueForUsers)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 8]: ", 1, 8);
    return option;
}
enTransactionsMenue GetTransactionOptionByUser()
{
    enTransactionsMenue option = (enTransactionsMenue)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 4]: ", 1, 5);
    return option;
}
short GivePermissions(string message, short featureNumber)
{
    short permission = 0;
    permission &= ~(1 << (featureNumber - 'a'));
    bool areYouAgreed = AreYouAgreed(message, 'y', 'n');

    if ((featureNumber == 0) && areYouAgreed)
    {
        permission = -1;
        return permission;
    }
    else if (areYouAgreed)
        permission |= (1 << (featureNumber - 'a'));

    return permission;
}
void GoBackToMainMenueForClients(CD &cd)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformMainMenueOptionForClients(cd);
}
void GoBackToMainMenueForUsers(stUserName &UN, CD &cd)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformMainMenueOptionForUsers(UN, cd);
}
void GoBackToManageMenueForUsers(stUserName &UN, CD &cd)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformManageUsersMenueScreen(UN, cd);
}
void GoBackToTransactionsMenue(vector<CD> &vClients, CD &cd)
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause > 0");
    PerformTransactions(vClients, cd);
}

bool isAmountExceedsTheBalance(short balance, short amount)
{
    if (amount > balance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to: " << balance
             << "\nPlease Enter another amount: ";
    }
}
bool isVectorEmpty(vector<CD> &vClients)
{
    return (vClients.size() == 0) ? true : false;
}
bool isVectorEmpty(vector<stUN> &vUsers)
{
    return (vUsers.size() == 0) ? true : false;
}
bool IsFeatureEnabled(const stUN &UN, short feature)
{
    return (UN.permissions & feature != 0) || UN.permissions == -1;
}

vector<CD> LoadClientDataFromFileToVector(string ClientsFile)
{
    vector<CD> vClients;
    CD cd;

    fstream myFile;
    myFile.open(ClientsFile, ios::in);
    if (myFile.is_open())
    {
        string line;

        while (getline(myFile, line))
        {
            cd = ConvertClientLineToRecord(line);
            vClients.push_back(cd);
        }
        myFile.close();
    }

    return vClients;
}
vector<stUN> LoadUserDataFromFileToVector(string UsersFile)
{
    vector<stUN> vUsers;
    stUN UN;

    fstream myFile;
    myFile.open(UsersFile, ios::in);
    if (myFile.is_open())
    {
        string line;

        while (getline(myFile, line))
        {
            UN = ConvertUserLineToRecord(line);
            vUsers.push_back(UN);
        }
        myFile.close();
    }

    return vUsers;
}
void Log_in()
{
    vector<CD> vClientsData;

    vClientsData = LoadClientDataFromFileToVector(ClientsFile);

    ShowLogInScreen();
    EnterUserNameAndPassword(vClientsData);
}

bool MarkUserForDeleteByUsername(vector<stUN> &vUsers, string username)
{
    for (stUserName &UserName : vUsers)
    {
        if (UserName.user_name == username)
        {
            UserName.markForDeleting = true;
            return true;
        }
    }
    return false;
}
bool MarkUserForUpdateByUsername(vector<stUN> &vUsers, string username)
{
    for (stUserName &UserName : vUsers)
    {
        if (UserName.user_name == username)
        {
            UserName.markForUpdating = true;
            return true;
        }
    }
    return false;
}
void PerformDeposit(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the client details:\n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        int depositAmount = GetValidPositiveIntegerInRange("\n\nPlease Enter Deposit Amount: ", 1, 32000);
        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            for (CD &cd : vClients)
            {
                if (cd.accountNumber == cd.accountNumber)
                {
                    cd.balance += depositAmount;
                    cd.balance += depositAmount;
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFile, vClients);
            ShowNewBalance(cd);
            return;
        }
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
void PerformExit()
{
    Log_in();
}
void PerformMainMenueOptionForClients(CD &cd)
{
    system("color 0f");
    system("cls");
    ShowMainMenueScreenForClients();

    vector<CD> vClients;
    vClients = LoadClientDataFromFileToVector(ClientsFile);

    switch (GetMainOptionByUserForClients())
    {
    case enMainMenueForClients::show_client_list:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(cd);
        }
        PerformShowClientList(vClients);
        GoBackToMainMenueForClients(cd);
        break;
    case enMainMenueForClients::add_new_client:
        PerformAddNewClient(vClients);
        GoBackToMainMenueForClients(cd);
        break;
    case enMainMenueForClients::deleteClient:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(cd);
        }
        PerformDeleteClient(vClients);
        GoBackToMainMenueForClients(cd);
        break;
    case enMainMenueForClients::UpdateClientInfo:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(cd);
        }
        PerformUpdateClient(vClients);
        GoBackToMainMenueForClients(cd);
        break;
    case enMainMenueForClients::FindClient:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(cd);
        }
        PerformFindClient(vClients);
        GoBackToMainMenueForClients(cd);
        break;
    case enMainMenueForClients::transactions:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(cd);
        }
        PerformTransactions(vClients, cd);
        break;
    case enMainMenueForClients::Exit:
        PerformExit();
        break;
    }
}
void PerformShowClientList(vector<CD> &vClients)
{
    system("cls");
    PrintClientsData(vClients);
}
void PerformTransactions(vector<CD> &vClients, CD &cd)
{
    system("color 0f");
    system("cls");
    ShowTransactionsMenueScreenForClients();
    enTransactionsMenue option;
    PerformTransactionsMenueOptionsForClients(vClients, cd, (option = GetTransactionOptionByUser()));
}
void PerformTransactionsMenueOptionsForClients(vector<CD> &vClients, CD &cd, enTransactionsMenue option)
{

    system("cls");
    ShowTransactionsMenueOptionsScreen(option);

    switch (option)
    {
    case enTransactionsMenue::Deposite:
        PerformDeposit(vClients);
        GoBackToTransactionsMenue(vClients, cd);
        break;
    case enTransactionsMenue::Withdraw:
        PerformWithdraw(vClients);
        GoBackToTransactionsMenue(vClients, cd);
        break;
    case enTransactionsMenue::BalanceOfOneClient:
        ShowBalanceOfOneClient(vClients, option);
        GoBackToTransactionsMenue(vClients, cd);
        break;
    case enTransactionsMenue::TotalBalance:
        ShowBalancesList(vClients);
        GoBackToTransactionsMenue(vClients, cd);
        break;
    case enTransactionsMenue::MainMenue:
        PerformMainMenueOptionForClients(cd);
    }
}
void PerformUpdateClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::UpdateClientInfo);
    UpdateClientByAccountNumber(vClients);
}
void PerformUpdateUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreen(enManageUsersMenue::UpdateUser);
    UpdateUserByUsername(vUsers);
}
void PerformWithdraw(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        int depositAmount = GetValidPositiveIntegerInRange("\nPlease Enter Deposit Amount: ", 1, 60000);
        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            cd.balance -= depositAmount;
            SaveCleintsDataToFile(ClientsFile, vClients);
            ShowNewBalance(cd);
            return;
        }
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
void PrintBalanceOfOneClient(vector<CD> &vClients, CD &cd, char LongitudinallyAndtransversely)
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
void PrintClientsData(vector<CD> &vClients)
{
    system("color 0f");
    ShowClientsListScreen(vClients.size());

    for (CD &cd : vClients)
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 't');
        cout << "-------------------------------------------------"
             << "--------------------------------------------------" << endl;
    }
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
        cout << "\nThe Following are the Client Details \n";
        cout << "\nAccount Number: " << cd.accountNumber;
        cout << "\nPin Code      : " << cd.pinCode;
        cout << "\nName          : " << cd.name;
        cout << "\nPhone         : " << cd.phone;
        cout << "\nBalance       : " << cd.balance;
    }
}
void SaveCleintsDataToFile(string ClientsFile, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(ClientsFile, ios::out | ios::app); //! الحمد لله غيرت المود للإضافة بدلا من الكتابة او القراءة

    if (myFile.is_open())
    {
        string lineOfRecord;
        for (CD &cd : vClients)
        {
            lineOfRecord = ConvertRecordToLineForClient(cd);
            myFile << lineOfRecord << endl;
        }
    }
}
void SaveCleintsDataToFileForDelete(string ClientsFile, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(ClientsFile, ios::out);
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
void SaveCleintsUpdateToFile(string ClientsFile, vector<CD> &vClients, string accountNumber)
{
    fstream myFile;
    myFile.open(ClientsFile, ios::out);
    if (myFile.is_open())
    {
        for (CD &cd : vClients)
        {
            if (cd.markForUpdating)
                cd = ChangeClientRecord(accountNumber);
            myFile << ConvertRecordToLineForClient(cd) << endl;
        }
        myFile.close();
    }
}
void SearchForClientsByAccountNumber(vector<CD> &vClients)
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
        ClientIsNotFoundStatement(accountNumber);
}
void ShowBalancesOfClients(vector<CD> &vClients)
{
    system("color 0f");
    if (isVectorEmpty(vClients))
        return;
    for (CD &cd : vClients)
    {
        PrintBalanceOfOneClient(vClients, cd, 't');
    }
    cout << "----------------------------------------------"
         << "----------------------------------------------" << endl;
}
void ShowBalanceOfOneClient(vector<CD> &vClients, enTransactionsMenue option)
{
    system("color 0f");
    if (isVectorEmpty(vClients))
    {
        ShowVectorIsEmpty();
    }

    string accountNumber = GetStringInput("\nPlease Enter Account Number: ");
    CD cd;
    if (FindClientByAccountNumber(vClients, cd, accountNumber))
        PrintBalanceOfOneClient(vClients, cd, 'l');
    else
        ClientIsNotFoundStatement(accountNumber);
}
void ShowBalancesStatement(vector<CD> &vClients)
{
    cout << "\n"
         << Tabs(2) << "Balances List (" << vClients.size() << ") Client(s)."
         << "\n____________________________________________________________________________________________\n"
         << "| " << setw(15) << left << "Account Number"
         << "| " << setw(40) << left << "Client Name"
         << "| " << setw(30) << left << "Balance"
         << "| "
         << "\n____________________________________________________________________________________________"
         << endl;
}
void ShowClientsListScreen(size_t ClientsNumber)
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
void ShowLogInScreen()
{
    system("cls");
    cout << "-----------------------------------------------------\n";
    cout << Tabs(2) << "Login Screen\n";
    cout << "-----------------------------------------------------\n";
}
void ShowNewBalance(CD &cd)
{
    cout << "\nDone Successfully, New Balance is " << cd.balance;
}
void ShowQuickWithdrawScreen()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Quick Withdraw\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] 20      [2] 50\n";
    cout << Tabs(1) << "[3] 100     [4] 200\n";
    cout << Tabs(1) << "[5] 400     [6] 600\n";
    cout << Tabs(1) << "[7] 800     [8] 1000\n";
    cout << Tabs(1) << "[9] Exit\n";
    cout << "===============================================================" << endl; //~ clear the buffer.
}

void Show_ATM_MainMenueScreen()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "ATM Main Menue Screen\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] Quick Withdraw.\n";
    cout << Tabs(1) << "[2] NormalWithdraw.\n";
    cout << Tabs(1) << "[3] Deposit.\n";
    cout << Tabs(1) << "[4] Check Balance.\n";
    cout << Tabs(1) << "[5] Logout.\n";
    cout << "===============================================================\n";
}
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option)
{
    switch (option)
    {
    case enTransactionsMenue::Deposite:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Check Balance Screen\n";
        cout << "----------------------------------------";
        break;
    case enTransactionsMenue::Withdraw:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Quick Withdraw\n";
        cout << "----------------------------------------";
        break;
    case enTransactionsMenue::BalanceOfOneClient:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Balance Of One Client\n";
        cout << "----------------------------------------";
        break;
    }
}
void ShowVectorIsEmpty()
{
    system("color 0c");
    cout << "\a";
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

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');

        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            MarkClientForUpdateByAccountNumber(vClients, accountNumber);
            SaveCleintsUpdateToFile(ClientsFile, vClients, accountNumber);

            //~ Refresh Clients
            vClients = LoadClientDataFromFileToVector(ClientsFile);
            system("color 0a");
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
