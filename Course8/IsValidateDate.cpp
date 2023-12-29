#include <iostream>
#include <limits>
#include <string>
#include <ctime>
using namespace std;

struct stDate
{
    short year = 1;
    short month = 1;
    short day = 1;
};

short DaysInCurrentYear(short year);
short DaysInCurrentMonth(stDate Date);
short DaysInCurrentMonth(stDate, short);
short DaysInCurrentMonthInNotLeapYear(short month);
short GetValidPositiveIntegerInRange(string message, short min, short max);

bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool IsLeapYear(short year);
bool IsLastDayInMonth(stDate Date);
bool IsValidDate(stDate Date);

short DaysInCurrentMonth(stDate);
short DaysInCurrentMonthInNotLeapYear(stDate);

stDate ReadDateInfo();

int main()
{
    stDate Date;

    cout << "\nEnter Date to check: ";
    Date = ReadDateInfo();

    IsValidDate(Date) ? cout << "\nYes, it's a valid date." : cout << "\nNo, it's nott a valid date.";            
}

short DaysInCurrentMonth(short year, short month)
{
    return ((IsLeapYear(year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(month));
}
short DaysInCurrentMonth(stDate Date)
{
    return DaysInCurrentMonth(Date.year, Date.month);
}
short DaysInCurrentYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}
short DaysInCurrentMonthInNotLeapYear(short month)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[month];
}
short DaysInCurrentMonthInNotLeapYear(stDate Date)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}
short DaysInCurrentMonth(stDate Date, short month)
{
	return ((IsLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
}

short GetValidPositiveIntegerInRange(string message, short min, short max)
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

bool IsLastMonthInYear(short month)
{
    return month == 12;
}
bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date, Date.month)) ? true : false;
}
bool IsValidDate(stDate Date)
{
    return (Date.month <= 12 && Date.day <= DaysInCurrentMonth(Date));
}
    

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
