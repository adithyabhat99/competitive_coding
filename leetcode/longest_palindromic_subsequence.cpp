#include <iostream>
using namespace std;
bool isPal(string s)
{
    int l = 0, h = s.length() - 1;
    while (l < h)
    {
        if (s[l] != s[h])
            return false;
        l++;
        h--;
    }
    return true;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int maxPal(string s, int M, int i, string l)
{
    if (i == s.length())
        return M;
    if (isPal(l + s[i]))
        M = max(l.length()+1, M);
    return max(maxPal(s, M, i + 1, l), maxPal(s, M, i + 1, l + s[i]));
}
int longestPalindromeSubseq(string s)
{
    return maxPal(s, 0, 0, "");
}
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s)<<endl;
    return 0;
}