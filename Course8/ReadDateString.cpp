#include <iostream>
#include <vector>
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

string CovertDateToString(stDate Date);

short DaysInCurrentYear(short year);
short DaysInCurrentMonth(stDate Date);
short DaysInCurrentMonth(stDate, short);
short DaysInCurrentMonthInNotLeapYear(short month);
short GetValidPositiveIntegerInRange(string message, short min, short max);

bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short month);
bool IsLeapYear(short year);
bool IsLastDayInMonth(stDate Date);
bool IsValidDate(stDate Date);

short DaysInCurrentMonth(stDate);
short DaysInCurrentMonthInNotLeapYear(stDate);

stDate ReadDateString(string stringDate);

string ReadString(string message);

vector<string> SplitString(string str , string delimeter = " ");

int main()
{
    stDate Date;

    cout << "\nEnter Date to check: ";
    Date = ReadDateString(ReadString("\nPlease Enter Date dd/mm/yyyy? "));

    cout << "\nDay: " << Date.day ;
    cout << "\nmonth: " << Date.month;
    cout << "\nyear: " << Date.year;

    cout << "\nthe is string Date: " << CovertDateToString(Date);

}

string CovertDateToString(stDate Date)
{
    return to_string(Date.month) + "/" + to_string(Date.day) + "/" + to_string(Date.year);
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
short DaysInCurrentMonthInNotLeapYear(stDate Date)
{
    short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return array[Date.month];
}
short DaysInCurrentMonth(stDate Date, short month)
{
	return ((IsLeapYear(Date.year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(Date));
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

bool IsLastMonthInYear(short month)
{
    return month == 12;
}
bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.day == DaysInCurrentMonth(Date, Date.month)) ? true : false;
}
bool IsValidDate(stDate Date)
{
    return (Date.month <= 12 && Date.day <= DaysInCurrentMonth(Date));
}
    
string ReadString(string message)
{
    cout << message;
    cin >> message;

    return message;
}

stDate ReadDateString(string stringDate)
{
    
    vector<string> vDate;
    vDate = SplitString(stringDate, "/");

    stDate Date;

    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);
    
    return Date;
}

vector<string> SplitString(string str , string delimeter)
{
    vector<string> vString ;
    string word ;
    short position = 0 ;
 
    while((position = str.find(delimeter)) != str.npos)
    {   
        word = str.substr(0,position);
        
        if(word != "")
        {
            vString.push_back(word);
        }
        
        str.erase(0 , position + delimeter.length());
    }

    if(str != "")
    {
        vString.push_back(str);
    } 

    return vString ;
}
