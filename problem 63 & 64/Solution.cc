#include <iostream>
#include <string>
#include <vector>
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
    if (dateToCheck.m > 12 || dateToCheck.m < 1)
        return false;

    if (dateToCheck.d > 31 || dateToCheck.d < 1)
        return false;

    if (dateToCheck.m == 2)
    {
        if (isLeap(dateToCheck.y))
        { // 29
            if (dateToCheck.d > 29)
                return false;
        }
        else // 28
        {
            if (dateToCheck.d > 28)
                return false;
        }
    }

    if (NumberOfDaysInMonth(dateToCheck.y, dateToCheck.m) < dateToCheck.d)
        return false;

    return true;
}



// split the string into d -- >vector , m--> vector
vector<string> SplitString(string FullDateString)
{
    vector<string> result;
    short pos = 0;
    string delmi = "/";
    string DateStructTofill;
    while ((pos = FullDateString.find(delmi)) != string::npos)
    {
        DateStructTofill = FullDateString.substr(0, pos);
        if (DateStructTofill != "")
        {
            result.push_back(DateStructTofill);
        }
        FullDateString.erase(0, pos + delmi.size());
    }
    if (FullDateString != "")
        result.push_back(FullDateString);

    return result;
}

// convert vector data into stdate
stdate StringTODate(vector<string> &DateString)
{
    stdate date;
    date.d = stoi(DateString.at(0));
    date.m = stoi(DateString.at(1));
    date.y = stoi(DateString.at(2));
    return date;
}

void printDate(stdate date)
{
    cout<<"\nDay is: "<<date.d<<endl;
    cout<<"Month is: "<<date.m<<endl;
    cout<<"Year is: "<<date.y<<endl;

}

int main()
{
    string FullDate = read_full_line("\nenter Full date in one line: ");


}