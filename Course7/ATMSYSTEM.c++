//!  All Functions Definitions and Decleration are ordered alphabetically ☺ ☻ :-)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

string ClientsFile = "Clients.txt";

enum en_ATM_MainMenue
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
    string pinCode;
    int balance = 1;
}CD;
 
CD CurrentClient;

bool AreYouAgreed(string message, char agreed, char notAgreed);

string ConvertRecordToLineForClient(CD cd, string delimiter = "#//#");
CD ConvertClientLineToRecord(string line);
void ClientIsNotFoundStatement(string accountNumber);

void EnterِAccountNumberAndPinCode(vector<CD> vClientsData);
bool FindClientByAccountNumber(vector<CD> &vClients, CD &cd, string accountNumber);
bool FindClientByAccountNumberAndPinCode(vector<CD> &vClients, CD &cd);


void GoBackTo_ATM_MainMenue(CD &cd);
string GetStringInput(string prompt);
int GetValidPositiveIntegerInRange(string, int, int);
enQuickWithdraw GetQuickWithdrawOption();
void GoBackToMainMenueForClients(CD &cd);
enQuickWithdraw GetQuickWithdrawOption();


bool isVectorEmpty(vector<CD> vClients);

vector<CD> LoadClientDataFromFileToVector(string);
void Log_in();

void Perform_ATM_MainMenueOptions(vector<CD>, CD);
void PerformDeposit(vector<CD> &vClients);
void PerformQuickWithdraw(vector<CD> &vClients, enQuickWithdraw option);
void PerformUpdateClient(vector<CD> &vClients);
void PerformWithdraw(vector<CD> &vClients);

void SaveCleintsDataToFile(string ClientsFile, vector<CD> &vClients);
void Show_ATM_MainMenueScreen();
void Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue option);
void ShowBalance(CD cd);
void ShowNewBalance(CD);
void ShowClientsListScreen(size_t);
void ShowLogInScreen();
void ShowMainMenueScreenForClients();
void ShowNewBalance(CD cd);
void ShowVectorIsEmpty();
vector<string> SplitString(string str, string delimeter = "#//#");

string Tabs(short numberOfTabs);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main()
{
    Log_in();
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

 
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

void ClientIsNotFoundStatement(string accountNumber)
{
    cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
    cout << "\a";
    system("color 0c");
}
 
 

void EnterِAccountNumberAndPinCode(vector<CD> vClientsData)
{
    while (true)
    {
        CurrentClient.accountNumber = GetStringInput("\nEnter Account Number: ");
        CurrentClient.pinCode = GetStringInput("\nEnter Pin Code: ");

        if (FindClientByAccountNumberAndPinCode(vClientsData, CurrentClient))
            Perform_ATM_MainMenueOptions(vClientsData, CurrentClient);
            
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
 
en_ATM_MainMenue Get_ATM_Option()
{
    en_ATM_MainMenue userChoose = (en_ATM_MainMenue)GetValidPositiveIntegerInRange("\nChoose what do you want to do? [1 to 5]: ", 1, 5);
    return userChoose;
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
 
void GoBackTo_ATM_MainMenue(vector<CD> vClients, CD cd)
{
    cout << "\n\nPress any key to back to main menue...";
    system("pause > 0");
    Perform_ATM_MainMenueOptions(vClients, CurrentClient);
}
 
bool isAmountExceedsTheBalance(short balance, short amount)
{
    if (amount > balance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to: " << balance
             << "\nPlease Enter another amount: ";
    }
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
void Log_in()
{
    vector<CD> vClientsData;

    vClientsData = LoadClientDataFromFileToVector(ClientsFile);

    ShowLogInScreen();
    EnterِAccountNumberAndPinCode(vClientsData);
}

void PerformDeposit(vector<CD> &vClients)
{
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
            ShowBalance(CurrentClient);
            return;
        }
} 
    
void Perform_ATM_MainMenueOptions(vector<CD> vClients, CD cd)
{
    system("cls");
    Show_ATM_MainMenueScreen();
    
    vClients = LoadClientDataFromFileToVector(ClientsFile);

    switch ((Get_ATM_Option()))
    {
    case en_ATM_MainMenue::QuickWithdraw:
        Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue::QuickWithdraw);
        PerformQuickWithdraw(vClients, GetQuickWithdrawOption());
        GoBackTo_ATM_MainMenue(cd);
        break;
    case en_ATM_MainMenue::NormalWithdraw:
        Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue::NormalWithdraw);
        PerformWithdraw(vClients);
        GoBackTo_ATM_MainMenue(cd);
        break;
    case en_ATM_MainMenue::Deposit:
        Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue::Deposit);
        PerformDeposit(vClients);
        GoBackTo_ATM_MainMenue(cd);
        break;
    case en_ATM_MainMenue::ChckBalance:
        Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue::ChckBalance);
        ShowBalance(CurrentClient);
        GoBackTo_ATM_MainMenue(cd);
        break;
    case en_ATM_MainMenue::Logout:
        Log_in();
    }
}  
void PerformQuickWithdraw(vector<CD> &vClients, enQuickWithdraw option)
{    
    system("cls");

    ShowQuickWithdrawScreen();
    ShowBalance(CurrentClient);

    switch(option)
    {
    case enQuickWithdraw::the20:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 20;
        break;
    case enQuickWithdraw::the50:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 50;
        break;
    case enQuickWithdraw::the100:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 100;
        break;
    case enQuickWithdraw::the200:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 200;
        break;
    case enQuickWithdraw::the400:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 400;
        break;
    case enQuickWithdraw::the600:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 600;
        break;
    case enQuickWithdraw::the800:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 800;
        break;
    case enQuickWithdraw::the1000:
        if(AreYouAgreed("\nAre you sure you want to perform this transaction? [y/n] ", 'y', 'n'))
            CurrentClient.balance -= 1000;
        break;
    }
    SaveCleintsDataToFile(ClientsFile, vClients);
    ShowNewBalance(CurrentClient);
}
void PerformWithdraw(vector<CD> &vClients, enQuickWithdraw currency)
{
    short withDrawAmount = GetValidPositiveIntegerInRange("\nPlease Enter Withdraw Amount: ", 1, 32000);

    if(isAmountExceedsTheBalance(CurrentClient.balance, withDrawAmount))
    {
        if (AreYouAgreed("\nAre you sure you want to make this transaction? [Y/N]: ", 'y', 'n'))
        {
            CurrentClient.balance -= withDrawAmount;
            SaveCleintsDataToFile(ClientsFile, vClients);
            ShowNewBalance(CurrentClient);
            return;
        }
    }
 
}
void PerformWithdraw(vector<CD> &vClients)
{
} 
  
void SaveCleintsDataToFile(string ClientsFile, vector<CD> &vClients)
{
    fstream myFile;
    myFile.open(ClientsFile, ios::out);

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
 
void ShowLogInScreen()
{
    system("cls");
    cout << "-----------------------------------------------------\n";
    cout << Tabs(2) << "Login Screen\n";
    cout << "-----------------------------------------------------\n";
}
void ShowBalance(CD cd)
{
    cout << "\nYour Balance is " << cd.balance;
}
void ShowNewBalance(CD cd)
{
    cout << "\nDone Successfully, Now Balance is " << cd.balance;
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

enQuickWithdraw GetQuickWithdrawOption()
{
    enQuickWithdraw option = (enQuickWithdraw)GetValidPositiveIntegerInRange("\nChoose what to withdraw from [1] to [8]? ", 1, 8);
    return option;
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
void Show_ATM_MainMenueOptionsScreen(en_ATM_MainMenue option)
{
    switch (option)
    {
    case en_ATM_MainMenue::NormalWithdraw:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Normal Withdraw\n";
        cout << "----------------------------------------";
        break;
    case en_ATM_MainMenue::Deposit:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Deposit\n";
        cout << "----------------------------------------";
        break;
    case en_ATM_MainMenue::ChckBalance:
        cout << "----------------------------------------\n";
        cout << Tabs(1) << "Check Balance Screen";
        cout << "----------------------------------------\n";
        break;
    }
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
 