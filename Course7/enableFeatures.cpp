#include <iostream>
#include <limits>
using namespace std;

// Define features using binary representation
#define a 0b00000001
#define b 0b00000010
#define c 0b00000100
#define d 0b00001000
#define e 0b00010000
#define f 0b00100000
#define g 0b01000000


typedef struct stUserName
{
    string user_name;
    string password;
    short permissions = 1;
    bool markForDeleting = false;
    bool markForUpdating = false;
    double balance = 0;
} stUN;
enum FeatureStatus
{
    DISABLED = 'n',
    ENABLED = 'y'
};
bool IsFeatureEnabled(const stUN& UN, short feature);
bool AreYouAgreed(string message, char agreed, char notAgreed);
short GivePermissions(string message, short featureNumber);
short GetValidPositiveshortegerInRange(string message, short min, short max);
stUN PerformPermission(stUN &);

int main()
{
    stUN UN;
    UN = PerformPermission(UN);
    cout << "\nNOW the permission is: " << UN.permissions ;
    
    
    short featureNumber = 1;
    while(true)
    {
        featureNumber = GetValidPositiveshortegerInRange("\nPlease enter featurenumber: ", 1, 7);
        if(IsFeatureEnabled(UN, 1 << (featureNumber - 1)))
            cout << "\nthis feature is enabled";
        else
            cout << "\nthis feature is disabled";
    }


}
stUN PerformPermission(stUN &UN)
{
    UN.permissions |= GivePermissions("\nDo you want to give full access? [y/n] ", 0);

    if (UN.permissions == -1)
        return UN;

    cout << "\nDo you want to give full access to:\n";
    UN.permissions |= GivePermissions("\nShow Client List? [y/n] ", 1);
    UN.permissions |= GivePermissions("\nAdd New Client? [y/n] ", 2);
    UN.permissions |= GivePermissions("\nDelete Client? [y/n] ", 3);
    UN.permissions |= GivePermissions("\nUpdate Client? [y/n] ", 4);
    UN.permissions |= GivePermissions("\nFind Client? [y/n] ", 5);
    UN.permissions |= GivePermissions("\nTransactions? [y/n] ", 6);
    UN.permissions |= GivePermissions("\nManage Users? [y/n] ", 7);

    return UN;
}

short GivePermissions(string message, short featureNumber)
{
    short permission = 0;
    permission &= ~(1 << (featureNumber - 'a'));
    bool areYouAgreed = AreYouAgreed(message, 'y', 'n');
    
    if((featureNumber == 0) && areYouAgreed)
    {
        permission = -1;
        return permission;
    }
    else if(areYouAgreed)
        permission |= (1 << (featureNumber - 'a'));

    return permission;
}

bool AreYouAgreed(string message, char agreed, char notAgreed)
{
    char choice = 'y';

    do
    {
        cout << message;
        cin >> choice;

        if (cin.fail()) // Check if extraction failed (non-shorteger input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid Char. Please enter [n, N, y, Y] only: " << endl;
            continue; // Prompt user again
        }

    } while (!(tolower(choice) == agreed || tolower(choice) == notAgreed));

    return (tolower(choice) == 'y') ? true : false;
}

short GetValidPositiveshortegerInRange(string message, short min, short max)
{
    short number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-shorteger input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive shorteger." << endl;
            continue; // Prompt user again
        }

    } while (number < min || number > max);

    return number;
}
//! enable 1&3&6
//! 1 | 11 | 110 -> 111 so 7
//! 64      32 16 8    4 2 1 
//!          1         1   1   
bool IsFeatureEnabled(const stUN& UN, short feature)
{
    // Check if the feature is enabled using bitwise AND
    return (UN.permissions & feature) != 0;
}