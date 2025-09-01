#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace AllStuff;
using namespace std;

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

short numberOfDaysInMonth(short y, short m)
{
    if (m == 2)
        return (isLeap(y) == true) ? 29 : 28;

    // (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;

    short arrIs31D[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short n : arrIs31D)
    {
        if (n == m)
            return 30;
    }

    return 30;
}

int hoursInMonth(short y, short m)
{
    return 24 * numberOfDaysInMonth(y, m);
}

int MinInMonth(short y, short m)
{
    return 60 * hoursInMonth(y, m);
}

int secondsInMonth(short y, short m)
{
    return MinInMonth(y, m) * 60;
}

int main()
{
    short y = enter_postive_number("enter y: ");
    short m = enter_postive_number("\nenter m: ");

    cout << "the number of days in month is: " << numberOfDaysInMonth(y, m) << endl;
    cout << "the number of hours in month is: " << hoursInMonth(y, m) << endl;
    cout << "the number of min in month is: " << MinInMonth(y, m) << endl;
    cout << "the number of seconds is: " << secondsInMonth(y, m) << endl;
}