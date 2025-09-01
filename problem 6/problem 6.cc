#include <iostream>
#include"E:\projects\my library\AllStuff.h"  
using namespace std;
using namespace AllStuff;

bool isLeap(short y){
    return ((y%400==0)|| (y%4==0 && y%100!=0));
}

short NumberOfDaysInMonth(short y, short m){

    if (m<1 || 12<m) return 0; 
    return (m==2)?(isLeap(y)==true)?  29 : 28 : (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) ? 31 : 30;
}

int main(){
       short y = enter_postive_number("enter y: ");
    short m = enter_postive_number("\nenter m: ");

    cout << "the number of days in month is: " << NumberOfDaysInMonth(y, m) << endl;
}
