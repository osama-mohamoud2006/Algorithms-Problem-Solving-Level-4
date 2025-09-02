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
    short arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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

struct stdate { short y = 0;  short m = 0; short d = 0; };

stdate TheDateAgain(short DayUntillDate, short y) {
    stdate data;
    data.y = y;// the year

    short RemainingDays = DayUntillDate; // the function that count number of days starting from 1/1 untill your data
    short m = 1; // month
    while (true) {
        short monthDays = NumberOfDaysInMonth(y, m); // will return the number of days in month

        if (RemainingDays > monthDays) {
            RemainingDays -= monthDays; // will decrease the the remaing days untill reach the day
            m++;
        }
        else{
            data.d = RemainingDays; 
            data.m= m;
            break;
        }
    }
    return data;
}

int main()
{
    short d = enter_postive_number("\nenter d: ");
    short m = enter_postive_number("\nenter m: ");
    short y = enter_postive_number("\nenter y: ");
    cout << "\nNumber of days from begining of the year is: " << DayUntillDate(y, m, d) << endl;

    stdate date = TheDateAgain(DayUntillDate(y, m, d), y);
    cout << date.d << "/" << date.m << "/" << date.y << endl;
}