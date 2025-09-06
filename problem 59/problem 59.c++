#include <iostream>
#include <string>
#include <ctime>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;
enum enCompareDates
{
    before = -1,
    equal = 0,
    after = 1,
    none = 2
};
struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};

struct stPeriod
{
    stdate StartDate;
    stdate EndDate;
};

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}
short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

bool isLastDayInMonth(stdate date)
{
    return (NumberOfDaysInMonth(date.y, date.m) == date.d);
}

bool isLastMonthInYear(stdate date)
{
    return (date.m == 12);
}

stdate dateAfterAddingOneDay(stdate date)
{

    if (isLastDayInMonth(date) == true)
    {
        date.d = 1; // rest day 1

        if (isLastMonthInYear(date) == true) // 1/1
        {
            date.m = 1;
            date.y = date.y + 1;
        }
        else
            date.m++;
    }
    else
    {
        date.d = date.d + 1;
    }
    return date;
}
stdate FillDate()
{

    stdate d;
    static short c = 1;
    cout << "\ndate" << c << endl;
    d.d = enter_postive_number("enter d: ");
    d.m = enter_postive_number("\nenter m: ");
    d.y = enter_postive_number("\nenter y: ");
    c++;

    return d;
}

bool isDate1EqualsDate2(stdate date1, stdate date2)
{
    return ((date1.y == date2.y) && (date1.m == date2.m) && (date1.d == date2.d));
}

stPeriod FillPeriod()
{
    stPeriod period;
    period.StartDate = FillDate();
    period.EndDate = FillDate();
    return period;
}

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
                                                                                                             : false
                                                           : false;
}

bool isDate1AfterDate2(stdate date1, stdate date2)
{
    return (!isDate1LessThanDate2(date1, date2) && !isDate1EqualsDate2(date1, date2));
}

enCompareDates CompareDates(stdate date1, stdate date2)
{
    if (isDate1LessThanDate2(date1, date2))
        return enCompareDates::before;

    if (isDate1EqualsDate2(date1, date2))
        return enCompareDates::equal;

    return enCompareDates::after; // if it isn't before or equal then it is after
}

// bool isIntersectedPeriods(stPeriod p1, stPeriod p2)
// {
//     if(CompareDates(p2.EndDate,p1.StartDate)==before || CompareDates(p1.EndDate,p2.StartDate) ==before ) return false;
//     else return true;
// }

short diifBetween2dates(stdate date, stdate date2, bool EndDay = false)
{
    short days = 0;
    while (CompareDates(date, date2) == enCompareDates::before)
    {
        days++;
        date = dateAfterAddingOneDay(date);
    }
     return (EndDay) ? days += 1 : days;
}


short PeriodLength(stPeriod p1, bool EndDay = false)
{
    // short days = 0;
    // while (CompareDates(p1.StartDate, p1.EndDate) == before)
    // {
    //     days++;
    //     p1.StartDate = dateAfterAddingOneDay(p1.StartDate);
    // }
    // return (EndDay) ? days += 1 : days;

    return diifBetween2dates(p1.StartDate,p1.EndDate,EndDay);
}

int main()
{
    stPeriod p1 = FillPeriod();
    cout << "period length is: " << PeriodLength(p1, true) << endl;
}