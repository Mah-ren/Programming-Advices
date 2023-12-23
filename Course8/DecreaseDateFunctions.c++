#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct stDate
{
    short year = 1;
    short month = 1;
    short day = 1;
};

int DaysFromBeggingOfYear(stDate);
short DaysInCurrentMonth(stDate Date, short month);
int DaysInCurrentMonthInNotLeapYear(stDate);

int GetValidPositiveIntegerInRange(string message, int min, int max);

stDate DecreaseDateByOneDay(stDate Date);
stDate DecreaseDateByXDays(stDate Date, int);
stDate DecreaseDateByOneWeek(stDate Date);
stDate DecreaseDateByXWeeks(stDate Date, int);
stDate DecreaseDateByOneMonth(stDate Date);
stDate DecreaseDateByXMonths(stDate Date, int);
stDate DecreaseDateByOneYear(stDate Date);
stDate DecreaseDateByXYears(stDate Date, int);
stDate DecreaseDateByOneDecade(stDate Date);
stDate DecreaseDateByXDecades(stDate Date, int);
stDate DecreaseDateByOneCentury(stDate Date);
stDate DecreaseDateByXCenturies(stDate Date, int);

bool IsFirstMonthInYear(short month);
bool IsFirstDayInMonth(stDate Date);
bool isLeapYear(int);

int NumberOfDaysInAYear(int year);

stDate ReadDateInfo();

int main()
{
    stDate Date;

    cout << "\nPlease Enter Your Date Of Birth:\n";
    Date = ReadDateInfo();

    int daysFromBeggingOfYear = DaysFromBeggingOfYear(Date);

    cout << "\nDate After: ";

    Date = DecreaseDateByOneDay(Date);
    cout << "\n1] Subtracting one day is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXDays(Date, 5);
    cout << "\n2] Subtracting 5 days is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n2] Subtracting 10 days is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXDays(Date, 20);
    cout << "\n2] Subtracting 20 days is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n\n\n3] Subtracting one week is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n4] Subtracting ten weeks is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n\n\n5] Subtracting one month is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXMonths(Date, 10);
    cout << "\n6] Subtracting ten months is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByOneYear(Date);
    cout << "\n\n\n7] Subtracting one year is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n8] Subtracting ten years is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n\n\n9] Subtracting one decade is: " << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "\n10] Subtracting ten decades is:" << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n\n\n11] Subtracting one century is:" << Date.month << "/" << Date.day << "/" << Date.year;

    Date = DecreaseDateByXCenturies(Date, 10);
    cout << "\n12] Subtracting ten centuries is: " << Date.month << "/" << Date.day << "/" << Date.year;
}

int DaysFromBeggingOfYear(stDate Date)
{
    int numberOfDaysInAMonth = 0;

    for (int i = 1; i < Date.month; i++)
    {
        numberOfDaysInAMonth += DaysInCurrentMonth(Date, i);
    }

    return numberOfDaysInAMonth += Date.day;
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int DaysInCurrentMonthInNotLeapYear(stDate Date)
{
    int array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}

short DaysInCurrentMonth(stDate Date, short month)
{
    return ((isLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.day == 1)
    {
        if (Date.month == 1)
        {
            --Date.year;
            Date.month = 12;
            Date.day = 31;
        }
        else
        {
            --Date.month;
            Date.day = DaysInCurrentMonth(Date, Date.month);
        }
    }
    else
        --Date.day;
    return Date;
}

stDate DecreaseDateByXDays(stDate Date, int daysToSubtract)
{
    for (int i = 0; i < daysToSubtract; ++i)
        Date = DecreaseDateByOneDay(Date);

    return Date;
}
bool IsFirstDayInMonth(stDate Date)
{
    return Date.day == DaysInCurrentMonth(Date, Date.month) ? true : false;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 0; i < 7; ++i)
        Date = DecreaseDateByOneDay(Date);
    return Date;
}
stDate DecreaseDateByXWeeks(stDate Date, int weeksToSubtract)
{
    for (int i = 0; i < weeksToSubtract; ++i)
        Date = DecreaseDateByOneWeek(Date);
    return Date;
}
stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.month == 1)
    {
        Date.month = 12;
        --Date.year;
    }
    else
        --Date.month;
    short daysInCurrentMonth = DaysInCurrentMonth(Date, Date.month);
    if (Date.day > daysInCurrentMonth)
        Date.day = daysInCurrentMonth;
    return Date;
}
stDate DecreaseDateByXMonths(stDate Date, int monthsToSubtract)
{
    for (int i = 0; i < monthsToSubtract; ++i)
        Date = DecreaseDateByOneMonth(Date);
    return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
    --Date.year;
    return Date;
}
stDate DecreaseDateByXYears(stDate Date, int yearsToSubtract)
{
    Date.year -= yearsToSubtract;
    return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.year -= 10;
    return Date;
}
stDate DecreaseDateByXDecades(stDate Date, int decadesToAdd)
{
    Date.year -= (10 * decadesToAdd);
    return Date;
}
stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.year -= 100;
    return Date;
}
stDate DecreaseDateByXCenturies(stDate Date, int centuriesToAdd)
{
    Date.year -= (100 * centuriesToAdd);
    return Date;
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

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}

bool IsFirstMonthInYear(short month)
{
    return (month == 12) ? true : false;
}
bool isFirstDayInMonth(stDate Date)
{
    return (Date.day == DaysInCurrentMonth(Date, Date.month)) ? true : false;
}
