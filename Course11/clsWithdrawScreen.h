#pragma once 

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
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

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");
        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, enter another one: ";
            AccountNumber= clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nPlease Enter Withdraw Amount: ";
        int Amount = clsInputValidate::ReadIntNumber();
        
        if (clsInputValidate::isNumber1BiggerThanNumber2(Amount, Client.GetAccountBalance()))
        {
            cout << "\nAmont Exceeds the balance.";
            return;
        }

        else if (clsInputValidate::AreYouSure("\n\nAre you sure you want perfrom this transaction? y/n ? "))
        {
            Client.Withdraw(Amount);
            cout << "\n\nDone Successfully. New balance is: " << Client.GetAccountBalance();

        }
    }
};