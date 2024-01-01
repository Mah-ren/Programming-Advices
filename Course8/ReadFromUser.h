#pragma once
#include <iostream>
#include <limits>

using namespace std;



namespace ReadFromUser
{
    short GetValidPositiveShortegerInRange(string message, short min, short max)
    {
        short number = 1;

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

        } while (number < min && number > max);

        return number;
    }
}