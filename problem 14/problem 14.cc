#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

struct stdate
{
    short y = 0;
    short m = 0;
    short d = 0;
};

bool isDate1equalsDate2(stdate date, stdate date2)
{
    return ((date.y == date2.y) && (date.m == date2.m) && (date.d == date2.d));
}

stdate FillDate()
{
    static int dc = 1;
    cout << "\ndate " << dc << endl;
    stdate d;
    d.d = enter_postive_number("\nenter d: ");
    d.m = enter_postive_number("\nenter m: ");
    d.y = enter_postive_number("\nenter y: ");
    dc++;
    return d;
}

int main()
{

    (isDate1equalsDate2(FillDate(), FillDate()) == true) ? cout << "yes,date 1 is equals date2" : cout << "NO,date 1 isn't equals date2";
}
