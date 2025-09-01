#include <iostream>
#include"E:\projects\my library\AllStuff.h"  
using namespace AllStuff;
using namespace std;

bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

short numberOfDaysInMonth(short y, short m = 2)
{
    if (m == 2)
        return (isLeap(y) == true) ? 29 : 28;
    else
        return 30;
}

int hoursInMonth(short y)
{
    return 24 * numberOfDaysInMonth(y);
}

int MinInMonth(short y)
{
    return 60 * hoursInMonth(y);
}

int secondsInMonth(short y)
{
    return MinInMonth(y) * 60;
}

int main()
{
    short y= enter_postive_number("enter y: ");
    short m = enter_postive_number("\nenter m: ");

    cout<<"the number of days in month is: "<<numberOfDaysInMonth(y,m)<<endl;
     cout<<"the number of hours in month is: "<<hoursInMonth(y)<<endl;
     cout<<"the number of min in month is: "<<MinInMonth(y)<<endl;
     cout<<"the number of seconds is: "<<secondsInMonth(y)<<endl;



}