#include <iostream>
#include <iomanip>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void PrintCientRecordLine(clsBankClient Client)
{
    cout << "\n| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.GetAccountBalance() << "|";
    cout << "\n__________________________________________________________________________";
}


void ShowBalancesList()
{
    
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << "\n\t\t\tBalances List (" << vClients.size() << ")";
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
            PrintCientRecordLine(client);
        }

    float totalBalances = clsBankClient::GetTotalBalances();
    cout << "\n\t\t\t\t\t\t\t\tTotal Balances = " << totalBalances;
    cout << "\n\t\t\t\t\t\t\t\t(" << clsUtil::NumberToText(totalBalances) << ")";


}



int main()
{
    system("cls");
    ShowBalancesList();
    system("pause>0");
    return 0;
}