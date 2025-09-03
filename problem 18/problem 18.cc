#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
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

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
                                                                                                             : false
                                                           : false;
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
        date.d = 1; // rest day 1(31/3)

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

stdate CURRENTLOCALTIME()
{
    stdate date;
    time_t epoch_time = time(0);
    tm *date_now = localtime(&epoch_time);
    // d/ m/ y --> 3/9/2025
    date.d = date_now->tm_mday;
    date.m = (date_now->tm_mon) + 1;
    date.y = (date_now->tm_year) + 1900;
    return date;
}

int yourAgeInDays(stdate birthday, stdate d1)
{
    int days = 0;
    while (isDate1LessThanDate2(birthday, d1))
    {
        days++; // add days from 1/8/206 untill 3/9/2025
        birthday = dateAfterAddingOneDay(birthday);
    }
    return days;
}

int main()
{
    stdate DATETODAY = CURRENTLOCALTIME();
    stdate birthday = FillDate(); // fill your birthday

    cout<<"you lived for: "<<yourAgeInDays(birthday,DATETODAY)<< " days"<<endl;
}