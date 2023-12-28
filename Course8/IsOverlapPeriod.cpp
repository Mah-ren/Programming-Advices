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
struct stPeriod
{
    stDate start;
    stDate end;
};

short DaysInCurrentYear(short year);
short DaysInCurrentMonth(stDate Date);
short DaysInCurrentMonth(short, short);
short DaysInCurrentMonthInNotLeapYear(short month);

short GetValidPositiveIntegerInRange(string message, short min, short max);

bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualToDate2(stDate Date1, stDate Date2);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool IsLeapYear(short);
bool IsNotOverlapPeriod(stPeriod Period1, stPeriod Period2);

short DaysInCurrentMonth(stDate);
short DaysInCurrentMonthInNotLeapYear(stDate);

stDate ReadDateInfo();
stPeriod ReadPeriod();


int main()
{
    stPeriod Period1, Period2;

    cout << "\nEnter Period 1:";
    Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    Period2 = ReadPeriod();

    !IsNotOverlapPeriod(Period1, Period2) ? cout << "\nYes, Periods Overlap." : cout << "\nNo, Periods don't Overlap.";
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

 
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day);
}
 
bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool IsNotOverlapPeriod(stPeriod Period1, stPeriod Period2)
{
    //! if Period1 is older than Period2
    if (IsDate1BeforeDate2(Period1.start, Period2.start))
        return IsDate1BeforeDate2(Period1.end, Period2.start) ? true : false;

    //! if Period1 is newer than Period2
    else if (IsDate1BeforeDate2(Period2.start, Period1.start))
        return IsDate1BeforeDate2(Period2.end, Period1.start) ? true : false;

    //! if none of the above, then the Period1 is equal to Period2
    return true;
}
short DaysInCurrentMonthInNotLeapYear(stDate Date)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.start = ReadDateInfo();

    cout << "\nEnter End Date:\n";
    Period.end = ReadDateInfo();

    return Period;
}
 