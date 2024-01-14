#pragma once 
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private: 

    static void _PrintCientRecordLine(clsBankClient Client)
    {
        cout << "\n| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance() << "|";
        cout << "\n__________________________________________________________________________";
    }

public:

    static void ShowBalancesList()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string subTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
        _DrawScreenHeader("\t  Total Balances Screen", subTitle);
        
        cout << "\n__________________________________________________________________________";
        cout << "\n| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name ";
        cout << "| " << left << setw(12) << "Balance";
        cout << "|";
        cout << "\n__________________________________________________________________________";

        if (vClients.size() == 0)
        {
            system("color 0c");
            cout << "\n\aNo Clients Available in the system.";
            cout << "\n__________________________________________________________________________";
            return;
        }

        else 
            for (clsBankClient &client : vClients)
            {
                _PrintCientRecordLine(client);
            }

        float totalBalances = clsBankClient::GetTotalBalances();
        cout << "\n\t\t\t\t\t\t\t\tTotal Balances = " << totalBalances;
        cout << "\n\t\t\t\t\t\t\t\t(" << clsUtil::NumberToText(totalBalances) << ")";


    }



};