#include <iostream>
#include <string>
#include <ctime>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};

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

bool isLastDayInMonth(stdate date)
{
    return (NumberOfDaysInMonth(date.y, date.m) == date.d);
}

bool isLastMonthInYear(stdate date)
{
    return (date.m == 12);
}

short DayOrder(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + 12 * a - 2;

    return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
}

short DayOrder(stdate date)
{
    return DayOrder(date.y, date.m, date.d);
}

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
        : false
        : false;
}

bool isItWeekEnd(stdate date)
{
    // i suppose fri or sat is the week end
    return (DayOrder(date) == 5 || DayOrder(date) == 6) ? true : false;
}

bool isBussinessDay(stdate date)
{
    // if day isn't fri then it is bussiness day
    return !isItWeekEnd(date);
}

stdate dateAfterAddingOneDay(stdate date)
{

    if (isLastDayInMonth(date) == true)
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



stdate WillReturnDate(short ActualbussinessDays, stdate date)
{
    short weekend = 0;
    
    // if the currnet day is weekend then add days to date (bcz it is't vaction day)
    while (isItWeekEnd(date))
    {
        date = dateAfterAddingOneDay(date); // return bussiness day 
    }

    for (int i = 1; i <= ActualbussinessDays + weekend; i++)
    {
        if(isItWeekEnd(date))weekend++;

        date = dateAfterAddingOneDay(date);
    }

    while (isItWeekEnd(date)) // make sure that we have bussiness day not vaction
    {
        date = dateAfterAddingOneDay(date); // return bussiness day 
    }

    return date;
}

stdate FillDate()
{

    stdate d;
    static short c = 1;
    cout << "\ndate" << c << endl;
    d.d = enter_postive_number("enter d: ");
    d.m = enter_postive_number("\nenter m: ");
    d.y = enter_postive_number("\nenter y: ");
    c++;

    return d;
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

string dayAccordingToDayOrder(short weekOrder)
{
    string days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return days[weekOrder];
}

int main()
{
    stdate DateFrom = FillDate();
    short vaction = enter_postive_number("enter Vaction days: ");

    cout << "will return date: " << print_date(WillReturnDate(vaction, DateFrom)) << endl;
}