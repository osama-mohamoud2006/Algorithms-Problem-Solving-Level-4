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
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

bool IsVaildDate(stdate dateToCheck)
{
    // if(dateToCheck.m>12) return false;
    // if(dateToCheck.d>NumberOfDaysInMonth(dateToCheck.y,dateToCheck.m)) return false;

    // return (dateToCheck.m > 12 &&dateToCheck.m<1 ) ? false : (dateToCheck.d > NumberOfDaysInMonth(dateToCheck.y, dateToCheck.m) && dateToCheck.d<1 ) ? false:true;

    if (dateToCheck.m > 12 || dateToCheck.m < 1)
        return false;

    if (dateToCheck.d > 31 || dateToCheck.d<1)
        return false;

    if (dateToCheck.m == 2)
    {
        if (isLeap(dateToCheck.y))
        { // 29
            if (dateToCheck.d > 29)
                return false;
        }
        else //28 
        {
              if (dateToCheck.d > 28)
                return false;
        }
    }

    if(NumberOfDaysInMonth(dateToCheck.y,dateToCheck.m) < dateToCheck.d) return false;

    return true;
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

int main()
{
    stdate date = FillDate();
    if (IsVaildDate(date))
        cout << "Vaild date!\n";
    else
        cout << "Isn't Vaild date\n";
}