#include <iostream>
#include <string>
using namespace std;

struct stDate
{
	int year = 1;
	short month = 1;
	short day = 1;
};

string ConvertTotalDaysToDate(int, short);
short DaysFromBeggingOfYear(int, short, short);
bool isLeapYear(int);
short NumberOfDaysInMonth(int, short);
short NumberOfDaysInMonthInNotLeapYear(int, short);

int main()
{	
    

	int year = 1;
	short month = 1, day = 1;

    cout << "\nPlease Enter Your Date Of Birth:\n";
	cout << "\nPlease Enter a Day: ";
	cin >> day;

	cout << "\nPlease Enter a Month: ";
	cin >> month;

	cout << "\nPlease Enter a Year: ";
	cin >> year;

	short daysFromBeggingOfYea r = DaysFromBeggingOfYear(year, month, day);

	cout << "\nNumber Of Days From Beginning Of Year is: " << daysFromBeggingOfYear;

	cout << "\nThis is the new function :-)\n";

	cout << "\nDate for [" << daysFromBeggingOfYear << "] is: " << ConvertTotalDaysToDate(year, daysFromBeggingOfYear);


}

short DaysFromBeggingOfYear(int year, short month, short day)
{
	short numberOfDaysInAMonth = 0;

	for (short i = 1; i < month; i++)
	{
		numberOfDaysInAMonth += NumberOfDaysInMonth(year, i);
	}
	return numberOfDaysInAMonth += day;
}

bool isLeapYear(int year)
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonthInNotLeapYear(int year, short month)
{
	short array[] = { 1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return array[month];
}

short NumberOfDaysInMonth(int year, short month)
{
	return((isLeapYear(year) && month == 2) ? 29 : NumberOfDaysInMonthInNotLeapYear(year, month));
}

string ConvertTotalDaysToDate(int year, short daysFromBeggingOfYear)
{
	stDate Date;
	Date.year = year;
	Date.month = 1;
	short remainingDays = daysFromBeggingOfYear;
	short numberOfDaysInMonth = 1;
	while (true)
	{
		numberOfDaysInMonth = NumberOfDaysInMonth(Date.year, Date.month);
		if (remainingDays > numberOfDaysInMonth)
		{
			remainingDays -= numberOfDaysInMonth;
			++Date.month;
		}
		else
		{
			Date.day = remainingDays;
			break;
		}
	}

	return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
}