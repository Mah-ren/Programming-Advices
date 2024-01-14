#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactionScreen.h"
 
 
using namespace std;

class clsMainScreen:protected clsScreen
{
    private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eExit = 8
        };

        static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 8]? ";
            short Choice = clsInputValidate::ReadIntNumberBetween(1,8,"Enter Number between 1 to 8? ");
            return Choice;
        }

        static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...\n";
           
            system("pause>0");
            ShowMainMenue();
        }
        
        static void _ShowAllClientsScreen()
        {
            clsClientListScreen::ShowClientsList();
        }
        
        static void _ShowAddNewClientsScreen()
        {
            clsAddNewClient::ShowAddNewClientScreen();
        }

        static void _ShowDeleteClientScreen()
        {
            clsDeleteClient::ShowDeleteClientScreen();
        }

        static void _ShowUpdateClientScreen()
        {
            clsUpdateClient::ShowUpdateClientScreen();
        }

        static void _ShowFindClientScreen()
        {
            clsFindClient::ShowFindClientScreen();
        }

        static void _ShowTransactionsMenue()
       {
            clsTransactionScreen::ShowTransactionMenue();            
       }

        static void _ShowManageUsersMenue()
       {
           cout << "\nUsers Menue Will be here...\n";

       }

        static void _ShowEndScreen()
           {
               cout << "\nEnd Screen Will be here...\n";

           }

        static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
                system("cls");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();

            case enMainMenueOptions::eAddNewClient:
                system("cls");
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();


            case enMainMenueOptions::eDeleteClient:
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();

            case enMainMenueOptions::eUpdateClient:
                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();

            case enMainMenueOptions::eFindClient:
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();

            case enMainMenueOptions::eShowTransactionsMenue:
                system("cls");
                _ShowTransactionsMenue();

            case enMainMenueOptions::eManageUsers:
                system("cls");
                _ShowManageUsersMenue();

            case enMainMenueOptions::eExit:
                system("cls");
                _ShowEndScreen();
                //Login();

            }

        }

	public:  

        static void ShowMainMenue()
        {
            system("cls");
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }

};

