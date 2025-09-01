#include <iostream>
#include "E:\projects\my library\AllStuff.h"
using namespace AllStuff;
using namespace std;

bool leapOrnot(short y)
{
    // if it divided by 400 --> leap
    // if it divided by 4 And not divided by 100 --> leap 
     return ((y % 400 == 0)|| (y%4==0 && y%100!=0) );
}

int main()
{

    short y = enter_postive_number("enter y: ");

    (leapOrnot(y) == true) ? cout << "Leap!" : cout << "not leap!\n";
}