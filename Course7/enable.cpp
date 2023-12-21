
#include <iostream>
#include <bitset>
#include <limits>
using namespace std;

// Define features using bit manipulation
#define FEATURE_A 0b00000001
#define FEATURE_B 0b00000010
#define FEATURE_C 0b00000100
#define FEATURE_D 0b00001000
#define FEATURE_E 0b00010000
#define FEATURE_F 0b00100000
#define FEATURE_G 0b01000000

typedef struct stUserName
{
    string username;
    string password;
    short permissions = 0;
    bool markForDeleting = false;
    bool markForUpdating = false;
    double balance = 0;
}stUN;
enum FeatureStatus
{
    DISABLED = 'n',
    ENABLED = 'y'
};

bool AreYouAgreed(string message, char agreed, char notAgreed);
short GivePermissions(string message, stUN &UN, short featureNumber);
int GetValidPositiveIntegerInRange(string message, short min, short max);
stUN PerformPermission(stUN &UN);
void PrintPermission(stUN &UN);

int main()
{
    vector<stUserName> vClients;
    stUN UN;


    for(short i = i; i < 3; ++i)
    {
        cout << "\nPlease Enter Username: ";
        cin << 
    }



    UN.username = "pro219";
    UN.password = "1111";

    UN = PerformPermission(UN);
    PrintPermission(UN);

    return 0;
}

stUN PerformPermission(stUN &UN)
{
    if(AreYouAgreed("\nDo you want to give full access? [y/n] ", 'y', 'n'))
    {
        UN.permissions = -1;
        return UN;
    }

    cout << "\nDo you want to give access to:\n";
    UN.permissions = GivePermissions("\nShow Client List? [y/n] ", UN, 1);
    UN.permissions = GivePermissions("\nAdd New Client? [y/n] ", UN, 2);
    UN.permissions = GivePermissions("\nDelete Client? [y/n] ", UN, 3);
    UN.permissions = GivePermissions("\nUpdate Client? [y/n] ", UN, 4);
    UN.permissions = GivePermissions("\nFind Client? [y/n] ", UN, 5);
    UN.permissions = GivePermissions("\nTransactions? [y/n] ", UN, 6);
    UN.permissions = GivePermissions("\nManage UNs? [y/n] ", UN, 7);

    return UN;
}

short GivePermissions(string message, stUN &UN, short featureNumber)
{
    cout << message;
    cin >> 
    return  (UN.permissions |= 1 << featureNumber);
}

void PrintPermission(stUN &UN)
{
    cout << "\nNOW the permission is: " << UN.permissions << endl;
}

bool AreYouAgreed(string message, char agreed, char notAgreed)
{
    char choice = 'y';

    do
    {
        cout << message;
        cin >> choice;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid Char. Please enter [n, N, y, Y] only: " << endl;
            continue; // Prompt UN again
        }

    } while (!(tolower(choice) == agreed || tolower(choice) == notAgreed));

    return (tolower(choice) == 'y') ? true : false;
}