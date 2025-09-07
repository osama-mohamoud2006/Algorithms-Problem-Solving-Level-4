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

// convert lineOFstring data into stdate
stdate StringTODate(string LineOfDate)
{
    vector<string> DateString = SplitString(LineOfDate); // call split to split string to fill struct correctly
    stdate date;
    date.d = stoi(DateString.at(0));
    date.m = stoi(DateString.at(1));
    date.y = stoi(DateString.at(2));
    return date;
}

void printDate(stdate date)
{
    cout << "\nDay is: " << date.d << endl;
    cout << "Month is: " << date.m << endl;
    cout << "Year is: " << date.y << endl;
    cout << endl;
}

string DateStructIntoSingleLine(stdate date)
{
    return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
}

int main()
{
    string FullDate = read_full_line("\nenter Full date dd/mm/yyyy: ");

    stdate date = StringTODate(FullDate);

    printDate(date);

    cout<<"you enterd: "<<DateStructIntoSingleLine(date)<<endl;

    cout<<endl;
}