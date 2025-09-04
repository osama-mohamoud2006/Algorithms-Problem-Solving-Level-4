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

bool isLastMonthInYear(stdate date)
{
    return (date.m == 12);
}

bool isFirstMonthInTheYear(stdate date)
{
    return (date.m == 1); // if m=1
}

stdate DecraseOneDay(stdate date)
{
    short DaysInMonth = NumberOfDaysInMonth(date.y, date.m);

    if (isFirstMonthInTheYear(date)) // 1/1/2020 --> 31/12/2019
    {
        if (date.d == 1)
        {
            date.d = DaysInMonth; // 31
            date.y--;             // 2019
            date.m = 12;          // 12
            return date;
        }
    }
    else if (date.d == 1) // 1/4/2020 --> 31/3/2020
    {
        date.d = DaysInMonth; // 31
        date.m--;             // 3
        return date;
    }
    else
    {
        date.d--;
    }
    return date;
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    // 1
    stdate date = FillDate();
    date = DecraseOneDay(date);
    cout << "\n01-Substracting one day is: " << print_date(date) << endl;
}