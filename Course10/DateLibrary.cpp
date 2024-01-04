#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date date2 = Date::GetSystemDate();
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
    
    Date date1;
    // date2 = date2.ReadDateString("12/1/2024");
    // cout << "\nthe vacation from today until 12/1/2024 is: " << date2.CalculateBusinessDays(date1, date2);
    date1 = Date::ParseDateString("11/29/2003");
    cout << "\nMy Age in Days is: " << date1.CalculateMyAgeInDays(date1, date2);
ing_ad
} 

