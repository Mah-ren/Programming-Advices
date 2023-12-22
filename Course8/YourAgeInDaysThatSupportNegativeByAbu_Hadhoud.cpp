#pragma warning (disable : 4996)

#include <iostream>
#include <limits>
#include <string>
#include <ctime>

using namespace std;

struct stDate
{
	int year = 1;
	int month = 1;
	int day = 1;
};

int GetDifferenceInDays(stDate, stDate);
string ConvertTotalDaysToDate(int, int);

int DaysFromBeggingOfYear(stDate);

stDate GetSystemDate();
int GetValidPositiveIntegerInRange(string message, int min, int max);

bool isDate1BeforeDate2(stDate Date1, stDate Date2);
bool isLeapYear(int);

int NumberOfDaysInAYear(int year);
int NumberOfDaysInMonth(stDate);
int NumberOfDaysInMonthInNotLeapYear(stDate);

stDate ReadDateInfo();
void SwapDates(stDate &Date1, stDate &Date2);

int main()
{	
    stDate Date1, Date2;
   
    cout << "\nPlease Enter Your Date Of Birth:\n";
	Date1 = ReadDateInfo();
	Date2 = GetSystemDate();

	cout << "\nYour Age In Days is: " << GetDifferenceInDays(Date1, Date2);
}

int DaysFromBeggingOfYear(stDate Date)
{
	int numberOfDaysInAMonth = 0;

	for (int i = 1; i < Date.month; i++)
	{
		numberOfDaysInAMonth += NumberOfDaysInMonth(Date);
	}
	return numberOfDaysInAMonth += Date.day;
}

bool isLeapYear(int year)
{
	return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int NumberOfDaysInAYear(int year)
{
	return isLeapYear(year) ? 366 : 365;
}

int NumberOfDaysInMonthInNotLeapYear(stDate Date)
{
	int array[] = { 1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return array[Date.month];
}

int NumberOfDaysInMonth(stDate Date)
{
	return((isLeapYear(Date.year) && Date.month == 2) ? 29 : NumberOfDaysInMonthInNotLeapYear(Date));
}

string ConvertTotalDaysToDate(int year, int daysFromBeggingOfYear)
{
	stDate Date;
	Date.year = year;
	Date.month = 1;
	int remainingDays = daysFromBeggingOfYear;
	int numberOfDaysInMonth = 1;
	while (true)
	{
		numberOfDaysInMonth = NumberOfDaysInMonth(Date);
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

	return to_string(Date.month) + "/" + to_string(Date.day) + "/" + to_string(Date.year);
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
            cin.clear();                                         // Clear the error flag
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
	tm* now = localtime(&t);

	Date.year = now->tm_year + 1900;
	Date.month = now->tm_mon + 1;
	Date.day = now-> tm_mday;

	return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2)
{
    // if(!isDate1BeforeDate2(Date1, Date2))
    // {
    //     SwapDates(Date1, Date2);
    // }

	int differenceInDays = 0;
	for(int yearOfDate1 = (Date1.year + 1); yearOfDate1 < Date2.year; ++yearOfDate1)
		differenceInDays += NumberOfDaysInAYear(yearOfDate1);
	differenceInDays += ((NumberOfDaysInAYear(Date1.year) - DaysFromBeggingOfYear(Date1)) + DaysFromBeggingOfYear(Date2));

	return differenceInDays;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    if((Date1.year < Date2.year) || (Date1.month < Date2.month) || (Date1.day < Date2.day))
        return true;
    return false;
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
	Date.month =GetValidPositiveIntegerInRange("\nPlease Enter a Month: ", 1, 12);
	Date.year = GetValidPositiveIntegerInRange("\nPlease Enter a Year: ", 1, 3000);

	return Date;
}