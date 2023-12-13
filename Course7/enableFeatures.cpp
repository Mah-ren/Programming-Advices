//! Certainly! To store and combine the features in a single integer, you can use bitwise operations.
//! Here's an improved version of your code with better logic, variable names, and comments:

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

enum FeatureStatus
{
    DISABLED = 'n',
    ENABLED = 'y'
};

bool AreYouAgreed(string message, char agreed, char notAgreed);
short GivePermissions(string message, short featureNumber);
int GetValidPositiveIntegerInRange(string message, short min, short max);
short PerformPermission();
int main()
{
    short permission = PerformPermission();
    cout << "\nNOW the permission is: " << permission;


}

short PerformPermission()
{
    short permission = GivePermissions("Do you want to give full access? [y/n] ", 0);
    
    if(permission == -1)
        return permission;
        

    short length = GetValidPositiveIntegerInRange("\nPlease enter the number of the features: ", 1, 10);

    for(short i = 1; i <= length; ++i)
    {
        permission = GivePermissions("Do you want to give access to Feature[" + to_string(i) + "] ? [y/n] ",i);
    }
    
    return permission;
}


//! عايز اعمل فنكشن بتاخد من المستخدم رسالة و رقم الفيتشر يعني مثلا الخامسة 
//! لو المستخدم عمل ادخل 
short GivePermissions(string message, short featureNumber)
{
    int permission = 0;
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

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid Char. Please enter [n, N, y, Y] only: " << endl;
            continue; // Prompt user again
        }

    } while (!(tolower(choice) == agreed || tolower(choice) == notAgreed));

    return (tolower(choice) == 'y') ? true : false;
}

int GetValidPositiveIntegerInRange(string message, short min, short max)
{
    int number = 1;

    do
    {
        cout << message;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive integer." << endl;
            continue; // Prompt user again
        }

    } while (number < min || number > max);

    return number;
}