#include <bits/stdc++.h>
using namespace std;
// this is wrong and time complexity is more than O(n)
int find_min(int *a, int n, int k)
{
    if (k == 0)
        return 0;
    int sum = accumulate(a, a + n, 0);
    if (k > sum)
        return -1;
    int bucket[n], pairs = 0, picks = 0;
    memset(bucket, 0, sizeof(bucket));
    int i = 0;
    while (pairs < k)
    {
        if (bucket[i] / 2 == a[i])
        {
        }
        else
        {
            bucket[i]++;
            picks++;
            if (bucket[i] % 2 == 0)
                pairs++;
        }
        i = (i + 1) % n;
    }
    return (k % 2 == 0) ? picks + 1 : picks;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        cout << find_min(a, n, k) << endl;
    }
    return 0;
}