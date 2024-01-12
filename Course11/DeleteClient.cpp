#include <iostream>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)){
        cout << "\nAccount Number Is Not Found, Enter another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    if(clsInputValidate::AreYouSure("\nAre You Sure You Want to Delete This Client ? [y/n] "))
    {
        if (Client.Delete()){
            cout << "\nAccount Deleted Successfully :-)\n";
            Client.Print();
        }
        else
            cout << "\nError account was not deleted because it's not found";
    }

}

int main()

{
    DeleteClient();
    system("pause>0");
    return 0;
}