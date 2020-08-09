// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
#include <bits/stdc++.h>
using namespace std;
bool detectCapitalUse(string word)
{
    if (word.size() == 0 || word.size() == 1)
    {
        return true;
    }
    int i;
    for (i = 1; i < word.size(); i++)
    {
        bool x = isupper(word[i - 1]);
        bool y = isupper(word[i]);
        if (i == 1 && (x && !y))
        {
            continue;
        }
        if ((x && !y) || (!x && y))
        {
            break;
        }
    }
    if (i == word.size())
    {
        return true;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    cout << detectCapitalUse(s) << endl;
    return 0;
}