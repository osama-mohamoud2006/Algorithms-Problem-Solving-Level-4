#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

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
    return (date.m != 12) ? false : true;
}

int main()
{

    stdate date = FillDate();
    if (isLastDayInMonth(date))
    {
        cout << "yes " << date.d << " is the last day in the month!\n";
    }
    else
    {

        cout << "NO" << endl;
    }

    (isLastMonthInYear(date))?cout<<"yes this is the last month! \n":cout<<"No this isn't the last month!\n";
}