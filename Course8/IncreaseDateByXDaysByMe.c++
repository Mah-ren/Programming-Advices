#pragma warning(disable : 4996)

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

int GetDifferenceInDays(stDate, stDate);
string ConvertTotalDaysToDate(int, int);

int DaysFromBeggingOfYear(stDate);

stDate GetSystemDate();
int GetValidPositiveIntegerInRange(string message, int min, int max);

stDate IncreaseDateByOneDay(stDate Date);
stDate IncreaseDateByXDays(stDate Date, int);
stDate IncreaseDateByOneWeek(stDate Date);
stDate IncreaseDateByXWeeks(stDate Date, int);
stDate IncreaseDateByOneMonth(stDate Date);
stDate IncreaseDateByXMonths(stDate Date, int);
stDate IncreaseDateByOneYear(stDate Date);
stDate IncreaseDateByXYears(stDate Date, int);
stDate IncreaseDateByOneDecade(stDate Date);
stDate IncreaseDateByXDecades(stDate Date, int);
stDate IncreaseDateByOneCentury(stDate Date);
stDate IncreaseDateByXCenturies(stDate Date, int);
bool isDate1BeforeDate(stDate Date, stDate Date2);
bool IsLastMonthInYear(short month);
bool IsLastDayInMonth(stDate Date);
bool isLeapYear(int);

int DaysInCurrentMonth(stDate, short);
int NumberOfDaysInAYear(int year);
int DaysInCurrentMonthInNotLeapYear(stDate);

stDate ReadDateInfo();

int main()
{
	stDate Date;

	cout << "\nPlease Enter Your Date Of Birth:\n";
	Date = ReadDateInfo();

	int daysFromBeggingOfYear = DaysFromBeggingOfYear(Date);

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

int NumberOfDaysInAYear(int year)
{
	return isLeapYear(year) ? 366 : 365;
}

int DaysInCurrentMonthInNotLeapYear(stDate Date)
{
	int array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return array[Date.month];
}

int DaysInCurrentMonth(stDate Date, short month)
{
	return ((isLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
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

stDate IncreaseDateByXDays(stDate Date, int daysToAdd)
{
	for(short i = 0; i < daysToAdd; ++i)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	int remainingDays = daysToAdd;
	short daysRemainingInMonth = 1;
	short daysRemainingInYear = (NumberOfDaysInAYear(Date.year) - daysFromBeginningOfYear);
	short numberOfDaysInYear = 1;

	if (remainingDays > daysRemainingInYear)
	{
		remainingDays -= daysRemainingInYear;
		Date.year++;
		Date.month = 1;
		Date.day = 1;
	}

	while (true)
	{
		short numberOfDaysInYear = NumberOfDaysInAYear(Date.year);
		
		if (remainingDays > numberOfDaysInYear)
		{
			remainingDays -= numberOfDaysInYear;
			Date.year++;
		}
		else
		{
			daysRemainingInMonth = (DaysInCurrentMonth(Date, Date.month) - Date.day);
			
			if (remainingDays > daysRemainingInMonth)
			{
				remainingDays -= daysRemainingInMonth;
				++Date.month;
			}
			else
			{
				Date.day = remainingDays;
				break;
			}
		}
	}

	return Date;
}
bool IsLastDayInMonth(stDate Date)
{
	return Date.day == DaysInCurrentMonth(Date, Date.month) ? true : false;
}

stDate IncreaseDateByOneWeek(stDate Date)
{

	return Date;
}
stDate IncreaseDateByXWeeks(stDate Date, int weeksToAdd)
{

	return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{

	return Date;
}
stDate IncreaseDateByXMonths(stDate Date, int monthsToAdd)
{

	return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{

	return Date;
}
stDate IncreaseDateByXYears(stDate Date, int yearsToAdd)
{

	return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{

	return Date;
}
stDate IncreaseDateByXDecades(stDate Date, int decadesToAdd)
{

	return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{

	return Date;
}
stDate IncreaseDateByXCenturies(stDate Date, int centuriesToAdd)
{

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
			cin.clear();										 // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "\nInvalid input. Please enter a positive integer." << endl;
			continue; // Prompt user again
		}

	} while (number < min || number > max);

	return number;
}
stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm *now = localtime(&t);

	Date.year = now->tm_year + 1900;
	Date.month = now->tm_mon + 1;
	Date.day = now->tm_mday;

	return Date;
}

int GetDifferenceInDays(stDate Date, stDate Date2)
{
	if(!isDate1BeforeDate(Date, Date2))
	{
	    SwapDates(Date, Date2);
	}

	int differenceInDays = 0;
	for (int yearOfDate = (Date.year + 1); yearOfDate < Date2.year; ++yearOfDate)
		differenceInDays += NumberOfDaysInAYear(yearOfDate);
	differenceInDays += ((NumberOfDaysInAYear(Date.year) - DaysFromBeggingOfYear(Date)) + DaysFromBeggingOfYear(Date2));

	return differenceInDays;
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
	return (Date.day == DaysInCurrentMonth(Date, Date.month)) ? true : false;
}
