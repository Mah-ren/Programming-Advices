#pragma once 
#include <iostream>
#include "Date.h"
using namespace std;



class Period
{
public:
    Date _start;
    Date _end;
    bool IsNotOverlapPeriod(Period period1, Period period2)
    {
        //! if Period1 is older than Period2
        if (Date::IsDate1BeforeDate2(period1._start, period2._start))
            return Date::IsDate1BeforeDate2(period1._end, period2._start) ? true : false;

        //! if Period1 is newer than Period2
        else if (Date::IsDate1BeforeDate2(period2._start, period1._start))
            return Date::IsDate1BeforeDate2(period2._end, period1._start) ? true : false;

        //! if none of the above, then the Period1 is equal to Period2
        return true;
    }
};