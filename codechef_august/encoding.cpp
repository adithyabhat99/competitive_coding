// Wrong answer
#include <bits/stdc++.h>
using namespace std;
int fun(string n, int r)
{
    char prev = n[0];
    for (int i = 1; i < r; i++)
    {
        if (n[i] == prev)
            n[i] = '0';
        else
            prev = n[i];
    }
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        res = (res * 10 + (int)n[i] - '0') % r;
    }
    return res % ((int)pow(10, 9) + 7);
}
int main()
{
    int t, n, ans;
    string S;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        cin >> S;
        ans += fun(S, n);
        cin >> n;
        cin >> S;
        ans += fun(S, n);
        cout << ans << endl;
    }
    return 0;
}