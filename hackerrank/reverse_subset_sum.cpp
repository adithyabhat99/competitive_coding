// Given subset sum array (of size 2^n), find orginal array of size n
// works for only unique elements in the original array
#include <bits/stdc++.h>
using namespace std;
vector<int> findOriginalArray(vector<int> subsetSum)
{
    vector<int> ans;
    unordered_map<int, bool> mp;
    unordered_map<int, bool> mp2;
    sort(subsetSum.begin(), subsetSum.end());
    for (auto x : subsetSum)
        mp2[x] = true;
    int sum = 0;
    for (int i = 1; i < subsetSum.size(); i++)
    {
        sum += subsetSum[i];
        if (mp2[sum] && !mp[subsetSum[i]])
        {
            ans.push_back(subsetSum[i]);
            mp[subsetSum[i]] = true;
        }
        else
            sum -= subsetSum[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> subsetSum;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        subsetSum.push_back(x);
    }
    vector<int> ans = findOriginalArray(subsetSum);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}