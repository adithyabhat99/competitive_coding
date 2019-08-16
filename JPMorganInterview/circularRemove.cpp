#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int i = 0;
    while (1)
    {
        i = (i + k - 1) % v.size();
        v.erase(v.begin() + i);
        if (v.size() == 1)
            break;
    }
    cout << v[0] << endl;
    return 0;
}