#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y & 100 != 0));
}

short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

int TotalDaysSinceTheD(short y, short m, short d)
{
    int totalDaysInMonths = 0;

    for (int i = 1; i <= m; i++)
    {
        totalDaysInMonths += NumberOfDaysInMonth(y, i); // count the total days untill the current month
    }

    int the_rest_days_in_month = NumberOfDaysInMonth(y, m) - d;

    return totalDaysInMonths - the_rest_days_in_month;
}

int main()
{
    short d = enter_postive_number("\nenter d: ");
    short m = enter_postive_number("\nenter m: ");
    short y = enter_postive_number("\nenter y: ");
    cout<<TotalDaysSinceTheD(y,m,d)<<endl;
}