#include <iostream>
#include <limits>
using namespace std;

struct stDate
{
    short year = 1;
    short month = 1;
    short day = 1;
};

short DaysInCurrentMonthInNotLeapYear(stDate Date);
short DaysFromBeginngOfYear(stDate Date);
short DaysInCurrentMonth(stDate Date, short month);
short DayOfWeekOrder(stDate Date);
string DayShortName(short DayOfWeekOrder);
short DaysUntilEndOfWeek(short dayOfWeekOrder);
short DaysUntilEndOfYear(short numberOfDaysInAYear, short daysFromBeginngOfYear);
short DaysUntilEndOfMonth(stDate);
short GetValidPositiveIntegerInRange(string message, short min, short max);

bool isLeapYear(short year);
bool isItBusinessDay(short dayOfWeekOrder);
bool isItEndOfWeek(short );
bool isItWeekend(short);

short NumberOfDaysInAYear(short year);

stDate PrintDateToday(stDate Date, short dayOfWeekOrder);

stDate ReadDateInfo();


int main()
{
    stDate Date;
    Date = ReadDateInfo();
    short dayOfWeekOrder = DayOfWeekOrder(Date);
    PrintDateToday(Date, dayOfWeekOrder);

    cout << "\nIs is End Of Week ? ";
    cout << (isItEndOfWeek(dayOfWeekOrder)) ?  "\nYes, it is end of week." : "\nNo, it's not end of week.";

    cout << "\nIs it a weekend? ";
    if (isItWeekend(dayOfWeekOrder))
        cout << "\nYes, it's a weekend.";
    else 
        cout << "\nNo, it's Not a weekend.";

    cout << "\nis it a business day? \"by function isItWeekend\"";
    if (!isItWeekend(dayOfWeekOrder))
        cout << "\nYes, it's a business day.";
    else 
        cout << "\nNo, it's Not a business day.";
    
    cout << "\nis it a business day? \"by function isItbusinessDay\"";
    if(isItBusinessDay(dayOfWeekOrder))
        cout << "\nYes, it's a business day.";
    else 
        cout << "\nNo, it's Not a business day.";

    cout << "\nDays until end of week : " << DaysUntilEndOfWeek(dayOfWeekOrder) << " Days(s).";
    cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date) << " Days(s).";

    cout << "\nDate.year: " << Date.year;
    cout << "\nDate.month: " << Date.month;
    cout << "\nDate.day: " << Date.day;

    short daysFromBeginngOfYear = DaysFromBeginngOfYear(Date);
    cout << "\nDays From beginning of year : " << daysFromBeginngOfYear;

    short numberOfDaysInAYear = NumberOfDaysInAYear(Date.year);
    cout << "\nDays of year: " << numberOfDaysInAYear;


    cout << "\nDays until end of year : " << DaysUntilEndOfYear(numberOfDaysInAYear, daysFromBeginngOfYear) << " Days(s).";


    
}
 
short DaysFromBeginngOfYear(stDate Date)
{
    short numberOfDaysInAMonth = 0;

	for (short i = 1; i < Date.month; i++)
	{
		numberOfDaysInAMonth += DaysInCurrentMonth(Date, i);
	}
	return numberOfDaysInAMonth += Date.day;
}

short DaysInCurrentMonthInNotLeapYear(stDate Date)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}
short DaysInCurrentMonth(stDate Date, short month)
{
    return ((isLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
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
    return (DaysInCurrentMonth(Date, Date.month) - Date.day );
}
short DaysUntilEndOfYear(short numberOfDaysInAYear, short daysFromBeginngOfYear)
{
    return (numberOfDaysInAYear - daysFromBeginngOfYear);
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

stDate PrintDateToday(stDate Date, short dayOfWeekOrder)
{
    cout << "Today is " << DayShortName(dayOfWeekOrder) << " , " 
         << to_string(Date.month) << "/" << to_string(Date.day) << "/" << to_string(Date.year);
}

bool isItEndOfWeek(short dayOfWeekOrder)
{
    return (dayOfWeekOrder == 6) ? true : false;
}
bool isItWeekend(short dayOfWeekOrder)
{
    return (dayOfWeekOrder == 6 || dayOfWeekOrder == 5) ? true : false;
}
bool isItBusinessDay(short dayOfWeekOrder)
{
    return !(dayOfWeekOrder == 6 || dayOfWeekOrder == 5) ? true : false;
}
bool isLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short NumberOfDaysInAYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}
stDate ReadDateInfo()
{
    stDate Date;

    Date.day = GetValidPositiveIntegerInRange("\nPlease Enter a Day: ", 1, 31);
    Date.month = GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
    Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

    return Date;
}
