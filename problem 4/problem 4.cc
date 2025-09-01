#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

//   int tm_sec; // seconds of minutes from 0 to 61
//   int tm_min; // minutes of hour from 0 to 59
//   int tm_hour; // hours of day from 0 to 24
//   int tm_mday; // day of month from 1 to 31
//   int tm_mon; // month of year from 0 to 11
//   int tm_year; // year since 1900
//   int tm_wday; // days since sunday
//   int tm_yday; // days since January 1st
//   int tm_isdst; // hours of daylight savings time

bool leapYearORNot(short y)
{
    // if it divided by 400 --> leap
    // if it divided by 4 And not divided by 100 --> leap
    return ((y % 400 == 0) || (y % 4 == 0 && y & 100 != 0));
}

short numberOFDays(short y)
{
    return (leapYearORNot(y) == true) ? 366 : 365;
}

int numberOfHours(short d)
{
    return 24 * d;
}

int numberOfMin(int hour)
{
    return hour * 60;
}

int numberOfSeconds(int min)
{
    return min*60;
}

int main()
{
    short y = enter_postive_number("enter y: ");
    short numOfdays = numberOFDays(y);
    int numOfhours = numberOfHours(numOfdays);
    int numOfmin = numberOfMin(numOfhours);
    int numOfSeconds=numberOfSeconds(numOfmin);

    cout << "number of days in year (" << y << ") is " << numOfdays << endl;
    cout << "number of hours in year (" << y << ") is " << numOfhours << endl;

    cout << "number of min in year (" << y << ") is " << numOfmin << endl;
        cout << "number of seconds in year (" << y << ") is " << numOfSeconds << endl;
}