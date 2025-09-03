#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

// add one day
struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};

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

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
                                                                                                             : false
                                                           : false;
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

stdate AddXdays(short days, stdate date)
{
    for (int i = 1; i <= days; i++)
    {
        date = dateAfterAddingOneDay(date);
    }
    return date;
}

stdate AddOneWeek(stdate date)
{
    date.d += 7;
    int dayOFmonth = NumberOfDaysInMonth(date.y, date.m);

    if (date.d > dayOFmonth)
    {
        date.m++;
        date.d -= dayOFmonth;
    }

    if (date.m > 12)
    {
        date.m = 1;
        date.y++;
    }

    return date;
}

stdate AddXWeeks(short x, stdate date)
{
    for (int i = 1; i <= x; i++)
    {
        date = AddOneWeek(date);
    }
    return date;
}

stdate AddOneMonth(stdate date)
{
    date.m++;
    if (date.m > 12)
        date.m = 1;
    return date;
}

stdate AddXMonths(short x, stdate date)
{
    for (int i = 1; i <= x; i++)
    {
        date = AddOneMonth(date);
    }
    return date;
}

stdate AddOneYear(stdate date)
{
    date.y++;
    return date;
}

stdate AddXYears(short x, stdate date)
{
    for (int i = 1; i <= x; i++)
    {
        date = AddOneYear(date);
    }
    return date;
}

stdate AddXYears2(short x, stdate date)
{
    date.y += x;
    return date;
}

stdate AddOneDecade(stdate date)
{
    date.y += 10;
    return date;
}

stdate AdddXDecade(short x, stdate date)
{
    for (int i = 1; i <= x; i++)
    {
        date = AddOneDecade(date);
    }
    return date;
}

// using recrusion
stdate AddXDecade2(short x, stdate date)
{
    static int total = 0;
    if (x != 0)
    {
        total = date.y += 10;
        return AddXDecade2(x = x - 1, date);
    }
    else
    {
        date.y = total;
        return date;
    }
}

stdate AddOneCentury(stdate date)
{
    date.y+=100;
    return date; 
}

stdate AddOneMillenuim(stdate date)
{
    date.y += 1000;
    return date;
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    stdate date = FillDate();
    short x = enter_postive_number("enter d to add: "); // to enter days to add
                                                        // 1
    date = dateAfterAddingOneDay(date);
    cout << "\n01 Adding one day is: " << print_date(date) << endl;
    // 2
    date = AddXdays(x, date);
    cout << "\n02 Adding " << x << " days is: " << print_date(date) << endl;
    // 3
    date = AddOneWeek(date);
    cout << "\n03 Adding one week is: " << print_date(date) << endl;
    // 4
    x = enter_postive_number("enter weeks to add: "); // to enter weeks to add
    date = AddXWeeks(x, date);
    cout << "\n04 Adding " << x << " weeks is: " << print_date(date) << endl;
    // 5
    date = AddOneMonth(date);
    cout << "\n05 Adding one month is : " << print_date(date) << endl;
    // 6
    x = enter_postive_number("enter month to add: "); // to enter months to add
    date = AddXMonths(x, date);
    cout << "\n06 Adding " << x << " month: " << print_date(date) << endl;

    // 7
    date = AddOneYear(date);
    cout << "\n07 Adding one year is: " << print_date(date) << endl;

    // 8
    x = enter_postive_number("enter year to add: "); // to enter months to add
    date = AddXYears(x, date);
    cout << "\n08 Adding " << x << " years is: " << print_date(date) << endl;

    // 9
    x = enter_postive_number("enter year to add: "); // to enter years to add
    date = AddXYears2(x, date);
    cout << "\n09 Adding(faster) " << x << " years is: " << print_date(date) << endl;

    // 10
    date = AddOneDecade(date);
    cout << "\n10 Adding one decade is: " << print_date(date) << endl;

    // 11
    x = enter_postive_number("enter decades to add: "); // to enter decades to add
    date = AdddXDecade(x, date);
    cout << "\n11 Adding " << x << " decades is: " << print_date(date) << endl;

    // 12
    x = enter_postive_number("enter decades to add: "); // to enter decades to add
    date = AddXDecade2(x, date);
    cout << "\n12 Adding(another method) " << x << " decades is: " << print_date(date) << endl;

    //13
    date = AddOneCentury(date);
    cout<<"\n13 Adding one century is:"<<print_date(date) << endl;

    //14 

}