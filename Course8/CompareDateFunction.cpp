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

short DaysFromBeggingOfYear(stDate);
short DaysInCurrentYear(short year);
short DaysInCurrentMonth(stDate Date);
short DaysInCurrentMonth(short, short);
short DaysInCurrentMonthInNotLeapYear(short month);

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false);
short GetValidPositiveIntegerInRange(string message, short min, short max);

stDate IncreaseDateByOneDay(stDate Date);
void IncrementMonthAndYear(stDate &Date);
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualToDate2(stDate Date1, stDate Date2);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool isLeapYear(short);

short NumberOfDaysInMonth(stDate);
short NumberOfDaysInMonthInNotLeapYear(stDate);

stDate ReadDateInfo();

void SwapDates(stDate &Date1, stDate &Date2);

int main()
{
    stDate Date1, Date2;

    cout << "\nPlease Enter Date1:\n";
    Date1 = ReadDateInfo();

    cout << "\n\nPlease Enter Date2:\n";
    Date2 = ReadDateInfo();

    // Date2 = GetSystemDate();

    cout << "\nCompare Result is: " << GetDifferenceInDays(Date1, Date2, false);
}

short DaysFromBeggingOfYear(stDate Date)
{
    short numberOfDaysInAMonth = 0;

    for (short i = 1; i < Date.month; i++)
    {
        numberOfDaysInAMonth += NumberOfDaysInMonth(Date);
    }
    return numberOfDaysInAMonth += Date.day;
}
short DaysInCurrentMonth(short year, short month)
{
    return ((isLeapYear(year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(month));
}
short DaysInCurrentMonth(stDate Date)
{
    return DaysInCurrentMonth(Date.year, Date.month);
}
short DaysInCurrentYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}
short DaysInCurrentMonthInNotLeapYear(short month)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[month];
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
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay)
{
    if (IsDate1EqualToDate2(Date1, Date2))
        return 0;
    else if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        return -1 * GetDifferenceInDays(Date1, Date2, IncludeEndDay);
    }

    // if (IsDate1BeforeDate2(Date1, Date2))
    else
    {
        short Days = 0;

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days : Days;
    }
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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}
bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day);
}
bool IsLastDayInMonth(stDate Date)
{
    return (Date.day == DaysInCurrentMonth(Date.year, Date.month));
}
bool IsLastMonthInYear(short month)
{
    return (month == 12);
}
bool isLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(stDate Date)
{
    return ((isLeapYear(Date.year) && Date.month == 2) ? 29 : NumberOfDaysInMonthInNotLeapYear(Date));
}
short NumberOfDaysInMonthInNotLeapYear(stDate Date)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}
void SwapDates(stDate &Date1, stDate &Date2)
{
    stDate Temp;

    Temp.year = Date1.year;
    Temp.month = Date1.month;
    Temp.day = Date1.day;

    Date1.year = Date2.year;
    Date1.month = Date2.month;
    Date1.day = Date2.day;

    Date2.year = Temp.year;
    Date2.month = Temp.month;
    Date2.day = Temp.day;
}

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}