#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace AllStuff;
using namespace std;
bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}
struct stdate
{
    short y = 0;
    short d = 0;
    short m = 0;
};

stdate fillDate()
{
    stdate date;
    date.d = enter_postive_number("\nenter d: ");
    date.m = enter_postive_number("\nenter m: ");
    date.y = enter_postive_number("\nenter y: ");
    return date;
}

short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

short daysPassedInYear(stdate date)
{
    short TotalDays = 0;
    for (short i = 1; i <= date.m - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(date.y, i);
    }
    return TotalDays + date.d; // will return the total days in year(that passed)+ the passed days from the month that user inputed
}

stdate daysPassedInYearIntoDateAgain(short daysPassed, stdate date)
{
    short RemainingDays = daysPassed;
    short m = 1;
    while (true)
    {
        short DaysInMonth = NumberOfDaysInMonth(date.y, m);
        if (RemainingDays > DaysInMonth)
        {
            RemainingDays -= DaysInMonth;
            m++;
        }
        else
        {
            date.m = m;
            date.d = RemainingDays;
            break;
        }
    }
    return date;
}

void printDate(stdate date)
{
    cout << date.d << "/" << date.m << "/" << date.y << endl;
}

int main()
{
    stdate date = fillDate();
    cout << daysPassedInYear(date) << endl; // 263 --> 20/9/2025
    date = daysPassedInYearIntoDateAgain(daysPassedInYear(date), date);
    printDate(date);
}
