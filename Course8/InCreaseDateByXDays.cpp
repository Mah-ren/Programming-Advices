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

// int GetDifferenceInDays(stDate, stDate);
string ConvertTotalDaysToDate(int, int);

int DaysFromBeggingOfYear(stDate);

// stDate GetSystemDate();
int GetValidPositiveIntegerInRange(string message, int min, int max);

stDate IncreaseDateByOneDay(stDate Date);
stDate IncreaseDateByXDays(stDate Date, short daysFromBeginningOfYear, int);
// stDate IncreaseDateByOneWeek(stDate Date, short daysFromBeginningOfYear);
// stDate IncreaseDateByXWeeks(stDate Date, short daysFromBeginningOfYear, int);
// stDate IncreaseDateByOneMonth(stDate Date, short daysFromBeginningOfYear);
// stDate IncreaseDateByXMonths(stDate Date, short daysFromBeginningOfYear, int);
// stDate IncreaseDateByOneYear(stDate Date, short daysFromBeginningOfYear);
// stDate IncreaseDateByXYears(stDate Date, short daysFromBeginningOfYear, int);
// stDate IncreaseDateByOneDecade(stDate Date, short daysFromBeginningOfYear);
// stDate IncreaseDateByXDecades(stDate Date, short daysFromBeginningOfYear, int);
// stDate IncreaseDateByOneCentury(stDate Date, short daysFromBeginningOfYear);
// stDate IncreaseDateByXCenturies(stDate Date, short daysFromBeginningOfYear, int);
// bool isDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsLastMonthInYear(short month);
bool IsLastDayInMonth(stDate Date);
bool isLeapYear(int);

int DaysInCurrentMonth(stDate, short);
int NumberOfDaysInAYear(int year);
int DaysInCurrentMonthInNotLeapYear(stDate);

stDate ReadDateInfo();

// void SwapDates(stDate &Date1, stDate &Date2);

int main()
{
	stDate Date1, Date2;

	cout << "\nPlease Enter Your Date Of Birth:\n";
	Date1 = ReadDateInfo();
	// Date2 = GetSystemDate();

	int daysFromBeggingOfYear = DaysFromBeggingOfYear(Date1);

	cout << "\nDate After: ";

	// cout << "\n1] Adding one day is: " << IncreaseDateByOneDay(Date1);
	cout << "\n2] Adding 5 days is: " << IncreaseDateByXDays(Date1, daysFromBeggingOfYear, 5);
	cout << "\n2] Adding 10 days is: " << IncreaseDateByXDays(Date1, daysFromBeggingOfYear, 10);
	cout << "\n2] Adding 20 days is: " << IncreaseDateByXDays(Date1, daysFromBeggingOfYear, 20);

	// cout << "\n\n\n3] Adding one week is: " << IncreaseDateByOneWeek(Date1, daysFromBeggingOfYear);
	// cout << "\n4] Adding ten weeks is: " << IncreaseDateByXWeeks(Date1, daysFromBeggingOfYear, 10);

	// cout << "\n\n\n5] Adding one month is: " << IncreaseDateByOneMonth(Date1, daysFromBeggingOfYear);
	// cout << "\n6] Adding ten months is: " << IncreaseDateByXMonths(Date1, daysFromBeggingOfYear, 10);

	// cout << "\n\n\n7] Adding one year is: " << IncreaseDateByOneYear(Date1, daysFromBeggingOfYear);
	// cout << "\n8] Adding ten years is: " << IncreaseDateByXYears(Date1, daysFromBeggingOfYear, 10);

	// cout << "\n\n\n9] Adding one decade is: " << IncreaseDateByOneDecade(Date1, daysFromBeggingOfYear);
	// cout << "\n10] Adding ten decades is:" << IncreaseDateByXDecades(Date1, daysFromBeggingOfYear, 10);

	// cout << "\n\n\n11] Adding one century is:" << IncreaseDateByOneCentury(Date1, daysFromBeggingOfYear);
	// cout << "\n12] Adding ten centuries is: " << IncreaseDateByXCenturies(Date1, daysFromBeggingOfYear, 10);
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
	//return Date;
}

stDate IncreaseDateByXDays(stDate Date, short daysFromBeginningOfYear, int daysToAdd)
{
	for(short i = 0; i < daysToAdd; ++i)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	// int remainingDays = daysToAdd;
	// short daysRemainingInMonth = 1;
	// short daysRemainingInYear = (NumberOfDaysInAYear(Date.year) - daysFromBeginningOfYear);
	// short numberOfDaysInYear = 1;

	// if (remainingDays > daysRemainingInYear)
	// {
	// 	remainingDays -= daysRemainingInYear;
	// 	Date.year++;
	// 	Date.month = 1;
	// 	Date.day = 1;
	// }

	// while (true)
	// {
	// 	short numberOfDaysInYear = NumberOfDaysInAYear(Date.year);
		
	// 	if (remainingDays > numberOfDaysInYear)
	// 	{
	// 		remainingDays -= numberOfDaysInYear;
	// 		Date.year++;
	// 	}
	// 	else
	// 	{
	// 		daysRemainingInMonth = (DaysInCurrentMonth(Date, Date.month) - Date.day);
			
	// 		if (remainingDays > daysRemainingInMonth)
	// 		{
	// 			remainingDays -= daysRemainingInMonth;
	// 			++Date.month;
	// 		}
	// 		else
	// 		{
	// 			Date.day = remainingDays;
	// 			break;
	// 		}
	// 	}
	// }

	// return Date;
}
bool IsLastDayInMonth(stDate Date)
{
	return Date.day == DaysInCurrentMonth(Date, Date.month) ? true : false;
}

// stDate IncreaseDateByOneWeek(stDate Date, short daysFromBeginningOfYear)
// {

// 	return Date;
// }
// stDate IncreaseDateByXWeeks(stDate Date, short daysFromBeginningOfYear, int weeksToAdd)
// {

// 	return Date;
// }
// stDate IncreaseDateByOneMonth(stDate Date, short daysFromBeginningOfYear)
// {

// 	return Date;
// }
// stDate IncreaseDateByXMonths(stDate Date, short daysFromBeginningOfYear, int monthsToAdd)
// {

// 	return Date;
// }
// stDate IncreaseDateByOneYear(stDate Date, short daysFromBeginningOfYear)
// {

// 	return Date;
// }
// stDate IncreaseDateByXYears(stDate Date, short daysFromBeginningOfYear, int yearsToAdd)
// {

// 	return Date;
// }
// stDate IncreaseDateByOneDecade(stDate Date, short daysFromBeginningOfYear)
// {

// 	return Date;
// }
// stDate IncreaseDateByXDecades(stDate Date, short daysFromBeginningOfYear, int decadesToAdd)
// {

// 	return Date;
// }
// stDate IncreaseDateByOneCentury(stDate Date, short daysFromBeginningOfYear)
// {

// 	return Date;
// }
// stDate IncreaseDateByXCenturies(stDate Date, short daysFromBeginningOfYear, int centuriesToAdd)
// {

// 	return Date;
// }
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
// stDate GetSystemDate()
// {
// 	stDate Date;

// 	time_t t = time(0);
// 	tm *now = localtime(&t);

// 	Date.year = now->tm_year + 1900;
// 	Date.month = now->tm_mon + 1;
// 	Date.day = now->tm_mday;

// 	return Date;
// }

// int GetDifferenceInDays(stDate Date1, stDate Date2)
// {
// 	if(!isDate1BeforeDate2(Date1, Date2))
// 	{
// 	    SwapDates(Date1, Date2);
// 	}

// 	int differenceInDays = 0;
// 	for (int yearOfDate1 = (Date1.year + 1); yearOfDate1 < Date2.year; ++yearOfDate1)
// 		differenceInDays += NumberOfDaysInAYear(yearOfDate1);
// 	differenceInDays += ((NumberOfDaysInAYear(Date1.year) - DaysFromBeggingOfYear(Date1)) + DaysFromBeggingOfYear(Date2));

// 	return differenceInDays;
// }

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
