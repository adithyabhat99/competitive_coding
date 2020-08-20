#include <bits/stdc++.h>
using namespace std;
// computes all the subsequence of an string
void subsequence(string str, vector<string> &st)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            st.push_back(sub_str);
            for (int k = 1; k < sub_str.length() - 1; k++)
            {
                string sb = sub_str;
                sb.erase(sb.begin() + k);
                subsequence(sb, st);
            }
        }
    }
}
int main()
{
    string n;
    int k, q;
    cin >> n >> k >> q;
    int a[q];
    for (int i = 0; i < q; i++)
        cin >> a[i];
    vector<string> subs;
    subsequence(n, subs);
    for (int i = 0; i < q; i++)
    {
        bool yes = false;
        for (int j = 0; j < subs.size(); j++)
        {
            if (atoi(subs[j].c_str()) % k == a[i])
            {
                yes = true;
                break;
            }
        }
        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}