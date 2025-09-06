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

bool isIntersectedPeriods(stPeriod p1, stPeriod p2)
{

    if (CompareDates(p1.EndDate, p2.StartDate) == enCompareDates::before || CompareDates(p1.StartDate, p2.EndDate) == enCompareDates::after)
        return false;
    else
        return true;
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

