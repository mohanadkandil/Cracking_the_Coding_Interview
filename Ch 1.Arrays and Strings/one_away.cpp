#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isOneAway(string str, string str2)
{
    bool flag = false;
    string x, y;
    // take the bigger string in x
    x = str.length() >= str2.length() ? str : str2;
    y = str.length() < str2.length() ? str : str2;

    int len1, len2;
    len1 = x.length();
    len2 = y.length();

    if (abs(len1 - len2) > 1)
        return false;

    for (int i = 0, j = 0; i < len1 && j < len2;)
    {

        if (x[i] != y[j])
        {
            if (flag)
                return false;
            flag = true;
            if (len1 == len2)
                i++, j++;
            else
                i++;
        }
        else
            i++, j++;
    }
    return true;
}

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    isOneAway(str1, str2) ? cout << "One Edit away." << endl : cout << "Not one edit away." << endl;
    return 0;
}