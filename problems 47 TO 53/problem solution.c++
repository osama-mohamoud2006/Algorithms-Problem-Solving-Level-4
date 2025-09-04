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

string dayAccordingToDayOrder(short weekOrder)
{
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
    return days[weekOrder];
}

stdate LocalTime()
{
    stdate date;
    time_t epoch_time = time(0);
    tm *local = localtime(&epoch_time);

    date.y = local->tm_year + 1900;
    date.d = local->tm_mday;
    date.m = (local->tm_mon + 1);
    return date;
}

bool isEndOfWeek(stdate date)
{
    // i suppose that thu is end of the week
    return (DayOrder(date) == 4) ? true : false;
}

bool isItWeekEnd(stdate date)
{
    // i suppose fri is the week end
    return (DayOrder(date) == 5) ? true : false;
}

bool isBussinessDay(stdate date)
{
    // if day isn't fri then it is bussiness day
    return !isItWeekEnd(date);
}



short DaysUntillEndOfWeek(stdate date)
{
    short d = 0;
    while (!isEndOfWeek(date)) // thu
    {
        d++;
        date.d++;
    }
    return d;

    //    return 6-DayOrder(date); // 6 is thu bcz it is the end of the week
}

short DaysUntillTheEndOfMonth(stdate date)
{
    short d = 0;
    short daysOfMonth = NumberOfDaysInMonth(date.y, date.m);

    while (date.d < daysOfMonth)
    {
        d++;
        date.d++;
    }
    return d;
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


short getDiffBetween2dates(stdate date1, stdate date2)
{
    short days = 0;
    while(isDate1LessThanDate2(date1,date2)){
        days++;
        date1=dateAfterAddingOneDay(date1);
    }
    return days;
}


stdate TheDateThatIndcatingThEndOfYear(stdate date)
{
    date.m = 12;
    date.d = 31;
    return date;
}

short DayUntillEndOfYear(stdate date)
{
    stdate endOfYear = TheDateThatIndcatingThEndOfYear(date);
    //short d = 0;
    // while (isDate1LessThanDate2(date, endOfYear))
    // {
    //     d++;
    //     date = dateAfterAddingOneDay(date);
    // }
    return getDiffBetween2dates(date,endOfYear);
}

string print_date(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    // i suppose that thu is end of the week

    // 1
    stdate date = LocalTime();
    cout << "\n"
         << dayAccordingToDayOrder(DayOrder(date)) << ", " << print_date(date) << endl;
    cout << "_________________________\n";
    // 2
    (isEndOfWeek(date)) ? cout << "today is thu so it is the end of the week!" : cout << "it isn't the end of the week!\n";
    cout << endl;

    // 3
    (isItWeekEnd(date)) ? cout << "today is fri so it is the weekend!" : cout << "it isn't weekend !\n";

    // 4
    (isBussinessDay(date)) ? cout << "today is business day!" : cout << "it isn't business day !\n";

    // 5
    cout << "\n\ndays untill end of week : " << DaysUntillEndOfWeek(date) << " day(s)";
    cout << endl;

    // 6
    cout << "Days unill the end of month: " << DaysUntillTheEndOfMonth(date) << " day(s)" << endl;

    // 7
    cout << "Days untill the end of the year: " << DayUntillEndOfYear(date) << " day(s)" << endl;
}
