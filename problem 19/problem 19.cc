#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
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

bool Is2DatesAreEqual(stdate date1, stdate date2)
{
    return (date1.y == date2.y && date1.m == date2.m && date1.d == date2.d);
}

short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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

bool isFirstMonthInYear(stdate date)
{
    return (date.m == 1);
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

stdate dateAfterMinusOneDay(stdate date)
{
    if (isFirstMonthInYear(date)) // 1/1/2022 --> 31/12/2021
    {
        date.m = 12;
        date.y -= 1;
        date.d = NumberOfDaysInMonth(date.y, date.m); // from 1 -->31
        return date;
    }

    if (date.d == 1) // 1/3/2022
    {
       
       
        date.m -= 1; //2
        date.d = NumberOfDaysInMonth(date.y, date.m); //  31 /2/2022
    }
    else
    {
        date.d -= 1;
    }
    return date;
}

int diffBetween2days(stdate date1, stdate date2)
{
    int days = 0;
    while (!Is2DatesAreEqual(date1, date2))
    {
        if (isDate1LessThanDate2(date1, date2) != true)
        { 
            days--;
            date1 = dateAfterMinusOneDay(date1);
           
           
        }
        else {
            days++;
            date1 = dateAfterAddingOneDay(date1);
           
        }
    }
    return days;
}

int main()
{
    stdate date1 = FillDate();
    stdate date2 = FillDate();
    cout << "diff between 2 dates: " << diffBetween2days(date1, date2) << " day" << endl;
}