#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, o = 0, e = 0;
    cin >> n;
    vector<int> vo;
    vector<int> ve;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2)
        {
            vo.push_back(x);
            o++;
        }
        else
        {
            e++;
            ve.push_back(x);
        }
    }
    int s = 0;
    if ((o - e) > 1)
    {
        sort(vo.begin(), vo.end());
        if (e != 0)
        {
            int y = vo.size() - e - 1;
            for (int i = 0; i < y; i++)
                s += vo[i];
        }
        if (e == 0)
        {
            for (int i = 0; i < vo.size() - 1; i++)
                s += vo[i];
        }
    }
    else if ((e - o) > 1)
    {
        sort(ve.begin(), ve.end());
        if (o != 0)
        {
            int y = ve.size() - o - 1;
            for (int i = 0; i < y; i++)
                s += ve[i];
        }
        if (o == 0)
        {
            for (int i = 0; i < ve.size() - 1; i++)
                s += ve[i];
        }
    }
    cout << s << endl;
}