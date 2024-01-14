#pragma once 

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


 
class clsAddNewClient : protected clsScreen
{
private: 
    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.LastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.Email(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.Phone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }
    
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
    static void ShowAddNewClientScreen()
    {
        string AccountNumber = "";

        _DrawScreenHeader("\t  Add New Client Screen");

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;


        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        };

    }    

};