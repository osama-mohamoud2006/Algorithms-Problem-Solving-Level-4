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

bool isDate1LessThanDate2(stdate date, stdate date2)
{
    return (date.y < date2.y) ? true : (date.y == date2.y) ? (date.m < date2.m) ? true : (date.m == date2.m) ? (date.d < date2.d) ? true : false
                                                                                                             : false
                                                           : false;
}

bool isDate1EqualsDate2(stdate date1, stdate date2){
    return ((date1.y==date2.y)&&(date1.m==date2.m)&&(date1.d==date2.d));
}


bool isDate1AfterDate2(stdate date1, stdate date2)
{
    // // 1/1/2022 is after 1/1/2000
    // return (date1.y > date2.y) ? true : (date1.y == date2.y) ? (date1.m > date2.m) ? true : (date1.m == date2.m)   ? (date1.d > date2.d) ? true : false : false:false;
    return (!isDate1LessThanDate2(date1,date2)&& !isDate1EqualsDate2(date1,date2));
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
    stdate date1 = FillDate();
    stdate date2 = FillDate();

    if (isDate1AfterDate2(date1, date2))
        cout << "\nDate1 is After date2\n";
    else
        cout << "\nDate 1 isn't after date 2\n";
}
