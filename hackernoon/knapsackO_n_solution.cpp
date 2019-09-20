// Solution to knapsack problem using Dynamic Programming.
// Only using O(2*capacity) extra space!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c;
    cin >> n;
    cin >> c;
    int weight[n], profit[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    int a[c + 1];
    int b[c + 1];
    memset(a, 0, (c + 1) * sizeof(a[0]));
    int *prev = a, *curr = b;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0)
                continue;
            if (weight[i - 1] > j)
                curr[j] = prev[j];
            else
                curr[j] = max(prev[j], profit[i - 1] + prev[j - weight[i - 1]]);
        }
        if (i != 0)
            swap(prev, curr);
    }
    cout << prev[c] << endl;
    return 0;
}