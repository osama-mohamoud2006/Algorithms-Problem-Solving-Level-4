#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

// to check the feb
bool isLeap(short y)
{
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
}

// return day order starting from 0 (sun)
short DayOrder(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + 12 * a - 2;

    return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
}

// to return the string that indicating the month name
string monthName(short m)
{
    string month[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "agu", "sep", "oct", "nov", "dec"};
    return month[m - 1];
}

// return the number of days in month
short NumberOfDaysInMonth(short y, short m)
{

    if (m < 1 || 12 < m)
        return 0;
    short arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
}

// print the month
void printMonthCalnder(short m, short y)
{
    int theLastDayInMonth = NumberOfDaysInMonth(y, m); // the last day
    int currentDay = DayOrder(y, m, 1);

    cout << "\n______________" << monthName(m) << "______________" << endl;

    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < currentDay; i++)
    {
        printf("     ");
    }

    for (int d = 1; d <= theLastDayInMonth; d++)
    {
        printf("%4d ", d);
        if ((d + currentDay) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

void PrintYearcalnder(short y)
{
    for (short i = 1; i <= 12; i++)
    {
        printMonthCalnder(i,y); // print the month
        cout<<endl;
    }
    
}

int main(){
     short y = enter_postive_number("\nenter y: ");
    PrintYearcalnder(y);
}
