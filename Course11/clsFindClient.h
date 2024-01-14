#pragma once 

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


 
class clsFindClient : protected clsScreen
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

    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\t  Find Client Screen");
        cout << "\nPlease Enter Acount Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        while (! clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number " << AccountNumber << " is not found :-(";
            return;
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        
        if (!Client.IsEmpty())
            cout << "\nClient is found :-)";
        else 
            cout << "\nClient was not found :-(";        
        
        _PrintClient(Client);
    }


}; 
