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

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y & 100 != 0));
}

int TotalDaysSinceTheD(short y, short m, short d)
{
    int totalDaysInMonths = 0;

    for (int i = 1; i <= m-1; i++)
    {
        totalDaysInMonths += NumberOfDaysInMonth(y, i); // count the total days untill the current month
    }

    // int the_rest_days_in_month = NumberOfDaysInMonth(y, m) - d;

    return totalDaysInMonths += d;
}

int main()
{
    short d = enter_postive_number("\nenter d: ");
    short m = enter_postive_number("\nenter m: ");
    short y = enter_postive_number("\nenter y: ");
    cout<<"\nNumber of days from begining of the year is: "<<TotalDaysSinceTheD(y,m,d)<<endl;

}