#include <bits/stdc++.h>
using namespace std;
void fun(string s)
{
    int n = s.size();
    map<char, int> m;
    char a[101];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) != m.end())
        {
            cout << "No\n";
            return;
        }
        m[s[i]] = 0;
        a[x++] = s[i];
    }
    sort(a, a + x);
    for (int i = 0; i < x - 1; i++)
    {
        if (((int)a[i + 1] - (int)a[i]) > 1)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main()
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        fun(s);
    }
}