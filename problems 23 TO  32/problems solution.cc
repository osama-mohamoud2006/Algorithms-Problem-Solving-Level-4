#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

// add one day
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

stdate AddXdays(short days, stdate date)
{
    for (int i = 1; i <= days; i++)
    {
        date = dateAfterAddingOneDay(date);
    }
    return date;
}

stdate AddOneWeek(stdate date)
{
    if (isLastDayInMonth(date))
    { //  30/1/2021

        date.d = 7;
        date.m++; // 7/2

        if (isLastMonthInYear(date))
        {               // 31/12 -- >> 7/1
            date.m = 1; // month
            date.d = 7; // day
        }
    }

    else if (NumberOfDaysInMonth(date.y, date.m) != 30) // 2 ,4
    {
        date.d = 6;
        date.m++;
    }
    else
    {
        if (isLastMonthInYear(date))
        {
            date.d = 6;
            date.m = 1;
            date.y++;
        }
        date.d += 7;
    }

    return date;
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    stdate date = FillDate();
    //short days = enter_postive_number("enter d to add: "); // to enter days to add

    date = dateAfterAddingOneDay(date);
    cout << "01 Adding one day is: " << print_date(date) << endl;
    //date = AddXdays(days, date);
   // cout << "02 Adding 10 days is: " << print_date(date) << endl;
    date = AddOneWeek(date);
    cout<<"03 Adding one week is: "<< print_date(date) << endl;
}