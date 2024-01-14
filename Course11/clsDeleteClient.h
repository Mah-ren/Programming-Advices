#pragma once 

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


 
class clsDeleteClient : protected clsScreen
{
private: 
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName();
        cout << "\nLastName    : " << Client.LastName();
        cout << "\nFull Name   : " << Client.FullName();  
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteClientScreen()
    {
        string AccountNumber = "";

        _DrawScreenHeader("\t  Delete Client Screen");

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Enter another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        if(clsInputValidate::AreYouSure("\nAre You Sure You Want to Delete This Client ? [y/n] "))
        {
            if (Client.Delete()){
                cout << "\nAccount Deleted Successfully :-)\n";
                _PrintClient(Client);
            }
            else
                cout << "\nError account was not deleted because it's not found";
        }

    }    

}; 
