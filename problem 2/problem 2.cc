#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace AllStuff;
using namespace std;

bool leapOrnot(short y)
{
     return (y % 400 == 0) ? true : (y % 4 == 0) ? (y % 100 != 0) ? true : false : false;
}

int main()
{

    short y = enter_postive_number("enter y: ");

    (leapOrnot(y) == true) ? cout << "Leap!" : cout << "not leap!\n";
}