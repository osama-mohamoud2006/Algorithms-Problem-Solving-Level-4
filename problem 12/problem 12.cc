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
    d.d = enter_postive_number("\nenter d: ");
    d.m = enter_postive_number("\nenter m: ");
    d.y = enter_postive_number("\nenter y: ");
    return d;
}

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

// how many days in month
short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

// the no.of passed days in year
short DayUntillDate(stdate d)
{
    short totalDays = 0;

    for (short i = 1; i <= d.m - 1; i++)
    {
        totalDays += NumberOfDaysInMonth(d.y, i);
    }
    return totalDays + d.d;
}

stdate TheYearAfterAddDays(stdate date, short d)
{
    short RemainingDays = d + DayUntillDate(date); // total days

    date.m = 1;
    while (true)
    {
        short daysInMonth = NumberOfDaysInMonth(date.y, date.m);

        if (RemainingDays > daysInMonth)
        {
            RemainingDays -= daysInMonth;
            date.m++;

            if (date.m > 12)
            {
                date.m = 1;
                date.y++; // if new year
            }
        }
        else
        {

            date.d = RemainingDays;
            break;
        }
    }
    return date;
}

short EnterDay()
{
    return enter_postive_number("\nenter d to add: ");
}

int main()
{
    stdate date = TheYearAfterAddDays(FillDate(), EnterDay());

    cout << date.d << "/" << date.m << "/" << date.y << endl;
}