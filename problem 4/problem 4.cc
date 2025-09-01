#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

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

int numberOfHours(short y)
{
    return 24 * numberOFDays(y);
}

int numberOfMin(int y)
{
    return numberOfHours(y) * 60;
}

int numberOfSeconds(int y)
{
    return numberOfMin(y) * 60;
}

int main()
{
    short y = enter_postive_number("enter y: ");

    cout << "number of days in year (" << y << ") is " << numberOFDays(y) << endl;
    cout << "number of hours in year (" << y << ") is " << numberOfHours(y) << endl;

    cout << "number of min in year (" << y << ") is " << numberOfMin(y) << endl;
    cout << "number of seconds in year (" << y << ") is " << numberOfSeconds(y) << endl;
}