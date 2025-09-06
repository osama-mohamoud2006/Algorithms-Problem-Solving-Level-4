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

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
                                                                                                             : false
                                                           : false;
}

bool isDate1EqualsDate2(stdate date1, stdate date2)
{
    return ((date1.y == date2.y) && (date1.m == date2.m) && (date1.d == date2.d));
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

int main()
{
    stdate date1 = FillDate();
    stdate date2 = FillDate();

    cout << "compare result is: " << CompareDates(date1, date2) << "\n\n";
}
