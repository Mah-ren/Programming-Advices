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
typedef struct stP
{
    stDate s;
    stDate e;
}P;

short CountOverlapDays(stP P1, stP P2, bool endDay = true);

short DaysInCurrentYear(short year);
short DaysInCurrentMonth(stDate Date);
short DaysInCurrentMonth(stDate, short);
short DaysInCurrentMonthInNotLeapYear(short month);
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay);
short GetValidPositiveIntegerInRange(string message, short min, short max);

void IncrementMonthAndYear(stDate &Date);
stDate IncreaseDateByOneDay(stDate Date);
bool IsDate1AfterDate2(stDate Date1, stDate Date2);
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualToDate2(stDate Date1, stDate Date2);
bool IsDateWithinP(stP P, stDate Date);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool IsLeapYear(short);
bool IsLastDayInMonth(stDate Date);
bool IsNotOverlapPeriod(stP P1, stP P2);

short DaysInCurrentMonth(stDate);
short DaysInCurrentMonthInNotLeapYear(stDate);

string PeriodLengthInDays(stP P, bool includeEndDay = false);

stDate ReadDateInfo();
stP ReadP();

void SwapDates(stDate &Date1, stDate &Date2);

int main()
{
    stP P1, P2;

    cout << "\nEnter P 1:";
    P1 = ReadP();
    
    cout << "\nEnter P 2:";
    P2= ReadP();

    cout << "\n\nOverlap Days Count Is: " << CountOverlapDays(P1, P2);
}

short CountOverlapDays(stP P1, stP P2, bool endDay)
{
    if (IsNotOverlapPeriod(P1, P2))
        return 0;

    if (IsDate1BeforeDate2(P1.s, P2.s))
    {
        if (IsDate1BeforeDate2(P1.e, P2.e))
            return GetDifferenceInDays(P2.s, P1.e, endDay);
        else if (IsDate1BeforeDate2(P2.e, P1.e))
            return GetDifferenceInDays(P2.s, P2.e, endDay); 
        else 
            return GetDifferenceInDays(P2.s, P2.e, endDay); 
    }
    else if (IsDate1BeforeDate2(P2.s, P1.s))
    {
        if (IsDate1BeforeDate2(P2.e, P1.e))
            return GetDifferenceInDays(P2.s, P2.e, endDay); 
        else if (IsDate1BeforeDate2(P1.e, P2.e))
            return GetDifferenceInDays(P2.s, P2.e, endDay); 
        else 
            return GetDifferenceInDays(P2.s, P2.e, endDay); 

    }
    else
    {
        if (IsDate1BeforeDate2(P1.e, P2.e))
            return GetDifferenceInDays(P1.e, P2.e, endDay); 
        else if (IsDate1BeforeDate2(P2.e, P1.e))
            return GetDifferenceInDays(P2.e, P1.e, endDay); 
        else 
            return GetDifferenceInDays(P1.s, P1.e, endDay); 
    }
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
            cout << "\nInvalid input. Please enter a positive shorteger.";
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
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (Date1.year > Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month > Date2.month ? true : (Date1.month == Date2.month ? Date1.day > Date2.day : false)) : false);
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
bool IsNotOverlapPeriod(stP P1, stP P2)
{
    //! if P1 is older than P2
    if (IsDate1BeforeDate2(P1.s, P2.s))
        return IsDate1BeforeDate2(P1.e, P2.s) ? true : false;

    //! if P1 is newer than P2
    else if (IsDate1BeforeDate2(P2.s, P1.s))
        return IsDate1BeforeDate2(P2.e, P1.s) ? true : false;

    //! if none of the above, then the P1 is equal to P2
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
bool IsDateWithinP(stP P, stDate Date)
{
    IsDate1BeforeDate2(P.s, Date) && IsDate1BeforeDate2(Date, P.e) ? true : (IsDate1EqualToDate2(P.s, Date) || IsDate1EqualToDate2(P.e, Date)) ? true : false; 
}

short DaysInCurrentMonth(stDate Date, short month)
{
	return ((isLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
}
string PeriodLengthInDays(stP P, bool includeEndDay)
{
    return to_string(GetDifferenceInDays(P.s, P.e, includeEndDay));
}
stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
stP ReadP()
{
    stP P;

    cout << "\nEnter Start Date:\n";
    P.s = ReadDateInfo();

    cout << "\nEnter End Date:\n";
    P.e = ReadDateInfo();

    return P;
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
