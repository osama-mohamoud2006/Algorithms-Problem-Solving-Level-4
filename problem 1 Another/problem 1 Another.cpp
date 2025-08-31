#include <iostream>
using namespace std;

string Hunderdes(int length)
{
    string arrHunderdes[] = { "one hundered", "two hundered", "three hundered", "four hundered", "five hunded", "six hundered", "seven hundereds", "eghit huundereds", "nine hundered" };

    return arrHunderdes[length];
}

string second(int length)
{
    string arr2d[] = { "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine" };
    return arr2d[length];
}
string first(int length)
{
    string arr1d[] = { "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine" };
    return arr1d[length];
}

string number_to_text(string text)
{

    string res;
    if (text.size() == 3)
    {

        res += Hunderdes(int(text[2])) + ",";
        res += second(int(text[1])) + ",";
        res += first(int(text[0]));
    }

    return res;
}

int main()
{
    cout << number_to_text("576") << endl;
}