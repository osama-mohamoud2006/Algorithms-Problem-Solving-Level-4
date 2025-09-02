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

short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

short thePassedDays(stdate date)
{
    short totalDaysMonths = 0;

    for (int i = 1; i <= date.m - 1; i++)
    {
        totalDaysMonths += NumberOfDaysInMonth(date.y, i);
    }
    return totalDaysMonths + date.d;
}

// check if date 2 is bigger than date 1
bool isDate1lLessthanDate2(stdate date1, stdate date2)
{
    return (thePassedDays(date1) < thePassedDays(date2));
}

short diffBetween2days(stdate date1, stdate date2, bool endDay =false)
{
    short diff = 0;
    if (isDate1lLessthanDate2(date1, date2) == true)
    {
        diff = thePassedDays(date2) - thePassedDays(date1);
        if (endDay == true)
        {
            diff+=1;
        }
    }
    else
    {
        cout << "date 1 should less than date2" << endl;
        return 0;
    }

    return diff;
}

int main()
{
    stdate date1 = FillDate();
    stdate date2 = FillDate();

    cout<<"difference is: "<<diffBetween2days(date1,date2)<<" day"<<endl;
     cout<<"difference is(including end day): "<<diffBetween2days(date1,date2,true)<<" day"<<endl;

}