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
    short arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (m == 2) ? ((isLeap(y) == true) ? 29 : 28) : arr[m];
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
    vector<string> DateString = SplitString(LineOfDate); // call split string to fill struct correctly
    stdate date;
    date.d = stoi(DateString.at(0));
    date.m = stoi(DateString.at(1));
    date.y = stoi(DateString.at(2));
    return date;
}

string FindWordInLineAndReaplceIt(string full_line, string string_to_replace, string replace_to)
{
    short pos = 0;
    // get the first occuerence of "string_to_replace" --> pos
    while ((pos = full_line.find(string_to_replace)) != string::npos)
    {
        // replace --> start pos , number of chars you want to replace , new string 
        full_line.replace(pos, string_to_replace.size(), replace_to);
        pos = full_line.find(string_to_replace);
    }
    return full_line;
}

string PrintDateFormat(stdate date, string DateForamt = "dd/mm/yyyy")
{
    // replace function takes your line and edit the desired string and return the line again with new edit
    string datePrint = "";
    datePrint = FindWordInLineAndReaplceIt(DateForamt, "dd", to_string(date.d));
    datePrint = FindWordInLineAndReaplceIt(datePrint, "mm", to_string(date.m));
    datePrint = FindWordInLineAndReaplceIt(datePrint, "yyyy", to_string(date.y));

    return datePrint;
}

int main()
{
    string FullDate = read_full_line("\nenter Full date dd/mm/yyyy: ");

    stdate date = StringTODate(FullDate);
  
     cout << PrintDateFormat(date, "Day: dd - Month: mm - Year: yyyy") << endl;

}