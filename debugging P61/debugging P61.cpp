
//solution 2 ///////////////////////////////////////////////////////////

#include <cctype>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "E:\projects\my library\AllStuff.h"
using namespace std;
using namespace AllStuff;

string replace(string str, string which_string, string to_replace)
{
    // searching about the string you want to replace
    short pos = 0;

    while ((pos = str.find(which_string)) != string::npos)
    {
        //str.replace(the start pos , how many chars you want to replace , the new string you want )
        str = str.replace(pos, which_string.size(), to_replace);
        pos = str.find(which_string);// to check if there is another string to replace 
    }
    return str;
}

int main()
{
    string s = "Hi,iam osama from EGYPT ! \nHi, iam Eman from EGYPT !";
    string which_string = "EGYPT";
    string to_replace = "USA";
    cout << replace(s, which_string, to_replace) << endl;
}