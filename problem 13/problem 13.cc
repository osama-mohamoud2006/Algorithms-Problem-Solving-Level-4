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

    for (int i = 1; i <= m - 1; i++)
    {
        totalDaysInMonths += NumberOfDaysInMonth(y, i); // count the total days untill the current month
    }

    // int the_rest_days_in_month = NumberOfDaysInMonth(y, m) - d;

    return totalDaysInMonths += d;
}

struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};

bool isDate1Longer(stdate date , stdate date2)
{
  return (TotalDaysSinceTheD(date.y,date.m,date.d) > TotalDaysSinceTheD(date2.y,date2.m,date2.d));
}

stdate FillDate()
{
    static int dc =1;
    cout<<"\ndate "<<dc<<endl;
    stdate d;
    d.d = enter_postive_number("\nenter d: ");
    d.m = enter_postive_number("\nenter m: ");
    d.y = enter_postive_number("\nenter y: ");
    dc++;
    return d;
}

int main(){

    (isDate1Longer( FillDate(),FillDate())==true)?cout<<"yes,date 1 is less than date2":cout<<"NO,date 1 is bigger than date2";
}
