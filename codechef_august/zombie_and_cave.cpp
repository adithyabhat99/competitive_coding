// I am not the origina author of this code
#include <bits/stdc++.h>
using namespace std;

bool func(int *arr, int *z, int n)
{
    sort(arr, arr + n);
    sort(z, z + n);
    for (int i = 0; i < n; i++)
        if (arr[i] != z[i])
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    int c[100000], z[100000], arr[100000];
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> z[i];
        memset(arr, 0, sizeof(int) * (n + 1));

        for (int i = 0; i < n; i++)
        {
            arr[max(0, i - c[i])]++;
            arr[min(i + c[i], n - 1) + 1]--;
        }

        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
        }

        func(arr, z, n) ? cout << "YES\n" : cout << "NO\n";
    }
}