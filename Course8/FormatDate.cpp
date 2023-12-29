#include <iostream>
#include <limits>
#include <string>
#include <ctime>
using namespace std;

enum enFormatDate
{
    enDayMonthYear_BackSlash,
    enYearDayMonth_BackSlash, 
    enMonthDayYear_BackSlash, 
    enMonthDayYear_Dash,
    enDayMonthYear_Dash,
    enDateLinearly
};
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

string FormatingDate(stDate Date, enFormatDate formatDate);

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
    
    cout << "\n";
    cout << "\n" << FormatingDate(Date, enFormatDate::enDayMonthYear_BackSlash) << endl;
    cout << "\n" << FormatingDate(Date, enFormatDate::enYearDayMonth_BackSlash) << endl;
    cout << "\n" << FormatingDate(Date, enFormatDate::enMonthDayYear_BackSlash) << endl;
    cout << "\n" << FormatingDate(Date, enFormatDate::enMonthDayYear_Dash) << endl;
    cout << "\n" << FormatingDate(Date, enFormatDate::enDayMonthYear_Dash) << endl;
    cout << "\n" << FormatingDate(Date, enFormatDate::enDateLinearly) << endl;
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

string FormatingDate(stDate Date, enFormatDate formatDate)
{
    switch(formatDate)
    {
    case enFormatDate::enDayMonthYear_BackSlash:
        return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
    case enFormatDate::enYearDayMonth_BackSlash:
        return to_string(Date.year) + "/" + to_string(Date.day) + "/" + to_string(Date.month);
    case enFormatDate::enMonthDayYear_BackSlash:
        return to_string(Date.month) + "/" + to_string(Date.day) + "/" + to_string(Date.year);
    case enFormatDate::enMonthDayYear_Dash:
        return to_string(Date.month) + "-" + to_string(Date.day) + "-" + to_string(Date.year);
    case enFormatDate::enDayMonthYear_Dash:
        return to_string(Date.day) + "-" + to_string(Date.month) + "-" + to_string(Date.year);  
    case enFormatDate::enDateLinearly:
        return "Day:" + to_string(Date.day) + ", Month:" + to_string(Date.month) + ", Year:" +to_string(Date.year);
    }
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
