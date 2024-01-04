#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class Util
{
public:
    static void SwapDates(Date &date1, Date &date2)
    {
        Date Temp;
        Temp._year = date1._year;
        Temp._month = date1._month;
        Temp._day = date1._day;

        date1._year = date2._year;
        date1._month = date2._month;
        date1._day = date2._day;

        date2._year = Temp._year;
        date2._month = Temp._month;
        date2._day = Temp._day;
    }
};