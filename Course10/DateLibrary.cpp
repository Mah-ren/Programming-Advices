#include <iostream>
#include "Date.h"
using namespace std;


int main()
{
    Date date1 = Date::ParseDateString("12/31/2024");
    Date date2 = Date::ParseDateString("12/31/2024");

    // cout << "\ntoday is: " << Date::PrintSystemDate() << endl;
    // cout << "\n";
    // cout << "\n" << Date::DateString(Date::AddOneCentury(Date::GetSystemDate()));
    // cout << "\n" << Date::DateString(date.AddOneDay());
    // cout << date.DateString(date.AddOneDecade());
    // cout << date.DateToString(date.AddOneMillennium());
    // cout << date.DateToString(date.AddOneMonth()); 
    // cout << date.DateToString(date.AddOneWeek());
    // cout << date.DateToString(date.AddOneYear());
    // cout << date.DateToString(date.AddXCenturies(2));
    // cout << date.DateToString(date.AddXDays(30));
    // cout << date.DateToString(date.AddXDecades(10));
    // cout << date.DateToString(date.AddXMillinia(10));
    // cout << date.DateToString(date.AddXMonths(10));
    // cout << date.DateToString(date.AddXWeeks(3));
    // cout << date.DateToString(date.AddXYears(3));
    // date2 = date2.ReadDateString("29/11/2003");
    // cout << "\nthe vacation from today until 12/1/2024 is: " << date2.CalculateBusinessDays(date1, date2);
    // date1 = Date::ParseDateString("11/29/2003");
    // cout << "\nMy Age in Days is: " << Date::CalculateMyAgeInDays(Date::ParseDateString("29/11/2003"), Date::ParseDateString("4/1/2024"));
    // cout << Date::CalculateVacationDays(date1, date2);

    //! there is a problem with these functions     
    //! cout << "\nVacation periods is: " << Date::CalcBusinessDays(date1, date2);
    //! cout << "\ni will come in: " << Date::DateToString(Date::CalcVacationReturnDate(date1, 10));

    // cout << "\nCompare two dates: " << date1.ConvertTotalDaysToDate(300);
    // cout << "\n" << date1.DateToString(date1);
    // cout << "\n" << date1.DayOfWeekOrder() ;
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 1, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 2, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 3, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 4, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 5, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 6, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 7, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 8, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 9, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 10, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(1, 11, 2024);
    cout << "\n" << Date::DaysFromBeginningOfYear(31, 12, 2024);



} 

