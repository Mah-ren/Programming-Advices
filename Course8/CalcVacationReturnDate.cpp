#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;

enum enWeekDays
{
    Sunday = 1,
    Monday = 2,
    Tuesday = 4, 
    Wednesday = 8,
    Thursday = 16, 
    Friday = 32,
    Saturday = 64
};
struct stDate
{
    short year = 1;
    short month = 1;
    short day = 1;
};

bool AreYouAgreed(string message, char agreed, char notAgreed);

stDate CalcReturnDate(stDate Date, short vacationDays);

short DaysInCurrentMonthInNotLeapYear(short month);
short DaysInCurrentMonth(short year, short month);
short DayOfWeekOrder(short, short, short);
short DayOfWeekOrder(stDate Date);
string DayShortName(short DayOfWeekOrder);

short GetValidPositiveIntegerInRange(string message, short min, short max);

stDate IncreaseDateByOneDay(stDate Date);
void IncrementMonthAndYear(stDate &Date);
bool isItBusinessDay(short dayOfWeekOrder);
bool isItEndOfWeek(short );
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool isLeapYear(short year);
bool IsFridayOrSaturday(short day);

short NumberOfDaysInAYear(short year);

string PrintDateToday(stDate Date);

stDate ReadDateInfo();

int main()
{
    stDate Date1, Date2;

    cout << "\nVacation Starts:";
    Date1 = ReadDateInfo();

    Date2 = CalcReturnDate(Date1, GetValidPositiveIntegerInRange("\nPlease Enter Vacation Days: ", 1, 32));
    cout << "Return Date: " << PrintDateToday(Date2);
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

    } while (!(tolower(choice) == tolower(agreed) || tolower(choice) == tolower(notAgreed)));

    return (tolower(choice) == 'y' ? true : false);
}

stDate CalcReturnDate(stDate Date, short vacationDays)
{
    while (vacationDays != 0)
    {
        if(isItBusinessDay(DayOfWeekOrder(Date)))
            vacationDays--;
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;    
}

short DaysInCurrentMonthInNotLeapYear(short month)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[month];
}
short DaysInCurrentMonth(short year, short month)
{
    return ((isLeapYear(year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(month));
}
short DayOfWeekOrder(short day, short month, short year)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.day, Date.month, Date.year);
}
string DayShortName(short dayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[dayOfWeekOrder];
}
 
short GetValidPositiveIntegerInRange(string message, short min, short max)
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

    } while (number < min || number > max);

    return number;
}
stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        IncrementMonthAndYear(Date);
    }
    else
    {
        ++Date.day;
    }
    return Date;
}
void IncrementMonthAndYear(stDate &Date)
{
    if (IsLastMonthInYear(Date.month))
    {
        ++Date.year;
        Date.month = 1;
        Date.day = 1;
    }
    else
    {
        Date.day = 1;
        ++Date.month;
    }
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date.year, Date.month));
}
bool IsLastMonthInYear(short month)
{
	return (month == 12);
}
bool isItBusinessDay(short dayOfWeekOrder)
{
    return !(IsFridayOrSaturday(dayOfWeekOrder));
}
bool isLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
 
bool IsFridayOrSaturday(short day)
{
    return (day == 5 || day == 6);
}

short NumberOfDaysInAYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

string PrintDateToday(stDate Date)
{
    return ("Today is " + DayShortName(DayOfWeekOrder(Date)) + " , " 
         + to_string(Date.month) + "/" + to_string(Date.day) + "/" + to_string(Date.year));
}

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
