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

bool isDate1LessThanDate2(stdate date1, stdate date2)
{
    if (date1.y > date2.y)
    {
        return false;
    }
    else if (date2.y > date1.y)
        return true;

    else if (date1.y == date2.y)
    {
        if (date1.m > date2.m)
        {
            return false;
        }
        else if (date2.m > date1.m)
        {
            return true;
        }
        else // m==m
        {
            if (date1.d > date2.d)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
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
    return (date.m == 12);
}

stdate dateAfterAddingOneDay(stdate date)
{

    if (isLastDayInMonth(date) == true) // 31 or 30
    {
        date.d = 1; // rest day 1

        if (isLastMonthInYear(date) == true) // 1/1
        {
            date.m = 1;
            date.y = date.y + 1;
        }
        else
            date.m++;
    }
    else
    {
        date.d = date.d + 1;
    }
    return date;
}

int DiffBetween2Dates(stdate date1, stdate date2)
{
    int days = 0;
    while (isDate1LessThanDate2(date1, date2))
    {
        days++; // if date 1 less than date2 then add days untill reach the date 2 
        date1 = dateAfterAddingOneDay(date1);
    }
    return days;
}

int main(){
    stdate date1 = fillDate();
    stdate date2 = fillDate();
    cout<<"the diff betweem 2 dates is: "<<DiffBetween2Dates(date1,date2)<<endl;
}