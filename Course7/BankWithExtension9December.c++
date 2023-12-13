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
string UsersFile = "UsersFile.txt";
enum enUserOrClient
{
    User = 1,
    Client = 2
};
enum enMainMenueForClients
{
    ShowClientList = 1,
    Add_New_Client = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Transactions = 6,
    Exit = 7
};
enum enMainMenueForUsers
{
    ShowClientList = 1,
    Add_New_Client = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Transactions = 6,
    ManageUsers = 7,
    Logout = 8
};
enum enManageUsersMenue
{
    UsersList = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUser = 5,
    MainMenue = 6
};
enum enTransactionsMenue
{
    Deposite = 1,
    Withdraw = 2,
    BalanceOfOneClient = 3,
    TotalBalance = 4,
    MainMenue = 5
};
enum FeatureStatus
{
    DISABLED = 0,
    ENABLED = 1
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

typedef struct stUserName
{
    string user_name;
    string password;
    short permissions = 1;
    bool markForDeleting = false;
    bool markForUpdating = false;
    double balance = 0;
} stUN;

void AddClients(vector<CD> &vClients, string ClientsFile, string delimiter = "#//#");
void AddNewClient(vector<CD> &vClients, string ClientsFile, string delimiter = "#//#");
CD AddNewClientData(vector<CD> &vClients);
void AddDataLineToFile(string ClientsFile, string dataLine);
void AddUsers(vector<stUN> &vUsers, string UsersFile, string delimiter = "#//#");
bool AreYouAgreed(string message, char agreed, char notAgreed);

CD ChangeClientRecord(string AccountNumber);
string ConvertRecordToLineForClient(CD cd, string delimiter = "#//#");
string ConvertRecordToLineForUser(stUN UN, string delimiter = "#//#");
CD ConvertClientLineToRecord(string line);
stUN ConvertUserLineToRecord(string line);
void ClientIsNotFoundStatement(string accountNumber);

void DeleteClientFromFileByAccountNumber(vector<CD> &vClients);
void DeleteUserFromFileByUsername(vector<stUN> &vUsers);

bool FindClientByAccountNumber(vector<CD> &vClients, string accountNumber);
bool FindClientByAccountNumberAndPinCode(vector<CD> &vClients, CD &cd);
bool FindUserByUsername(vector<stUN> &vUsers, stUN &UN, string user_name);
bool FindUserByUserNameAndPassword(vector<stUserName> &vUsers, stUN UN);

enManageUsersMenue GetManageUsersOption();
enMainMenueForClients GetMainOptionByUserForClients();
enMainMenueForUsers GetMainOptionByUserForUsers();
string GetStringInput(string prompt);
enTransactionsMenue GetTransactionOptionByUser();
int GetValidPositiveIntegerInRange(string message, short min, short max);
short GetValidPositiveShortIntegerInRange(string, short, short);
short GivePermissions(string message, short featureNumber);
void GoBackToMainMenueForClients(vector<CD> &vClients);
void GoBackToMainMenueForUsers(vector<stUN> &vUsers, vector<CD> &vClients);
void GoBackToManageMenueForUsers(vector<stUN> &vUsers);
void GoBackToTransactionsMenue(vector<CD> &vClients);

bool isVectorEmpty(vector<CD> &vClients);
bool isVectorEmpty(vector<stUN> &vUsers);

vector<CD> LoadClientDataFromFileToVector(string);
vector<stUN> LoadUserDataFromFileToVector(string);
void Log_in();

bool MarkClientForDeleteByAccountNumber(vector<CD> &vClients, string accountNumber);
bool MarkClientForUpdateByAccountNumber(vector<CD> &vClients, string accountNumber);

void PrintClientsData(vector<CD> &vClients);
void PrintOneClientDataLongitudinallyAndtransversely(CD &cd, char LongitudinallyAndtransversely);
void PrintOneUserDataLongitudinallyAndtransversely(stUN &UN, char LongitudinallyAndtransversely);
void PrintOneUserDataLongitudinallyAndtransversely(stUN &UN, char LongitudinallyAndtransversely);
void PrintUsersData(vector<stUN> &vUsers);
void PerformDeposit(vector<CD> &vClients);
void PerformFindUser(vector<stUN> &vUsers);
void PerformFindClient(vector<CD> &vClients);
void PerformMainMenueOptionForClients(vector<CD> &vClients);
short PerformPermission();
void PerformShowClientList(vector<CD> &vClients);
void PerformTransactions(vector<CD> &vClients);
void PerformTransactions(vector<stUN> &vUsers);
void PerformTransactionsMenueOptionsForClients(vector<CD> &vClients, enTransactionsMenue option);
void PerformUpdateClient(vector<CD> &vClients);
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
void ShowManageMenueOptionsScreen(enManageUsersMenue option, vector<stUN> &vUsers);
void ShowManageUsersMenueScreen();
void ShowNewBalance(CD &cd);
void ShowNewBalance(stUN &UN);
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option);
void ShowTransactionsMenueScreenForClients();
void ShowVectorIsEmpty();
vector<string> SplitString(string str, string delimeter = "#//#");

string Tabs(short numberOfTabs);

void UpdateClientByAccountNumber(vector<CD> &vClients);
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
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
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

    return UN;
}
void AddUsers(vector<stUN> &vUsers, string UsersFile, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        cout << "\nAdding New Client:\n\n";
        AddNewUser(vUsers, ClientsFile, delimiter);
        system("color 0a");
        addMore = AreYouAgreed("\n\aUser Added Successfuly, Do you want to add more clients? [Y/N] ", 'y', 'n');
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
    AddDataLineToFile(
        ClientsFile,
        ConvertRecordToLineForUser(
            AddNewUserData(vUsers)));
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

    return (tolower(choice) == 'y') ? true : false;
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

    if (FindClientByAccountNumber(vClients, accountNumber))
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

void EnterUserNameAndPassword(vector<stUN> &vUsers, vector<CD> &vClients)
{
    stUN UN;
    CD cd;

    while (true)
    {
        UN.user_name = cd.accountNumber = GetStringInput("\nEnter Username: ");
        UN.password = cd.pinCode = GetStringInput("\nEnter Password: ");

        if (FindUserByUserNameAndPassword(vUsers, UN))
            PerformMainMenueOptionForUsers(vUsers, vClients);
        else if (FindClientByAccountNumberAndPinCode(vClients, cd))
            PerformMainMenueOptionForClients(vClients);
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
bool FindUserByUserNameAndPassword(vector<stUserName> &vUsers, stUN UN)
{
    for (stUserName &UserName : vUsers)
    {
        if (UserName.user_name == UN.user_name && UserName.password == UN.password)
            return true;
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
enManageUsersMenue GetManageUsersOption()
{
    enManageUsersMenue option = (enManageUsersMenue)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 8]: ", 1, 6);
    return option;
}
enMainMenueForClients GetMainOptionByUserForClients()
{
    enMainMenueForClients userChoose = (enMainMenueForClients)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 7]: ", 1, 7);
    return userChoose;
}
enMainMenueForUsers GetMainOptionByUserForUsers()
{
    enMainMenueForUsers option = (enMainMenueForUsers)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 8]: ", 1, 8);
    return option;
}
enTransactionsMenue GetTransactionOptionByUser()
{
    enTransactionsMenue option = (enTransactionsMenue)GetValidPositiveShortIntegerInRange("\nChoose what do you want to do? [1 to 4]: ", 1, 5);
    return option;
}
short GivePermissions(string message, short featureNumber)
{
    int permission = 0;
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
void GoBackToMainMenueForClients(vector<CD> &vClients)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformMainMenueOptionForClients(vClients);
}
void GoBackToMainMenueForUsers(vector<stUN> &vUsers, vector<CD> &vClients)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformMainMenueOptionForUsers(vUsers, vClients);
}
void GoBackToManageMenueForUsers(vector<stUN> &vUsers)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    PerformManageUsersMenueScreen(vUsers);
}
void GoBackToTransactionsMenue(vector<CD> &vClients)
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause > 0");
    PerformTransactions(vClients);
}
void GoBackToTransactionsMenue(vector<stUN> &vUsers)
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause > 0");
    PerformTransactions(vUsers);
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
    vector<CD> vClients;
    vector<stUN> vUsers;

    vUsers = LoadUserDataFromFileToVector(UsersFile);
    vClients = LoadClientDataFromFileToVector(ClientsFile);

    ShowLogInScreen();
    EnterUserNameAndPassword(vUsers, vClients);
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

void PerformAddNewClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::Add_New_Client);
    AddClients(vClients, ClientsFile);
    SaveCleintsDataToFile(ClientsFile, vClients);
}
void PerformAddNewUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreenForUsers(enManageUsersMenue::AddNewUser);
    AddUsers(vUsers, UsersFile);
    SaveUsersDataToFile(UsersFile, vUsers);
}
void PerformDeleteClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::DeleteClient);
    DeleteClientFromFileByAccountNumber(vClients);
}
void PerformDeleteUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreenForUsers(enManageUsersMenue::DeleteUser);
    DeleteUserFromFileByUsername(vUsers);
}
void PerformDeposit(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if (FindClientByAccountNumber(vClients, accountNumber))
    {
        cout << "\nThe Following are the client details:\n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        short depositAmount = GetValidPositiveIntegerInRange("\n\nPlease Enter Deposit Amount: ", 1, 32000);
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
void PerformDeposit(vector<stUN> &vUsers)
{
    stUN UN;
    string username = GetStringInput("Please Enter Username: ");

    if (FindUserByUsername(vUsers, UN, username))
    {
        cout << "\nThe Following are the client details:\n";
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');
        short depositAmount = GetValidPositiveIntegerInRange("\n\nPlease Enter Deposit Amount: ", 1, 32000);
        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'));
            UN.balance += depositAmount;

        SaveUsersDataToFile(UsersFile, vUsers);
        ShowNewBalance(UN);
        return;
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
void PerformExit()
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::Exit);
}
void PerformLogout()
{
    system("cls");

}
void PerformFindClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::FindClient);
    SearchForClientsByAccountNumber(vClients);
}
void PerformFindUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreenForUsers(enMainMenueForUsers::FindUser);
    SearchForUserByUsername(vUsers);
}
void PerformMainMenueOptionForClients(vector<CD> &vClients)
{
    system("color 0f");
    system("cls");
    ShowMainMenueScreenForClients();
    vClients = LoadClientDataFromFileToVector(ClientsFile);

    switch (GetMainOptionByUserForClients())
    {
    case enMainMenueForClients::ShowClientList:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(vClients);
        }
        PerformShowClientList(vClients);
        GoBackToMainMenueForClients(vClients);
        break;
    case enMainMenueForClients::Add_New_Client:
        PerformAddNewClient(vClients);
        GoBackToMainMenueForClients(vClients);
        break;
    case enMainMenueForClients::DeleteClient:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(vClients);
        }
        PerformDeleteClient(vClients);
        GoBackToMainMenueForClients(vClients);
        break;
    case enMainMenueForClients::UpdateClientInfo:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(vClients);
        }
        PerformUpdateClient(vClients);
        GoBackToMainMenueForClients(vClients);
        break;
    case enMainMenueForClients::FindClient:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(vClients);
        }
        PerformFindClient(vClients);
        GoBackToMainMenueForClients(vClients);
        break;
    case enMainMenueForClients::Transactions:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForClients(vClients);
        }
        PerformTransactions(vClients);
        break;
    case enMainMenueForClients::Exit:
        PerformExit();
        break;
    }
}
void PerformMainMenueOptionForUsers(vector<stUN> &vUsers, vector<CD> &vClients)
{
    system("color 0f");
    system("cls");
    ShowMainMenueScreenForUsers();

    vClients = LoadClientDataFromFileToVector(ClientsFile);

    switch (GetMainOptionByUserForUsers())
    {
    case enMainMenueForUsers::ShowClientList:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(vUsers, vClients);
        }
        PerformShowClientList(vClients);
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
    case enMainMenueForUsers::Add_New_Client:
        PerformAddNewClient(vClients);
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
    case enMainMenueForUsers::DeleteClient:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(vUsers, vClients);
        }
        PerformDeleteClient(vClients);
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
    case enMainMenueForUsers::UpdateClientInfo:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(vUsers, vClients);
        }
        PerformUpdateClient(vClients);
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
    case enMainMenueForUsers::FindClient:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(vUsers, vClients);
        }
        PerformFindClient(vClients);
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
    case enMainMenueForUsers::Transactions:
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(vUsers, vClients);
        }
        PerformTransactions(vClients);
        break;
    case enMainMenueForUsers::ManageUsers:
        PerformManageUsersMenueScreen(vUsers);
    case enMainMenueForUsers::Logout:
        PerformExit();
        break;
    }
}
void PerformManageUsersMenueScreen(vector<stUN> &vUsers)
{
    system("color 0f");
    system("cls");
    ShowManageUsersMenueScreen();

    vUsers = LoadUserDataFromFileToVector(UsersFile);

    //! i don't need to load date from file to vector as E:/Hamza told me so i won't write this here:
    //*     vUsers = LoadUserDataFromFileToVector(UsersFile);
    //! cause i did that in PerformMainMenueForUsers() but i think that i should write again in Manage cause if i did sth
    //! like adding new user so, i'll need to update the vector cause after every function like adding or updating i need to
    //! to save the vector data in the file and then it'll go back to PerformManageUsersMenueScreen() it'll need to make sure
    //! that i updated the vector

    switch (GetManageUsersOption())
    {
    case enManageUsersMenue::UsersList:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(vUsers);
        }
        PerformShowUserList(vUsers);
        GoBackToManageMenueForUsers(vUsers);
        break;
    case enManageUsersMenue::AddNewUser:
        PerformAddNewUser(vUsers);
        GoBackToManageMenueForUsers(vUsers);
        break;
    case enManageUsersMenue::DeleteUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(vUsers);
        }
        PerformDeleteUser(vUsers);
        GoBackToManageMenueForUsers(vUsers);
        break;
    case enManageUsersMenue::UpdateUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(vUsers);
        }
        PerformUpdateClient(vUsers);
        GoBackToManageMenueForUsers(vUsers);
        break;
    case enManageUsersMenue::FindUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(vUsers);
        }
        PerformFindUser(vUsers);
        GoBackToManageMenueForUsers(vUsers);
        break;
    case enManageUsersMenue::MainMenue:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(vUsers);
        }
        PerformTransactions(vUsers);
        break;
    }
}
short PerformPermission()
{
    short permission = GivePermissions("Do you want to give full access? [y/n] ", 0);

    if (permission == -1)
        return permission;

    short length = GetValidPositiveIntegerInRange("\nPlease enter the number of the features: ", 1, 10);

    for (short i = 1; i <= length; ++i)
    {
        permission = GivePermissions("Do you want to give access to Feature[" + to_string(i) + "] ? [y/n] ", i);
    }

    return permission;
}
void PerformShowClientList(vector<CD> &vClients)
{
    system("cls");
    PrintClientsData(vClients);
}
void PerformShowUserList(vector<stUN> &vUsers)
{
    system("cls");
    ShowUsersListScreen(vUsers.size());
    PrintUsersData(vUsers);
}
void PerformTransactions(vector<CD> &vClients)
{
    system("color 0f");
    system("cls");
    ShowTransactionsMenueScreenForClients();
    enTransactionsMenue option;
    PerformTransactionsMenueOptionsForClients(vClients, (option = GetTransactionOptionByUser()));
}
void PerformTransactions(vector<stUN> &vUsers)
{
    system("color 0f");
    system("cls");
    ShowTransactionsMenueScreenForClients();
    enTransactionsMenue option;
    PerformTransactionsMenueOptionsForUsers(vUsers, (option = GetTransactionOptionByUser()));
}
void PerformTransactionsMenueOptionsForClients(vector<CD> &vClients, enTransactionsMenue option)
{
    system("cls");
    ShowTransactionsMenueOptionsScreen(option);

    switch (option)
    {
    case enTransactionsMenue::Deposite:
        PerformDeposit(vClients);
        GoBackToTransactionsMenue(vClients);
        break;
    case enTransactionsMenue::Withdraw:
        PerformWithdraw(vClients);
        GoBackToTransactionsMenue(vClients);
        break;
    case enTransactionsMenue::BalanceOfOneClient:
        ShowBalanceOfOneClient(vClients, option);
        GoBackToTransactionsMenue(vClients);
        break;
    case enTransactionsMenue::TotalBalance:
        ShowBalancesList(vClients);
        GoBackToTransactionsMenue(vClients);
        break;
    case enTransactionsMenue::MainMenue:
        GoBackToMainMenueForClients(vClients);
        break;
    }
}
void PerformTransactionsMenueOptionsForUsers(vector<stUN> &vUsers, vector<CD> &vClients, enTransactionsMenue option)
{
    system("cls");
    ShowTransactionsMenueOptionsScreen(option);

    switch (option)
    {
    case enTransactionsMenue::Deposite:
        PerformDeposit(vUsers);
        GoBackToTransactionsMenue(vUsers);
        break;
    case enTransactionsMenue::Withdraw:
    {
        PerformWithdraw(vUsers);
        GoBackToTransactionsMenue(vUsers);
        break;
    case enTransactionsMenue::BalanceOfOneClient:
    {
        ShowBalanceOfOneClient(vUsers, option);
        GoBackToTransactionsMenue(vUsers);
        break;
    case enTransactionsMenue::TotalBalance:
        ShowBalancesList(vUsers);
        GoBackToTransactionsMenue(vUsers);
        break;
    case enTransactionsMenue::MainMenue:
        GoBackToMainMenueForUsers(vUsers, vClients);
        break;
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
    ShowMainMenueOptionsScreenForUsers(enMainMenueForClients::UpdateClientInfo);
    UpdateUserByUsername(vUsers);
}
void PerformUpdateUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreenForUsers(enMainMenueForUsers::UpdateUserInfo);
    UpdateUserByUsername(vUsers);
}
void PerformWithdraw(vector<CD> &vClients)
{
    string accountNumber = GetStringInput("\nPlease enter account Number: ");
    CD cd;
    if (FindClientByAccountNumberAndPinCode(vClients, cd, accountNumber))
    {
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
        short depositAmount = GetValidPositiveIntegerInRange("\nPlease Enter Deposit Amount: ", 1, 60000);
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
void PerformWithdraw(vector<stUN> &vUsers)
{
    string username = GetStringInput("\nPlease enter account Number: ");
    stUN UN;
    
    if (FindUserByUsername(vUsers, UN, username))
    {
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');
        short depositAmount = GetValidPositiveIntegerInRange("\nPlease Enter Deposit Amount: ", 1, 60000);
        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            cd.balance -= depositAmount;
            SaveCleintsDataToFile(ClientsFile, vClients);
            ShowNewBalance(cd);
            return;
        }
    }
    else
        UserIsNotFoundStatement(username);
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
    }
    cout << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}
void PrintUsersData(vector<stUN> &vUsers)
{
    system("color 0f");
    ShowUsersListScreen(vUsers.size());
    for (stUserName &UserName : vUsers)
    {
        PrintOneUserDataLongitudinallyAndtransversely(UserName, 't');
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
        cout << "\nThe Following are the Client Details \n";
        cout << "\nAccount Number: " << cd.accountNumber;
        cout << "\nPin Code      : " << cd.pinCode;
        cout << "\nName          : " << cd.name;
        cout << "\nPhone         : " << cd.phone;
        cout << "\nBalance       : " << cd.balance;
    }
}
void PrintOneUserDataLongitudinallyAndtransversely(stUN &UN, char LongitudinallyAndtransversely)
{
    system("color 0f");

    if (LongitudinallyAndtransversely == 't')
    {
        cout << "| " << setw(30) << left << UN.user_name
             << "| " << setw(15) << left << UN.password
             << "| " << setw(40) << left << UN.permissions
             << "|" << endl;
    }
    else if (LongitudinallyAndtransversely == 'l')
    {
        cout << "\nThe Following are the Client Details \n";
        cout << "\nUser Name  : " << UN.user_name;
        cout << "\nPassword   : " << UN.password;
        cout << "\nPermissions: " << UN.permissions;
    }
}

stUserName ReadNewUserData(vector<stUN> &vUsers)
{
    stUN UN;
    string userName = GetStringInput("Enter user name: ");

    while (FindUserByUserNameAndPassword(vUsers, UN, userName))
    {
    }

    UN.user_name = userName;

    cout << "Enter Password: ";
    getline(cin, UN.password);

    return UN;
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
void SaveUserDataToFileForDelete(string UsersFile, vector<stUN> &vUsers)
{
    fstream myFile;
    myFile.open(UsersFile, ios::out);
    if (myFile.is_open())
    {

        for (stUserName &UserName : vUsers)
        {
            if (!UserName.markForDeleting)
            {
                string lineOfRecord = ConvertRecordToLineForUser(UserName);
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
void SaveUsersUpdateToFile(string UsersFile, vector<stUN> &vUsers, string username)
{
    fstream myFile;
    myFile.open(UsersFile, ios::out);
    if (myFile.is_open())
    {
        for (stUserName &UserName : vUsers)
        {
            if (UserName.markForUpdating)
                UserName = ChangeUserRecord(username);
            myFile << ConvertRecordToLineForUser(UserName) << endl;
        }
        myFile.close();
    }
}
void SaveUsersDataToFile(string UsersFile, vector<stUN> &vUsers)
{
    fstream myFile;
    myFile.open(UsersFile, ios::out | ios::app); //! الحمد لله غيرت المود للإضافة بدلا من الكتابة او القراءة

    if (myFile.is_open())
    {
        string lineOfRecord;
        for (stUserName &UserName : vUsers)
        {
            lineOfRecord = ConvertRecordToLineForUser(UserName);
            myFile << lineOfRecord << endl;
        }
    }
}
void SearchForClientsByAccountNumber(vector<CD> &vClients)
{
    CD cd;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string accountNumber = GetStringInput("\nPlease Enter Account Number To Search For: ");

    if (FindClientByAccountNumberAndPinCode(vClients, cd, accountNumber))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneClientDataLongitudinallyAndtransversely(cd, 'l');
    }
    else
        ClientIsNotFoundStatement(accountNumber);
}
void SearchForUserByUsername(vector<stUN> &vUsers)
{
    stUN UN;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string username = GetStringInput("\nPlease Enter Username To Search For: ");

    if (FindUserByUsername(vUsers, username))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');
    }
    else
        UserIsNotFoundStatement(username);
}
void ShowBalancesList(vector<CD> &vClients)
{
    ShowBalancesStatement(vClients);
    ShowBalancesOfClients(vClients);
}
void ShowBalancesList(vector<stUN> &vUsers))
{
    ShowBalancesStatement(vClients);
    ShowBalancesOfClients(vClients);
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
    if (FindClientByAccountNumberAndPinCode(vClients, cd, accountNumber))
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
void ShowUsersListScreen(size_t vUsers)
{
    cout << "\n"
         << Tabs(2) << "Users List [" << sizeof(vUsers) << "] User(s).\n"
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl
         << "| " << setw(30) << left << "Username"
         << "| " << setw(15) << left << "Password "
         << "| " << setw(40) << left << "Permission "
         << "|" << endl
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}
void ShowLogInScreen()
{
    cout << "-----------------------------------------------------\n";
    cout << Tabs(2) << "Login Screen\n";
    cout << "-----------------------------------------------------\n";
}
void ShowNewBalance(CD &cd)
{
    cout << "\nDone Successfully, New Balance is " << cd.balance;
}
void ShowNewBalance(stUN &UN)
{
    cout << "\nDone Successfully, New Balance is " << UN.balance;
}
void ShowMainMenueScreenForClients()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Main Menueo Screen\n";
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
void ShowMainMenueScreenForUsers()
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
    cout << Tabs(1) << "[7] Manage Users.\n";
    cout << Tabs(1) << "[8] Logout.\n";
    cout << "===============================================================" << endl; //~ clear the buffer.
}
void ShowMainMenueOptionsScreenForClients(enMainMenueForClients option)
{
    switch (option)
    {
    case enMainMenueForClients::Add_New_Client:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Add New Clients Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForClients::DeleteClient:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Delete Client Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForClients::UpdateClientInfo:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Update Client Info Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForClients::FindClient:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Find Client Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForClients::Exit:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Program Ends:-)\n";
        cout << "----------------------------------------\n";
        break;
    }
}
void ShowManageMenueOptionsScreen(enManageUsersMenue option, vector<stUN> &vUsers)
{
    switch (option)
    {
    case enManageUsersMenue::DeleteUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Delete User Screen\n";
        cout << "----------------------------------------";
        break;
    case enManageUsersMenue::UpdateUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Update User Info Screen\n";
        cout << "----------------------------------------";
        break;
    case enManageUsersMenue::FindUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Find User Screen\n";
        cout << "----------------------------------------";
        break;
    }
}
void ShowManageMenueOptionsScreenForUsers(enManageUsersMenue option)
{
    switch (option)
    {
    case enManageUsersMenue::AddNewUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Add New User Screen\n";
        cout << "----------------------------------------";
        break;
    case enManageUsersMenue::DeleteUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Delete User Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForUsers::UpdateClientInfo:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Update User Info Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForUsers::FindClient:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Find User Screen\n";
        cout << "----------------------------------------";
        break;
    }
}
void ShowManageUsersMenueScreen()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Manage Users Menue Screen\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] List Users.\n";
    cout << Tabs(1) << "[2] Add New User.\n";
    cout << Tabs(1) << "[3] Delete User.\n";
    cout << Tabs(1) << "[4] Update User.\n";
    cout << Tabs(1) << "[5] Find User.\n";
    cout << Tabs(1) << "[6] Main Menue.\n";
    cout << "===============================================================" << endl; //~ clear the buffer.
}
void ShowTransactionsMenueScreenForClients()
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
void ShowTransactionsMenueScreenForUsers()
{
    cout << "===============================================================\n";
    cout << Tabs(2) << "Transactions Menue Screen\n";
    cout << "===============================================================\n";
    cout << Tabs(1) << "[1] Deposite.\n";
    cout << Tabs(1) << "[2] Withdraw.\n";
    cout << Tabs(1) << "[3] Balance Of One User.\n";
    cout << Tabs(1) << "[4] Total Balances.\n";
    cout << Tabs(1) << "[5] Main Menue.\n";
    cout << "===============================================================\n";
}
void ShowTransactionsMenueOptionsScreen(enTransactionsMenue option)
{
    switch (option)
    {
    case enTransactionsMenue::Deposite:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Depsit Screen\n";
        cout << "----------------------------------------";
        break;
    case enTransactionsMenue::Withdraw:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Withdraw Screen\n";
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
void UpdateUserByUsername(vector<stUN> &vUsers)
{
    stUN UN;
    cout << "\nUpdate User\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string username = GetStringInput("\nPlease Enter Username To Update it: ");

    if (FindUserByUsername(vUsers, UN, username))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');

        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            MarkUserForUpdateByUsername(vUsers, username);
            SaveUsersUpdateToFile(UsersFile, vUsers, username);

            //~ Refresh Clients
            vUsers = LoadUserDataFromFileToVector(UsersFile);
            system("color 0a");
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
        UserIsNotFoundStatement(username);
}
void UserIsNotFoundStatement(string username)
{
    cout << "\nUser with Username (" << username << ") is Not Found!";
    cout << "\a";
    system("color 0c");
}