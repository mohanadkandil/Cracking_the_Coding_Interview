#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool checkPermutation(string str1, string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // if the lenghh of both strings are not the same, then
    // they cannpt be anagram
    if (n1 != n2)
        return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

bool checkPermutation_2(string str1, string str2)
{

    if (str1.length() != str2.length())
        return false;

    int count[256];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < str1.length(); i++)
    {
        int value = str1[i];
        count[value]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        int value = str2[i];
        count[value]--;
        if (count[value] < 0)
            return false;
    }

    return true;
}

int main()
{
    // Test Approach 1

    cout << "Approach 1" << endl;
    string str1 = "testest";
    string str2 = "estxest";

    if (checkPermutation(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;

    str1 = "hello";
    str2 = "oellh";

    if (checkPermutation(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;

    // Test Approach 2

    cout << "Approach 2" << endl;
    str1 = "testest";
    str2 = "estxest";

    if (checkPermutation_2(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;

    str1 = "hello";
    str2 = "oellh";

    if (checkPermutation_2(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;

    return 0;
}