#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, i, j, k, M = 0;
    cin >> m >> k;
    int a[m][m];
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    int l, r, t, b;
    t = 0, b = k - 1;
    while (b < m)
    {
        l = 0, r = k - 1;
        while (r < m)
        {
            int sum = 0;
            for (int i = l; i <= r; i++)
                for (int j = t; j <= b; j++)
                    sum += a[i][j];
            M = max(M, sum);
            l++, r++;
        }
        t++, b++;
    }
    cout << M << endl;
    return 0;
}