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

enum enMainMenueForClients
{
    show_client_list = 1,
    add_new_client = 2,
    deleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    transactions = 6,
    Exit = 7
};
enum enMainMenueForUsers
{
    ShowClientList = 1,
    Add_New_Client = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    find_client = 5,
    Transactions = 6,
    ManageUsers = 7,
    Logout = 8
};
enum enManageUsersMenue
{
    UsersList = 1,
    add_New_User = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUser = 5,
    mainMenue = 6
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
} stUN;

void AddClients(vector<CD> &vClients, string ClientsFile, string delimiter = "#//#");
void AddNewClient(vector<CD> &vClients, string ClientsFile, string delimiter = "#//#");
CD AddNewClientData(vector<CD> &vClients);
void AddDataLineToFile(string ClientsFile, string dataLine);
void AddNewUser(vector<stUN> &vUsers, string UsersFile, string delimiter);
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

bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber);
bool FindClientByAccountNumberAndPinCode(vector<CD> &vClients, CD &cd);
bool FindUserByUsername(vector<stUN> &vUsers, stUN &UN, string user_name);
bool FindUserByUserNameAndPassword(vector<stUserName> &vUsers, stUN &UN);

enManageUsersMenue GetManageUsersOption();
enMainMenueForClients GetMainOptionByUserForClients();
enMainMenueForUsers GetMainOptionByUserForUsers();
string GetStringInput(string prompt);
enTransactionsMenue GetTransactionOptionByUser();
int GetValidPositiveIntegerInRange(string, int, int);
short GivePermissions(string message, short featureNumber);
void GoBackToMainMenueForClients(CD &cd);
void GoBackToMainMenueForUsers(stUserName &UN, CD &cd);
void GoBackToManageMenueForUsers(stUserName &UN, CD &cd);
void GoBackToTransactionsMenue(vector<CD> &vClients);

bool isVectorEmpty(vector<CD> &vClients);
bool isVectorEmpty(vector<stUN> &vUsers);
bool IsFeatureEnabled(const stUN &UN, short feature);

vector<CD> LoadClientDataFromFileToVector(string);
vector<stUN> LoadUserDataFromFileToVector(string);
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

void SaveClientsDataToFile(string ClientsFile, vector<CD> &vClients);
void SaveClientsDataToFileForDelete(string ClientsFile, vector<CD> &vClients);
void SaveClientsUpdateToFile(string ClientsFile, vector<CD> &vClients, string accountNumber);
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

void EnterUserNameAndPassword(vector<stUN> &vUsersData, vector<CD> &vClientsData)
{
    stUN UN;
    CD cd;

    while (true)
    {
        UN.user_name = cd.accountNumber = GetStringInput("\nEnter Username: ");
        UN.password = cd.pinCode = GetStringInput("\nEnter Password: ");

        if (FindUserByUserNameAndPassword(vUsersData, UN))
            PerformMainMenueOptionForUsers(UN, cd);
        else if (FindClientByAccountNumberAndPinCode(vClientsData, cd))
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
    vector<stUN> vUsersData;

    vUsersData = LoadUserDataFromFileToVector(UsersFile);
    vClientsData = LoadClientDataFromFileToVector(ClientsFile);

    ShowLogInScreen();
    EnterUserNameAndPassword(vUsersData, vClientsData);
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
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::add_new_client);
    AddClients(vClients, ClientsFile);
    SaveCleintsDataToFile(ClientsFile, vClients);
}
void PerformAddNewUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreen(enManageUsersMenue::add_New_User);
    AddUsers(vUsers, UsersFile);
    SaveUsersDataToFile(UsersFile, vUsers);
}
void PerformDeleteClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::deleteClient);
    DeleteClientFromFileByAccountNumber(vClients);
}
void PerformDeleteUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreen(enManageUsersMenue::DeleteUser);
    DeleteUserFromFileByUsername(vUsers);
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
void PerformFindClient(vector<CD> &vClients)
{
    system("cls");
    ShowMainMenueOptionsScreenForClients(enMainMenueForClients::FindClient);
    SearchForClientsByAccountNumber(vClients);
}
void PerformFindUser(vector<stUN> &vUsers)
{
    system("cls");
    ShowManageMenueOptionsScreen(enManageUsersMenue::FindUser);
    SearchForUserByUsername(vUsers);
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
void PerformMainMenueOptionForUsers(stUserName &UN, CD &cd)
{
    vector<stUN> vUsers;
    vector<CD> vClients;
    
    vUsers = LoadUserDataFromFileToVector(UsersFile);
    vClients = LoadClientDataFromFileToVector(ClientsFile);

    system("color 0f");
    system("cls");
    ShowMainMenueScreenForUsers();

    switch (GetMainOptionByUserForUsers())
    {
    case enMainMenueForUsers::ShowClientList:
        if (!IsFeatureEnabled(UN, 1))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformShowClientList(vClients);
        break;
    case enMainMenueForUsers::Add_New_Client:
        if (!IsFeatureEnabled(UN, 2))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformAddNewClient(vClients);
        GoBackToMainMenueForUsers(UN, cd);
        break;
    case enMainMenueForUsers::DeleteClient:
        if (!IsFeatureEnabled(UN, 3))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformDeleteClient(vClients);
        GoBackToMainMenueForUsers(UN, cd);
        break;
    case enMainMenueForUsers::UpdateClient:
        if (!IsFeatureEnabled(UN, 4))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformUpdateClient(vClients);
        GoBackToMainMenueForUsers(UN, cd);
        break;
    case enMainMenueForUsers::find_client:
        if (!IsFeatureEnabled(UN, 5))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformFindClient(vClients);
        GoBackToMainMenueForUsers(UN, cd);
        break;
    case enMainMenueForUsers::Transactions:
        if (!IsFeatureEnabled(UN, 6))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        if (isVectorEmpty(vClients))
        {
            ShowVectorIsEmpty();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformTransactions(vClients, cd);
        break;
    case enMainMenueForUsers::ManageUsers:
        if (!IsFeatureEnabled(UN, 7))
        {
            ShowAccessIsDenied();
            GoBackToMainMenueForUsers(UN, cd);
        }
        PerformManageUsersMenueScreen(UN, cd);
    case enMainMenueForUsers::Logout:
        Log_in();
    }
}
void PerformManageUsersMenueScreen(stUserName &UN, CD &cd)
{
    system("color 0f");
    system("cls");
    ShowManageUsersMenueScreen();

    vector<stUN> vUsers;
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
            GoBackToManageMenueForUsers(UN, cd);
        }
        PerformShowUserList(vUsers);
        GoBackToManageMenueForUsers(UN, cd);
        break;
    case enManageUsersMenue::add_New_User:
        PerformAddNewUser(vUsers);
        GoBackToManageMenueForUsers(UN, cd);
        break;
    case enManageUsersMenue::DeleteUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(UN, cd);
        }
        PerformDeleteUser(vUsers);
        GoBackToManageMenueForUsers(UN, cd);
        break;
    case enManageUsersMenue::UpdateUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(UN, cd);
        }
        PerformUpdateUser(vUsers);
        GoBackToManageMenueForUsers(UN, cd);
        break;
    case enManageUsersMenue::FindUser:
        if (isVectorEmpty(vUsers))
        {
            ShowVectorIsEmpty();
            GoBackToManageMenueForUsers(UN, cd);
        }
        PerformFindUser(vUsers);
        GoBackToManageMenueForUsers(UN, cd);
        break;
    case enManageUsersMenue::mainMenue:
        PerformMainMenueOptionForUsers(UN, cd);
    }
}
stUN PerformPermission(stUN &UN)
{
    UN.permissions |= GivePermissions("\nDo you want to give full access? [y/n] ", 0);

    if (UN.permissions == -1)
        return UN;

    cout << "\nDo you want to give full access to:\n";
    UN.permissions |= GivePermissions("\nShow Client List? [y/n] ", 1);
    UN.permissions |= GivePermissions("\nAdd New Client? [y/n] ", 2);
    UN.permissions |= GivePermissions("\nDelete Client? [y/n] ", 3);
    UN.permissions |= GivePermissions("\nUpdate Client? [y/n] ", 4);
    UN.permissions |= GivePermissions("\nFind Client? [y/n] ", 5);
    UN.permissions |= GivePermissions("\nTransactions? [y/n] ", 6);
    UN.permissions |= GivePermissions("\nManage Users? [y/n] ", 7);

    return UN;
}
void PerformShowClientList(vector<CD> &vClients)
{
    system("cls");
    PrintClientsData(vClients);
}
void PerformShowUserList(vector<stUN> &vUsers)
{
    //!     i need to fill this UN so isFeatureEnabled() can take it asa an argument, and i'll take it from the login function
    //!     isFeatureEnabled(UN, featureNumber);
    system("cls");
    ShowUsersListScreen(vUsers.size());
    PrintUsersData(vUsers);
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

void SaveClientsDataToFile(string ClientsFile, vector<CD> &vClients)
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
void SaveClientsDataToFileForDelete(string ClientsFile, vector<CD> &vClients)
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

    if (FindClientByAccountNumber(vClients, cd, accountNumber))
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

    if (FindUserByUsername(vUsers, UN, username))
    {
        cout << "\nThe Following are the Client Details \n";
        PrintOneUserDataLongitudinallyAndtransversely(UN, 'l');
    }
    else
        UserIsNotFoundStatement(username);
}
void ShowAccessIsDenied()
{
    system("cls");
    system("color 0c");
    cout << "\a";
    cout << "\n------------------------------------------------";
    cout << "\nAccess Denied,";
    cout << "\nYou Don't Have Permissions To Do This, ";
    cout << "\nPlease Contact Your Admin.";
    cout << "\n------------------------------------------------";
}
void ShowBalancesList(vector<CD> &vClients)
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
    system("cls");
    cout << "-----------------------------------------------------\n";
    cout << Tabs(2) << "Login Screen\n";
    cout << "-----------------------------------------------------\n";
}
void ShowNewBalance(CD &cd)
{
    cout << "\nDone Successfully, New Balance is " << cd.balance;
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
    case enMainMenueForClients::add_new_client:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Add New Clients Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForClients::deleteClient:
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
    }
}
void ShowManageMenueOptionsScreen(enManageUsersMenue option)
{
    switch (option)
    {
    case enManageUsersMenue::add_New_User:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Add New User Screen\n";
        cout << "----------------------------------------";
        break;
    case enManageUsersMenue::DeleteUser:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Delete User Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForUsers::UpdateClient:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Update User Info Screen\n";
        cout << "----------------------------------------";
        break;
    case enMainMenueForUsers::find_client:
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