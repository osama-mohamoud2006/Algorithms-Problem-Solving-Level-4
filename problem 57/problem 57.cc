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

enCompareDates IsDate1BeforeDate2(stdate date1, stdate date2)
{
    return (isDate1LessThanDate2(date1, date2)) ? enCompareDates::before : enCompareDates::none;
}

enCompareDates IsDate1EqualsDate2(stdate date1, stdate date2)
{
    return (isDate1EqualsDate2(date1, date2)) ? enCompareDates::equal : enCompareDates::none;
}

enCompareDates IsDate1AfterDate2(stdate date1, stdate date2)
{
    return (isDate1AfterDate2(date1, date2)) ? enCompareDates::after : enCompareDates::none;
}

enCompareDates CompareDates(stdate date1, stdate date2)
{
    if(isDate1LessThanDate2(date1,date2))return IsDate1BeforeDate2(date1,date2);
    if(isDate1EqualsDate2(date1,date2)) return IsDate1EqualsDate2(date1,date2);
    if(isDate1AfterDate2(date1,date2)) return IsDate1AfterDate2(date1,date2);
}

int main(){
    
}
