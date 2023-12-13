#include <iostream>
using namespace std;

// Define features using binary representation
#define FIRST_FEATURE 0b00000001
#define SECOND_FEATURE 0b00000010
#define THIRD_FEATURE 0b00000100
#define FOURTH_FEATURE 0b00001000
#define FIFTH_FEATURE 0b00010000
#define SIXTH_FEATURE 0b00100000
#define SEVENTH_FEATURE 0b01000000

// Enum for enable/disable
enum FeatureStatus
{
    DISABLED = 0,
    ENABLED = 1
};

int main()
{
    int permission = 0; // Initialize permission as 0
    int choice;

    cout << "Enter your permission on the first feature (1 for enable, 0 for disable): ";
    cin >> choice;

    // Update permission based on user input for the first feature
    if (choice == ENABLED)
    {
        permission |= FIRST_FEATURE;
        cout << "\nFirst feature is enabled.";
    }
    else
    {
        permission &= ~FIRST_FEATURE; // Disable the first feature
        cout << "\nFirst feature is disabled.";
    }

    // You can repeat the above process for other features...

    // Now, 'permission' holds the combined features in a single integer.
    return 0;
}