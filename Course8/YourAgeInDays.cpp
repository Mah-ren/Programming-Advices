#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct stDate
{
	int year = 1;
	int month = 1;
	int day = 1;
};

string ConvertTotalDaysToDate(int, int);
int DaysFromBeggingOfYear(stDate);
int GetValidPositiveIntegerInRange(string message, int min, int max);
bool isLeapYear(int);
int NumberOfDaysInMonth(stDate);
int NumberOfDaysInMonthInNotLeapYear(stDate);

int main()
{	
    stDate Date;
    cout << "\nPlease Enter Your Date Of Birth:\n";

	Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
	Date.month =GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
	Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

	int daysFromBeggingOfYear  = DaysFromBeggingOfYear(Date);
	cout << "\nThis is the new function :-)\n";
	cout << "\nDate for [" << daysFromBeggingOfYear << "] is: " << ConvertTotalDaysToDate(Date.year, daysFromBeggingOfYear);


}

int DaysFromBeggingOfYear(stDate Date)
{
	int numberOfDaysInAMonth = 0;

	for (int i = 1; i < Date.month; i++)
	{
		numberOfDaysInAMonth += NumberOfDaysInMonth(Date);
	}
	return numberOfDaysInAMonth += Date.day;
}

bool isLeapYear(int year)
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int NumberOfDaysInMonthInNotLeapYear(stDate Date)
{
	int array[] = { 1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return array[Date.month];
}

int NumberOfDaysInMonth(stDate Date)
{
	return((isLeapYear(Date.year) && Date.month == 2) ? 29 : NumberOfDaysInMonthInNotLeapYear(Date));
}

string ConvertTotalDaysToDate(int year, int daysFromBeggingOfYear)
{
	stDate Date;
	Date.year = year;
	Date.month = 1;
	int remainingDays = daysFromBeggingOfYear;
	int numberOfDaysInMonth = 1;
	while (true)
	{
		numberOfDaysInMonth = NumberOfDaysInMonth(Date);
		if (remainingDays > numberOfDaysInMonth)
		{
			remainingDays -= numberOfDaysInMonth;
			++Date.month;
		}
		else
		{
			Date.day = remainingDays;
			break;
		}
	}

	return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
}

int GetValidPositiveIntegerInRange(string message, int min, int max)
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