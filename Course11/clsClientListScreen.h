#pragma once 

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private: 

    static void _PrintCientRecordLine(clsBankClient Client)
    {
        cout << "\n| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone();
        cout << "| " << setw(20) << left << Client.Email();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance() << "|";
        cout << "\n______________________________________________________________________________________________________";
    }

public:
    
    static void ShowClientsList()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        
        string Title = "\t  Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")";
        cout << "\n______________________________________________________________________________________________________";
        cout << "\n| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name ";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Balance ";
        cout << "| " << left << setw(12) << "Salary    ";
        cout << "|";
        cout << "\n______________________________________________________________________________________________________";

        if (vClients.size() == 0)
        {
            system("color 0c");
            cout << "\n\aNo Clients Available in the system.";
            cout << "\n________________________________________________________________________________________________";
            return;
        }

        else 
            for (clsBankClient &client : vClients)
            {
                    _PrintCientRecordLine(client);
            }
    }


};