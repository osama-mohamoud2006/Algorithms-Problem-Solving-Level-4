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

bool isLastMonthInYear(stdate date)
{
    return (date.m == 12);
}

bool isFirstMonthInTheYear(stdate date)
{
    return (date.m == 1); // if m=1
}

stdate DecreaseOneDay(stdate &date)
{

    if (isFirstMonthInTheYear(date)) // 1/1/2020 --> 31/12/2019
    {
        if (date.d == 1)
        {
            date.y--;                                     // 2019
            date.m = 12;                                  // 12
            date.d = NumberOfDaysInMonth(date.y, date.m); // 31
            return date;
        }
    }
    else if (date.d == 1) // 1/4/2020 --> 31/3/2020
    {
        date.m--;                                     // 3
        date.d = NumberOfDaysInMonth(date.y, date.m); // 31
        return date;
    }
    else
    {
        date.d--;
    }
    return date;
}

stdate DecreaseXDays(short x, stdate date)
{
    for (short i = 1; i <= x; i++)
    {
        date = DecreaseOneDay(date);
    }
    return date;
}

stdate DecreaseOneWeek(stdate date)
{
    for (int i = 1; i <= 7; i++)
    {
        date = DecreaseOneDay(date);
    }
    return date;
}

stdate DecreaseXWeeks(short x, stdate date)
{
    for (int i = 1; i <= x; i++)
    {
        date = DecreaseOneWeek(date);
    }
    return date;
}

stdate DecreaseOneMonth(stdate date)
{
    if (isFirstMonthInTheYear(date))
    {                // 1/1/2022 --> 1/12/2021
        date.y--;    // 2021
        date.m = 12; // 12
        return date;
    }
    else
    {
        date.m--;
    }
    short DaysInMonth = NumberOfDaysInMonth(date.y, date.m);
    if (date.d > DaysInMonth)
    {
        date.d = DaysInMonth;
    }
    return date;
}

stdate DecreaseXMonth(short x, stdate date)
{
    for (short i = 1; i <= x; i++)
    {
        date = DecreaseOneMonth(date);
    }
    return date;
}

stdate DecreaseOneYear(stdate date)
{
    date.y--;
    return date;
}

stdate DecreaseXYears(short x, stdate date)
{
    for (short i = 1; i <= x; i++)
    {
        date = DecreaseOneYear(date);
    }
    return date;
}

stdate DecreaseXYears2(stdate date, short x = 10)
{
    date.y -= x;
    return date;
}

stdate DecreaseOneDecade(stdate date)
{
    date.y -= 10;
    return date;
}

stdate DecreaseXdecades(stdate date, short x = 10)
{
    for (short i = 1; i <= x; i++)
    {
        date = DecreaseOneDecade(date);
    }
    return date;
}

stdate DecreaseXdecades2(stdate date , short x=10){
    date.y-=10*x;
    return date;
}


stdaet 
string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    stdate date = FillDate();

    // 1
    date = DecreaseOneDay(date);
    cout << "\n01-Substracting one day is: " << print_date(date) << endl;

    // 2
    date = DecreaseXDays(10, date);
    cout << "\n02-Substracting 10 days is: " << print_date(date) << endl;

    // 3
    date = DecreaseOneWeek(date);
    cout << "\n03-Substracting one week is: " << print_date(date) << endl;

    // 4
    date = DecreaseXWeeks(10, date);
    cout << "\n04-Substracting 10 weeks is: " << print_date(date) << endl;

    // 5
    date = DecreaseOneMonth(date);
    cout << "\n05-Substracting one month is: " << print_date(date) << endl;

    // 6
    date = DecreaseXMonth(5, date);
    cout << "\n06-Substracting 5 months is: " << print_date(date) << endl;

    // 7
    date = DecreaseOneYear(date);
    cout << "\n07-Substracting one year is: " << print_date(date) << endl;

    // 8
    date = DecreaseXYears(10, date);
    cout << "\n08-Substracting 10 years is: " << print_date(date) << endl;

    // 9
    date = DecreaseXYears2(date);
    cout << "\n09-Substracting 10 years(faster) is: " << print_date(date) << endl;

    // 10
    date = DecreaseOneDecade(date);
    cout << "\n10-Substracting 1 decade is: " << print_date(date) << endl;

    // 11
    date = DecreaseXdecades(date);
    cout << "\n11-Substracting 10 decades is: " << print_date(date) << endl;

    //12
    date=DecreaseXdecades2(date);
    cout << "\n12-Substracting 10 decades(faster) is: " << print_date(date) << endl;

    cout << endl;
}
