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
short DaysInCurrentMonth(stDate, short);
short DaysInCurrentMonthInNotLeapYear(short month);
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay);
short GetValidPositiveIntegerInRange(string message, short min, short max);

void IncrementMonthAndYear(stDate &Date);
stDate IncreaseDateByOneDay(stDate Date);
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualToDate2(stDate Date1, stDate Date2);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool IsLeapYear(short);
bool IsLastDayInMonth(stDate Date);
bool IsNotOverlapPeriod(stPeriod Period1, stPeriod Period2);

short DaysInCurrentMonth(stDate);
short DaysInCurrentMonthInNotLeapYear(stDate);

string PeriodLengthInDays(stPeriod Period, bool includeEndDay);

stDate ReadDateInfo();
stPeriod ReadPeriod();

void SwapDates(stDate &Date1, stDate &Date2);

int main()
{
    stPeriod Period;

    cout << "\nEnter Period 1:";
    Period = ReadPeriod();

    cout << "\nPeriod Length: " << PeriodLengthInDays(Period, false);
    cout << "\nPeriod Length (including end day): " << PeriodLengthInDays(Period, true);
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
bool IsLastMonthInYear(short month)
{
    return month == 12;
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

bool isLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date, Date.month)) ? true : false;
}

short DaysInCurrentMonth(stDate Date, short month)
{
	return ((isLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
}
string PeriodLengthInDays(stPeriod Period, bool includeEndDay)
{
    return to_string(GetDifferenceInDays(Period.start, Period.end, includeEndDay));
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
