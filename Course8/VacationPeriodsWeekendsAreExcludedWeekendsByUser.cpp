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

short CalcVacationPeriods(stDate Date, stDate Date2);
short ConvertToPosition(short decimalNumber);

short DaysInCurrentMonthInNotLeapYear(short month);
short DaysInCurrentMonth(short year, short month);
short DayOfWeekOrder(short, short, short);
short DayOfWeekOrder(stDate Date);
string DayShortName(short DayOfWeekOrder);
short DaysUntilEndOfWeek(short dayOfWeekOrder);
short DaysUntilEndOfYear(short numberOfDaysInAYear, short daysFromBeginngOfYear);
short DaysUntilEndOfMonth(stDate);

short GetDifferenceInDays(stDate Date, stDate Date2);
short GetWeekendDaysFromUser();
short GetValidPositiveIntegerInRange(string message, short min, short max);

stDate IncreaseDateByOneDay(stDate Date);
void IncrementMonthAndYear(stDate &Date);
bool isDate1BeforeDate2(stDate Date1, stDate Date2);
bool isItBusinessDay(short dayOfWeekOrder);
bool isItEndOfWeek(short );
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool isLeapYear(short year);
bool IsDayWeekend(short, short);
bool IsFridayOrSaturday(short day);

short NumberOfDaysInAYear(short year);

stDate PrintDateToday(stDate Date, short dayOfWeekOrder);

stDate ReadDateInfo();

int main()
{
    stDate Date1, Date2;

    cout << "\nVacation Starts:";
    Date1 = ReadDateInfo();

    cout << "\n\nVacation Ends:";
    Date2 = ReadDateInfo();

    cout << "\n\nVacation From: " << DayShortName(DayOfWeekOrder(Date1)) << " , " << to_string(Date1.month) << "/" << to_string(Date1.day) << "/" << to_string(Date1.year);
    cout << "\nVacation To: " << DayShortName(DayOfWeekOrder(Date2)) << " , " << to_string(Date2.month) << "/" << to_string(Date2.day) << "/" << to_string(Date2.year) ;

    
    cout << "\n\nActual Vacation Days is: " << CalcVacationPeriods(Date1, Date2);

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

short CalcVacationPeriods(stDate Date1, stDate Date2) 
{
    short differenceInDaysExceptWeekends = 0;

    while(isDate1BeforeDate2(Date1, Date2))
    {
        // if(!IsDayWeekend(weekDays, ConvertToPosition(DayOfWeekOrder(Date1)+1)))
        //     differenceInDaysExceptWeekends++;
        if(!IsFridayOrSaturday(DayOfWeekOrder(Date1)))
            differenceInDaysExceptWeekends++;

        Date1 = IncreaseDateByOneDay(Date1);    
    }
    
    return differenceInDaysExceptWeekends;
}       
short ConvertToPosition(short decimalNumber)
{
    return 1 << (decimalNumber - 1);
}

short DaysFromBeginngOfYear(stDate Date)
{
    short daysInCurrentMonth = 0;

	for (short i = 1; i < Date.month; i++)
	{
		daysInCurrentMonth += DaysInCurrentMonth(Date.year, i);
	}
	return daysInCurrentMonth += Date.day;
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
short DaysUntilEndOfWeek(short dayOfWeekOrder)
{
    return 6 - dayOfWeekOrder;
}
short DaysUntilEndOfMonth(stDate Date)
{
    return (DaysInCurrentMonth(Date.year, Date.month) - Date.day );
}
short DaysUntilEndOfYear(short numberOfDaysInAYear, short daysFromBeginngOfYear)
{
    return (numberOfDaysInAYear - daysFromBeginngOfYear);
}

short GetWeekendDaysFromUser()
{
    cout << "\nPlease enter the Weekend days (y/n) for each day:\n";      
    vector<string> weekDays = { "Sunday: ", "Monday: ", "Tuesday: ", "Wednesday: ", "Thursday: ", "Friday: ", "Saturday: "};
    
    short vacationDays = 0, number = 1;

    for(string &day : weekDays)
    {
        vacationDays += AreYouAgreed(day, 'y', 'n') ? number : 0;
        number *= 2;
    }

    return vacationDays;
}
short GetDifferenceInDays(stDate Date, stDate Date2)
{
    short differenceInDays = 0;
    if(Date.year != Date2.year)
    {
        for (short yearOfDate = (Date.year + 1); yearOfDate < Date2.year; ++yearOfDate)
            differenceInDays += NumberOfDaysInAYear(yearOfDate);
        
        differenceInDays += ((NumberOfDaysInAYear(Date.year) - DaysFromBeginngOfYear(Date)) + DaysFromBeginngOfYear(Date2));
    }
    else    
        differenceInDays += (DaysFromBeginngOfYear(Date2) - DaysFromBeginngOfYear(Date));
	return differenceInDays;
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
bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    if((Date1.year < Date2.year) || (Date1.month < Date2.month) || (Date1.day < Date2.day))
        return true;
    return false;
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date.year, Date.month));
}
bool IsLastMonthInYear(short month)
{
	return (month == 12);
}
bool isItEndOfWeek(short dayOfWeekOrder)
{
    return (dayOfWeekOrder == 6);
}
bool isItBusinessDay(short dayOfWeekOrder)
{
    return !(dayOfWeekOrder == 6 || dayOfWeekOrder == 5);
}
bool isLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day == Date2.day) ? true : false;
}
bool IsDayWeekend(short WeekendDays, short day)
{
    return ((WeekendDays & day) != 0);
}
bool IsFridayOrSaturday(short day)
{
    return (day == 5 || day == 6);
}

short NumberOfDaysInAYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

stDate PrintDateToday(stDate Date, short dayOfWeekOrder)
{
    cout << "Today is " << DayShortName(dayOfWeekOrder) << " , " 
         << to_string(Date.month) << "/" << to_string(Date.day) << "/" << to_string(Date.year);
}

stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
