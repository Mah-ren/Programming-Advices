#pragma once

#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"


 
using namespace std;

class clsTransactionScreen : protected clsScreen
{
    private:
  
        enum enTransactionMenueOptions {eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainScreen = 4};

        static short _ReadTransactionMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 4]? ";
            short Choice = clsInputValidate::ReadIntNumberBetween(1,4,"Enter Number between 1 to 4? ");
            return Choice;
        }

        static  void _GoBackToTransactionMenue()
        {
            cout << setw(37) << left << ""<<"\n\tPress any key to go back to Transaction Menue...\n";
           
            system("pause>0");
            ShowTransactionMenue();
        }
        
        static void _ShowDepositScreen()
        {
            clsDepositScreen::ShowDepositScreen();
        }

        static void _ShowWithdrawScreen()
        {
            clsWithdrawScreen::ShowWithdrawScreen();
        }

        static void _ShowTotalBalancesScreen()
       {
        clsTotalBalancesScreen::ShowBalancesList();
       }

        static void _GoBackToMainMenue()
       {
           cout << "\nUsers Menue Will be here...\n";

       }


        static void _PerfromTransactionMenueOption(enTransactionMenueOptions TransactionMenueOption)
        {
            switch (TransactionMenueOption)
            {
            case enTransactionMenueOptions::eDeposit:
                system("cls");
                _ShowDepositScreen();
                _GoBackToTransactionMenue();

            case enTransactionMenueOptions::eWithdraw:
                system("cls");
               _ShowWithdrawScreen();
                _GoBackToTransactionMenue();


            case enTransactionMenueOptions::eTotalBalances:
                system("cls");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionMenue();

            case enTransactionMenueOptions::eMainScreen:
                system("cls");
                // _ShowUpdateClientScreen();
                _GoBackToTransactionMenue();

            };

        }

	public:  

        static void ShowTransactionMenue()
        {
            system("cls");
            _DrawScreenHeader("\t\tTransaction Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMenueOption());
        }

};

