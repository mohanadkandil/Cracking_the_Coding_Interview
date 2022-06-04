#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

// helper function to map every letter in different index[26]
int getCharIndex(char c)
{

    int idx = -1;

    if (c >= 'a' && c <= 'z')
        idx = c - 'a';
    else if (c >= 'A' && c <= 'Z')
        idx = c - 'A';

    return idx;
}

void countFrequency(string str, int *frequency)
{

    int idx;
    for (auto c : str)
    {

        idx = getCharIndex(c);
        if (idx != -1)
            ++frequency[idx];
    }
}

bool isPallindrome_1(string &str)
{

    int frequency[26]; // array of all Alpha
    memset(frequency, 0, sizeof(frequency));

    // check here that letter frequencies are all even or all even except one odd

    countFrequency(str, frequency);
    bool oddLetter = false; // detect if there's an old number of letters
    for (int i = 0; i < 26; ++i)
    {
        if (frequency[i] % 2 && oddLetter)
            oddLetter = false;
        else if (frequency[i] % 2 && !oddLetter)
            oddLetter = true;
    }

    return true;
}
// optimized than the first approach
bool isPallindrome_2(string &str)
{

    int frequency[26];
    memset(frequency, 0, sizeof(frequency));
    int oddCounter = 0, idx = 0;

    for (char &c : str)
    {

        idx = getCharIndex(c);
        if (idx != -1)
        {
            ++frequency[idx];
            if (frequency[idx] % 2)
                ++oddCounter;
            else
                --oddCounter;
        }
    }
    return (oddCounter <= 1);
}

int main()
{
    string str("Tact Coa");
    cout << "Original String: " << str << endl;
    cout << "Approach 1: " << isPallindrome_1(str) << endl;
    return 0;
}