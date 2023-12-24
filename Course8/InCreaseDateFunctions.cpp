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

short GetDifferenceInDays(stDate, stDate);
string ConvertTotalDaysToDate(short, short);

short DaysFromBeggingOfYear(stDate);
stDate GetSystemDate();
short GetValidPositiveIntegerInRange(string message, short min, short max);

stDate IncreaseDateByOneDay(stDate Date);
stDate IncreaseDateByXDays(stDate Date, short);
stDate IncreaseDateByOneWeek(stDate Date);
stDate IncreaseDateByXWeeks(stDate Date, short);
stDate IncreaseDateByOneMonth(stDate Date);
stDate IncreaseDateByXMonths(stDate Date, short);
stDate IncreaseDateByOneYear(stDate Date);
stDate IncreaseDateByXYears(stDate Date, short);
stDate IncreaseDateByOneDecade(stDate Date);
stDate IncreaseDateByXDecades(stDate Date, short);
stDate IncreaseDateByOneCentury(stDate Date);
stDate IncreaseDateByXCenturies(stDate Date, short);
bool IsLastMonthInYear(short month);
bool IsLastDayInMonth(stDate Date);
bool isLeapYear(short);
short NumberOfDaysInAYear(short year);
short DaysInCurrentMonth(short year, short month);
short DaysInCurrentMonthInNotLeapYear(short month);

stDate ReadDateInfo();

int main()
{
	stDate Date;

	cout << "\nPlease Enter Your Date Of Birth:\n";
	Date = ReadDateInfo();

	short daysFromBeggingOfYear = DaysFromBeggingOfYear(Date);

	cout << "\nDate After: ";

	Date = IncreaseDateByOneDay(Date);
	cout << "\n1] Adding one day is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXDays(Date, 5);
	cout << "\n2] Adding 5 days is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXDays(Date, 10);
	cout << "\n2] Adding 10 days is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXDays(Date, 20);
	cout << "\n2] Adding 20 days is: " << Date.month << "/" << Date.day << "/" << Date.year;

	

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n\n\n3] Adding one week is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "\n4] Adding ten weeks is: " << Date.month << "/" << Date.day << "/" << Date.year;

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n\n\n5] Adding one month is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXMonths(Date, 10);
	cout << "\n6] Adding ten months is: " << Date.month << "/" << Date.day << "/" << Date.year;

	Date = IncreaseDateByOneYear(Date);
	cout << "\n\n\n7] Adding one year is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXYears(Date, 10);
	cout << "\n8] Adding ten years is: " << Date.month << "/" << Date.day << "/" << Date.year;

	Date = IncreaseDateByOneDecade(Date);
	cout << "\n\n\n9] Adding one decade is: " << Date.month << "/" << Date.day << "/" << Date.year;
	
	Date = IncreaseDateByXDecades(Date, 10);
	cout << "\n10] Adding ten decades is:" << Date.month << "/" << Date.day << "/" << Date.year;

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n\n\n11] Adding one century is:" << Date.month << "/" << Date.day << "/" << Date.year;

	Date = IncreaseDateByXCenturies(Date, 10);
	cout << "\n12] Adding ten centuries is: " << Date.month << "/" << Date.day << "/" << Date.year;
}

short DaysFromBeggingOfYear(stDate Date)
{
	short numberOfDaysInAMonth = 0;

	for (short i = 1; i < Date.month; i++)
	{
		numberOfDaysInAMonth += DaysInCurrentMonth(Date, i);
	}
	
	return numberOfDaysInAMonth += Date.day;
}

bool isLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
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

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
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
	else
		Date.day++;
	return Date;
}

stDate IncreaseDateByXDays(stDate Date, short daysToAdd)
{
	for(short i = 0; i < daysToAdd; ++i)
		Date = IncreaseDateByOneDay(Date);
	
	return Date;
}
bool IsLastDayInMonth(stDate Date)
{
	return Date.day == DaysInCurrentMonth(Date.year, Date.month) ? true : false;
}
stDate IncreaseDateByOneWeek(stDate Date)
{
	for(short i = 0; i < 7; ++i)
		Date = IncreaseDateByOneDay(Date);
	return Date;
}
stDate IncreaseDateByXWeeks(stDate Date, short weeksToAdd)
{
	for (short i = 0; i < weeksToAdd; ++i)
		Date = IncreaseDateByOneWeek(Date);
	return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
	if(Date.month == 12)
	{ 
		Date.month = 1;
		Date.year++;
	}
	else 
		Date.month++;
	short daysInCurrentMonth = DaysInCurrentMonth(Date.year, Date.month);
	if(Date.day > daysInCurrentMonth)
		Date.day = daysInCurrentMonth;
	return Date;
}
stDate IncreaseDateByXMonths(stDate Date, short monthsToAdd)
{
	for (short i = 0; i < monthsToAdd; ++i)
		Date = IncreaseDateByOneMonth(Date);
	return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{
	Date.year++;
	return Date;
}
stDate IncreaseDateByXYears(stDate Date, short yearsToAdd)
{
	Date.year += yearsToAdd;
	return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.year += 10;
	return Date;
}
stDate IncreaseDateByXDecades(stDate Date, short decadesToAdd)
{
	Date.year += (10 * decadesToAdd); 
	return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.year += 100;
	return Date;
}
stDate IncreaseDateByXCenturies(stDate Date, short centuriesToAdd)
{
	Date.year += (100 * centuriesToAdd);
	return Date;
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
			cin.clear();										 // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "\nInvalid input. Please enter a positive shorteger." << endl;
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
 
bool IsLastMonthInYear(short month)
{
	return (month == 12) ? true : false;
}
bool isLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date.year, Date.month)) ? true : false;
}
