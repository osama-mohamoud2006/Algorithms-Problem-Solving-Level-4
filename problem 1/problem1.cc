#include <iostream>
using namespace std;

string numberToText(int num)
{
    if (num == 0)
        return "";
    if (num >= 1 && num <= 19)
    {
        string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thriteen", "fourteen", "fivety", "sixteen", "seventeen", "eigtheen", "ninetheen"};

        return arr[num] + " ";
    }

    if (num >= 20 && num <= 99) //(20,30,40,50,60,70,80,90)
    {
        // 33 --> 30+3 --> 30->(20-90) , 3-->(1-19)
        string arr[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        return arr[num / 10] + " " + numberToText(num % 10);
    }

    if (num >= 100 && num <= 1000)
    {
        // 125 --> 100+25
        string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        return arr[num / 100] + " hundered " + numberToText(num % 100);
    }

    if (num >= 1000 && num <= 10000)
    {
        // 2500 --> 2000+500
          string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
          return arr[num/1000]+" thousand "+numberToText(num%1000);
    }
}

int main()
{
    cout << numberToText(2545) << endl;
}