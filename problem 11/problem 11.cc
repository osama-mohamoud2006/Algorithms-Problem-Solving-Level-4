#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

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

short DayUntillDate(short y, short m, short d)
{
    short totalDays = 0;

    for (short i = 1; i <= m - 1; i++)
    {
        totalDays += NumberOfDaysInMonth(y, i);
    }
    return totalDays + d;
}

struct date
{
    short y;
    short m;
    short d;
};

date ReturnDate(short NOdayUntillDate, short y)
{
    // NOdayUntillDate is the number of days from 1/1 untill your day
    date data;
    data.y = y; // the year

    short RemainingDays = NOdayUntillDate; // will increment it to get the no.of days
    short m = 1;
    while (true)
    {
        short monthDays = NumberOfDaysInMonth(y, m); // the num of days in month

        if (RemainingDays > monthDays)
        {
            RemainingDays -= monthDays;
            m++;
        }
        else
        {
            data.m = m;
            data.d = RemainingDays;
            break;
        }
    }
    return data ; 
}

int main()
{
    short d = enter_postive_number("\nenter d: ");
    short m = enter_postive_number("\nenter m: ");
    short y = enter_postive_number("\nenter y: ");
    cout << "\nNumber of days from begining of the year is: " << DayUntillDate(y, m, d) << endl;

    date data ; 
    data = ReturnDate(DayUntillDate(y, m, d),y);
       cout << data.d << "/" << data.m << "/" << data.y << endl;

}