#include <iostream>
#include <string>
#include <cmath>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

string FullDate(short y, short m, short d)
{
    return (to_string(d) + "/" + to_string(m) + "/" + to_string(y));
}

short DayOrder(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + 12 * a - 2;

    return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
}

string DayName(short year, short month, short day)
{
    short dayOrder = DayOrder(year, month, day);
    switch (dayOrder)
    {
    case 0:
        return "sun";
    case 1:
        return "mon";
    case 2:
        return "tue";
    case 3:
        return "wen";
    case 4:
        return "thu";
    case 5:
        return "fri";
    case 6:
        return "sat";
    }
}

int main()
{
    short d = enter_postive_number("\nenter d: ");
    short m = enter_postive_number("\nenter m: ");
    short y = enter_postive_number("\nenter y: ");

    cout << "\ndata is: " << FullDate(y, m, d) << endl;
    cout << "day order is: " << DayOrder(y, m, d) << endl;
    cout << "dayname is: " << DayName(y, m, d) << endl;
}