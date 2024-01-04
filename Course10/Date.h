#pragma warning (disable : 4996)
#pragma once
#include <iostream>
#include "String.h"
#include <ctime>
using namespace std;

class Date
{
protected: 
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

public:
    short _day;
    short _month;
    short _year;

    Date()
    {

    }
    Date(string dateString)
    {
        ReadDateString(dateString);
    }
    Date(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    Date(short daysFromBeginningOfYear, short year)
    {
        Date date = GetdateFromDayOrderInYear(year, daysFromBeginningOfYear);
        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }
    void setDay(short day)
    {
        _day = day;
    }
    void setMonth(short month)
    {
        _month = month;
    }
    void setYear(short year)
    {
        _year = year;
    }
    
    static bool IsFirstMonthInYear(short month)
    {
        return month == 1;
    }
    static bool IsFirstMonthInYear(Date date)
    {
        return date._month == 1;
    }
    bool IsFirstMonthInYear()
    {
        return this->_month == 1;
    }
    static bool IsFirstDayInMonth(short day)
    {
        return day == 1;
    }
    static bool IsFirstDayInMonth(Date date)
    {
        return date._day == 1;
    }
    bool IsFirstDayInMonth()
    {
        return this->_day == 1;
    }
    static bool IsItBusinessDay(short dayOfWeekOrder)
    {
        return dayOfWeekOrder >= 1 && dayOfWeekOrder <= 4;
    }
    static bool IsItBusinessDay(Date date)
    {
        return IsItBusinessDay(DayOfWeekOrder(date));
    }
    bool IsItBusinessDay()
    {
        return IsItBusinessDay(this->_day);
    }
    static bool IsLeapYear(short year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }    
    bool IsLeapYear()
    {
        return IsLeapYear(this->_year);
    }
    static bool IsLastDayInMonth(short day, short month, short year)
    {
        return (day == DaysInCurrentMonth(year, month));
    }
    static bool IsLastDayInMonth(Date date)
    {
        return IsLastDayInMonth(date._day, date._month, date._year);
    }
    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }
    static bool IsLastMonthInYear(short month)
    {
        return (month == 12);
    }
    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(this->_month);
    }
    static bool IsValidDate(short day, short month, short year)
    {
        return (month <= 12 && day <= DaysInCurrentMonth(year, month));
    }
    bool IsValidDate()
    {
        return IsValidDate(this->_day, this->_month, this->_year);
    }
    static bool IsDate1AfterDate2(Date date1, Date date2)
	{
		return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualToDate2(date1, date2));

	}
	bool IsDateAfterDate2( Date date2)
	{
		return IsDate1AfterDate2(*this, date2);
	}
    static bool IsDate1BeforeDate2(Date date1, Date date2)
    {
        if((date1._year < date2._year) || (date1._month < date2._month) || (date1._day < date2._day))
            return true;
        return false;
    }
    bool IsDate1BeforeDate2(Date date2)
    {
        return IsDate1BeforeDate2(*this, date2);
    }
    static bool IsDate1EqualToDate2(Date date1, Date date2)
    {
        return (date1._year == date2._year && date1._month == date2._month && date1._day == date2._day);
    }       
    bool IsDate1EqualToDate2(Date date2)
    {
        return IsDate1EqualToDate2(*this, date2);
    }
    static short DaysInCurrentMonthInNotLeapYear(short month)
    {
        short array[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return array[month];
    }
    short DaysInCurrentMonthInNotLeapYear()
    {
        return DaysInCurrentMonthInNotLeapYear(this->_month);
    }
    static short DaysInYear(short year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }
    short DaysInYear()
    {
        return DaysInYear(this->_year);
    }
    static short DaysInCurrentMonth(short year, short month)
    {
        return ((IsLeapYear(year) && month == 2) ? 29 : DaysInCurrentMonthInNotLeapYear(month));
    }
    short DaysInCurrentMonth()
    {
        return DaysInCurrentMonth(this->_year, this->_month);   
    }
    short DaysInSpecificMonth(short month)
    {
        return DaysInCurrentMonth(this->_year, month);   
    }
    static short NumberOfDaysInAYear(short year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }
    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(this->_year);
    }

//! Days From Beginning of year  //////////////////////////////////////////////////////////////////////////////
    static short DaysFromBeginningOfYear(short day, short month, short year)
    {
        short numberOfDaysInAMonth = 0;

        for (int i = 1; i < month; i++)
        {
            numberOfDaysInAMonth += DaysInCurrentMonth(year, month);
        }

        return numberOfDaysInAMonth += day;
    }
    static short DaysFromBeginningOfYear(Date date)
    {
        return DaysFromBeginningOfYear(date._day, date._month, date._year);
    }
    short DaysFromBeginningOfYear()
    {
        return DaysFromBeginningOfYear(this->_day, this->_month, this->_year);
    }

//! Convert days from beginning of year to class //////////////////////////////////////////////////////////////////////////////
    static Date GetdateFromDayOrderInYear(unsigned short year, short daysFromBeginningOfYear)
    {
        Date date;
        date._year = year;
        date._month = 1;
        short remainingDays = daysFromBeginningOfYear;
        short numberOfDaysInMonth = 1;
        while (true)
        {
            numberOfDaysInMonth = DaysInCurrentMonth(date._year, date._month);
            if (remainingDays > numberOfDaysInMonth)
            {
                remainingDays -= numberOfDaysInMonth;
                ++date._month;
            }
            else
            {
                date._day = remainingDays;
                break;
            }
        }
        return date;
    }
    Date GetdateFromDayOrderInYear(short year, short daysFromBeginningOfYear)
    {       
        return GetdateFromDayOrderInYear(year, daysFromBeginningOfYear);
    }
    
//! Get Difference in days ///////////////////////////////////////////////////////////////////////////////////////////////////
    static int CalculateDifferenceInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}
    short CalculateDifferenceInDays(Date date2, bool includeEndDay)
    {
        return CalculateDifferenceInDays(*this, date2, includeEndDay);
    }
//! Get System Date /////////////////////////////////////////////////////////////////////////////////////////
    static Date GetSystemDate()
    {
        Date date;
        
        time_t t = time(0);
        tm* now = localtime(&t);

        date._year = now->tm_year + 1900;
        date._month = now->tm_mon + 1;
        date._day = now-> tm_mday;

        return date;
    }
    Date GetCurrentDate()
    {
        return GetSystemDate();
    }

//! Date to String /////////////////////////////////////////////////////////////////////////////////////////
    static string DateToString(Date date)
    {
        return (to_string(date._month) + "/" + to_string(date._day) + "/" + to_string(date._year));
    }
    string DateToString()
    {
        return DateToString(*this);
    }

     
    //! Calculate Vacation Return Date //////////////////////////////////////////////////////////////////////////////////
    static short DayOfWeekOrder(short day, short month, short year)
    {
        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    static short DayOfWeekOrder(Date date)
    {
        return DayOfWeekOrder(date._day, date._month, date._year);
    }
    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(*this);
    }

    static string ConvertTotalDaysToDate(short year, int daysFromBeggingOfYear)
    {
        Date date;
        date._year = year;
        date._month = 1;
        short remainingDays = daysFromBeggingOfYear;
        short numberOfDaysInMonth = 1;
        while (true)
        {
            numberOfDaysInMonth = DaysInCurrentMonth(date._year, date._month);
            if (remainingDays > numberOfDaysInMonth)
            {
                remainingDays -= numberOfDaysInMonth;
                ++date._month;
            }
            else
            {
                date._day = remainingDays;
                break;
            }
        }

        return to_string(date._month) + "/" + to_string(date._day) + "/" + to_string(date._year);
    }
    string ConvertTotalDaysToDate(short daysFromBeggingOfYear)
    {
        return ConvertTotalDaysToDate(this->_year);
    }
    static enDateCompare CompareDates(Date date1, Date date2)
	{
		if (IsDate1BeforeDate2(date1, date2))
			return enDateCompare::Before;

		if (IsDate1EqualToDate2(date1, date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}
	enDateCompare CompareDates(Date date2)
	{
		return CompareDates(*this, date2);
	}

    static string DayShortName(short day, short month, short year)
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arrDayNames[DayOfWeekOrder(day, month, year)];
    }
    static string DayShortName(Date date)
    {
        return DayShortName(date._day, date._month, date._year);
    }
    string DayShortName()
    {
        return DayShortName(*this);
    }
    static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return MonthShortName(_month);
	}

    //! Days Until End of ... ///////////////////////////////////////////////////////////////////////////////////////////
    static short DaysUntilEndOfWeek(short day, short month, short year)
    {
        return 6 - DayOfWeekOrder(day, month, year);
    }
    static short DaysUntilEndOfWeek(Date date)
    {
        return DaysUntilEndOfWeek(date._day, date._month, date._year);
    }
    short DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }

    static short DaysUntilEndOfMonth(short day, short month, short year)
    {
        return (DaysInCurrentMonth(year, month) - day );
    }   
    static short DaysUntilEndOfMonth(Date date)
    {
        return DaysUntilEndOfMonth(date._day, date._month, date._year);
    }
    short DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }

    static short DaysUntilEndOfYear(short numberOfDaysInAYear, short daysFromBeginngOfYear)
    {
        return (numberOfDaysInAYear - daysFromBeginngOfYear);
    }
    static short DaysUntilEndOfYear(short day, short month, short year)
    {
        return (NumberOfDaysInAYear(year) - DaysFromBeginningOfYear(day, month, year));
    }   
    static short DaysUntilEndOfYear(Date date)
    {
        return DaysUntilEndOfYear(date._day, date._month, date._year);
    }
    short DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }

    //!Add  ///////////////////////////////////////////////////////////////////////////////////////////
    static void IncrementMonthAndYear(short &day, short &month, short &year)
    {
        if (IsLastMonthInYear(month))
        {
            ++year;
            month = 1;
            day = 1;
        }
        else
        {
            day = 1;
            ++month;
        }
    }
    static void IncrementMonthAndYear(Date &date)
    {
        return IncrementMonthAndYear(date._day, date._month, date._year);
    }
    void IncrementMonthAndYear()
    {
        return IncrementMonthAndYear(*this);
    }
    static Date AddOneDay(Date date)
    {
        if (IsLastDayInMonth(date))
            IncrementMonthAndYear(date);
        else        
            ++date._day;
        return date;
    }
    Date AddOneDay()
    {
        return AddOneDay(*this);
    }
    static Date AddXDays(Date date, short daysToAdd)
    {
        for(short i = 0; i < daysToAdd; ++i)
            date = AddOneDay(date); 

        return date;
    }
    Date AddXDays(short daysToAdd)
    {
        return AddXDays(*this, daysToAdd);
    }
    static Date AddOneWeek(Date date)
    {
        for (short i = 0; i < 7; ++i)
            date = AddOneDay(date);
        return date;
    }
    Date AddOneWeek()
    {
        return AddOneWeek(*this);
    }
    static Date AddXWeeks(Date date, short weeksToAdd)
    {
        for (short i = 0; i < weeksToAdd; ++i)
            date = AddOneWeek(date);
        return date;
    }
    Date AddXWeeks(short weeksToAdd)
    {
        return AddXWeeks(*this, weeksToAdd);
    }
    static Date AddOneMonth(Date date)
    {
        if(date._month == 12)
        { 
            date._month = 1;
            date._year++;
        }
        else 
            date._month++;
        short daysInCurrentMonth = DaysInCurrentMonth(date._year, date._month);
        if(date._day > daysInCurrentMonth)
            date._day = daysInCurrentMonth;

        return date;
    }
    Date AddOneMonth()
    {
        return AddOneMonth(*this);
    }
    static Date AddXMonths(Date date, short monthsToAdd)
    {
        for (short i = 0; i < monthsToAdd; ++i)
            date = AddOneMonth(date);
        return date;
    }
    Date AddXMonths(short monthsToAdd)
    {
        return AddXMonths(*this, monthsToAdd);
    }
    static Date AddOneYear(Date date)
    {
        date._year++;
        return date;
    }
    Date AddOneYear()
    {
        return AddOneYear(*this);
    }
    static Date AddXYears(Date date, short yearsToAdd)
    {
        date._year += yearsToAdd;
        return date;
    }
    Date AddXYears(short yearsToAdd)
    {
        return AddXYears(*this, yearsToAdd);
    }
    static Date AddOneDecade(Date date)
    {
        date._year += 10;
        return date;
    }
    Date AddOneDecade()
    {
        return AddOneDecade(*this);
    }
    static Date AddXDecades(Date date, short decadesToAdd)
    {
        date._year += (10 * decadesToAdd); 
        return date;
    }
    Date AddXDecades(short decadesToAdd)
    {
        return AddXDecades(*this, decadesToAdd);
    }
    static Date AddOneCentury(Date date)
    {
        date._year += 100;
        return date;
    }
    Date AddOneCentury()
    {
        return AddOneCentury(*this);
    }
    static Date AddXCenturies(Date date, short centuriesToAdd)
    {
        date._year += (100 * centuriesToAdd);
        return date;
    }
    Date AddXCenturies(short centuriesToAdd)
    {
        return AddXCenturies(*this, centuriesToAdd);
    }
    static Date AddOneMillennium(Date date)
	{
		//Period of 1000 years
		date._year += 1000;
		return date;
	}
	Date AddOneMillennium()
	{
		return AddOneMillennium(*this);
	}
    static Date AddXMillinia(Date date, short milliniaToAdd)
    {
        date._year += (milliniaToAdd*1000);
        return date;
    }
    Date AddXMillinia(short milliniaToAdd)
    {
        return AddXMillinia(*this, milliniaToAdd);
    }
    //! Subtract Days ///////////////////////////////////////////////////////////////////////////////////////////
    static void DecrementMonthAndYear(short &day, short &month, short &year)
    {
        if (IsFirstMonthInYear(month))
        {
            --year;
            month = 12;
            day = 31;
        }
        else
        {
            day = DaysInCurrentMonth(year, month);
            --month;
        }
    }
    static void DecrementMonthAndYear(Date &date)
    {
        return DecrementMonthAndYear(date._day, date._month, date._year);
    }
    void DecrementMonthAndYear()
    {
        return DecrementMonthAndYear(*this);
    }
    static Date SubtractOneDay(Date date)
    {
        if (IsFirstDayInMonth(date))
            DecrementMonthAndYear(date);
        else        
            --date._day;
        return date;
    }
    Date SubtractOneDay()
    {
        return SubtractOneDay(*this);
    }
    static Date SubtractXDays(Date date, short daysToSubtract)
    {
        for (short i = 0; i < daysToSubtract; ++i)
            date = SubtractOneDay(date);

        return date;
    }
    Date SubtractXDays(short daysToSubtract)
    {
        return SubtractXDays(*this, daysToSubtract);
    }
    static Date SubtractOneWeek(Date date)
    {
        for (short i = 0; i < 7; ++i)
            date = SubtractOneDay(date);
        return date;
    }
    Date SubtractOneWeek()
    {
        return SubtractOneWeek(*this);
    }
    static Date SubtractXWeeks(Date date, short weeksToSubtract)
    {
        for (short i = 0; i < weeksToSubtract; ++i)
            date = SubtractOneWeek(date);
        return date;
    }
    Date SubtractXWeeks(short weeksToSubtract)
    {
        return SubtractXWeeks(*this, weeksToSubtract);
    }
    static Date SubtractOneMonth(Date date)
    {
        if (date._month == 1)
        {
            date._month = 12;
            --date._year;
        }
        else
            --date._month;
        short daysInCurrentMonth = DaysInCurrentMonth(date._year, date._month);
        if (date._day > daysInCurrentMonth)
            date._day = daysInCurrentMonth;
        return date;
    }
    Date SubtractOneMonth()
    {
        return SubtractOneMonth(*this);
    }
    static Date SubtractXMonths(Date date, short monthsToSubtract)
    {
        for (short i = 0; i < monthsToSubtract; ++i)
            date = SubtractOneMonth(date);
        return date;
    }
    Date SubtractXMonths(short monthsToSubtract)
    {
        return SubtractXMonths(*this, monthsToSubtract);
    }
    static Date SubtractOneYear(Date date)
    {
        --date._year;
        return date;
    }
    Date SubtractOneYear()
    {
        return SubtractOneYear(*this);
    }
    static Date SubtractXYears(Date date, short yearsToSubtract)
    {
        date._year -= yearsToSubtract;
        return date;
    }
    Date SubtractXYears(short yearsToSubtract)
    {
        return SubtractXYears(*this, yearsToSubtract);
    }
    static Date SubtractOneDecade(Date date)
    {
        date._year -= 10;
        return date;
    }
    Date SubtractOneDecade()
    {
        return SubtractOneDecade(*this);
    }
    static Date SubtractXDecades(Date date, short decadesToSubtract)
    {
        date._year -= (10 * decadesToSubtract);
        return date;
    }
    Date SubtractXDecades(short decadesToSubtract)
    {
        return SubtractXDecades(*this, decadesToSubtract);
    }
    static Date SubtractOneCentury(Date date)
    {
        date._year -= 100;
        return date;
    }
    Date SubtractOneCentury()
    {
        return SubtractOneCentury(*this);
    }
    static Date SubtractXCenturies(Date date, short centuriesToSubtract)
    {
        date._year -= (100 * centuriesToSubtract);
        return date;
    }
    Date SubtractXCenturies(short centuriesToSubtract)
    {
        return SubtractXCenturies(*this, centuriesToSubtract);
    }
	static Date SubtractOneMillennium(Date &Date)
	{
		//Period of 1000 years
		Date._year -= 1000;
		return Date;
	}
	void SubtractOneMillennium()
	{
		SubtractOneMillennium(*this);
	}

    //! Print /////////////////////////////////////////////////////////////////////////////////////////////////
    static void PrintDate(Date date)
    {
        cout << DateToString(date);
    }
    static string PrintSystemDate()
    {
        return DateToString(GetSystemDate());
    }
    void Print()
    {
        cout << DateToString() << endl;
    }
	static void PrintMonthCalendar(short Month, short Year)
	{
		short NumberOfDays;

		// Index of the day from 0 to 6
		short current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = DaysInCurrentMonth(Month, Year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		short i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_month, _year);
	}
	static void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");


		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

		return;
	}
	void PrintYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _year);
		printf("  _________________________________\n");


		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, _year);
		}

		return;
	}

    //! Swap Dates /////////////////////////////////////////////////////////////////////////////////////////////////
	static void SwapDates(Date & Date1, Date & Date2)
	{

		Date TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	//! Calculate /////////////////////////////////////////////////////////////////////////////////////////////////
    static short CalculateBusinessDays(Date DateFrom, Date DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsItBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}
    static short CalculateMyAgeInDays(Date DateOfBirth)
	{
		return CalculateDifferenceInDays(DateOfBirth, GetSystemDate(), true);
	}
    static short CalculateMyAgeInDays(Date dateOfBirth, Date dateOfDeath)
    {
        return CalculateDifferenceInDays(dateOfBirth, dateOfDeath, true);
    }
	static short CalculateVacationDays(Date dateFrom, Date DateTo)
	{
		return CalculateBusinessDays(dateFrom, DateTo);
	}
	static Date CalculateVacationReturnDate(Date dateFrom, short VacationDays)
	{
		short weekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{
			if (!IsItBusinessDay(dateFrom))
				weekEndCounter++;

			dateFrom = AddOneDay(dateFrom);
		}

		for (short i = 1; i <= weekEndCounter; i++)
			dateFrom = AddOneDay(dateFrom);

		return dateFrom;
	}
    static Date CalcVacationReturnDate(Date date, short vacationDays)
    {
        while (vacationDays != 0)
        {
            if (IsItBusinessDay(DayOfWeekOrder(date)))
                vacationDays--;
            date = AddOneDay(date);
        }
        return date;
    }
    Date CalcVacationReturnDate(short vacationDays)
    {
        return CalcVacationReturnDate(*this, vacationDays);
    }
    static short CalcVacationPeriods(Date date1, Date date2) 
    {
        short differenceInDaysExceptWeekends = 0;

        while(IsDate1BeforeDate2(date1, date2))
        {
            // if(!IsDayWeekend(weekDays, ConvertToPosition(DayOfWeekOrder(Date1)+1)))
            //     differenceInDaysExceptWeekends++;
            if(IsItBusinessDay(DayOfWeekOrder(date1)))
                differenceInDaysExceptWeekends++;

            date1 = AddOneDay(date1);    
        }
        
        return differenceInDaysExceptWeekends;
    }
    short CalcVacationPeriods(Date date2) 
    {
        return CalcVacationPeriods(*this, date2);
    }

    //! ReadDateString ///////////////////////////////////////////////////////////////////////////////////////////////////
    static Date ParseDateString(string stringdate)
    {
        Date date;
        vector<string> vDate;
        vDate = String::SplitString(stringdate, "/");
        
        date._day   = stoi(vDate[0]);
        date._month = stoi(vDate[1]);
        date._year  = stoi(vDate[2]);

        return date;
    }
    Date ReadDateString(string stringdate)
    {        
        return ParseDateString(stringdate);
    }
	

};

