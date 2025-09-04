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

short DayOrder(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + 12 * a - 2;

    return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
}

short DayOrder(stdate date)
{
    short a = ((14 - date.m) / 12);
    short y = date.y - a;
    short m = date.m + 12 * a - 2;

    return (date.d + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
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
    // is suppose that thu is end of the week
    return (DayOrder(date) == 4) ? true : false;
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
    cout << "\n"<<dayAccordingToDayOrder(DayOrder(date)) << ", " << print_date(date) << endl;

    // 2
    (isEndOfWeek(date)) ? cout << "today is thu so it is the end of the week!" : cout << "it isn't the end of the week!\n";
    cout << endl;
}
