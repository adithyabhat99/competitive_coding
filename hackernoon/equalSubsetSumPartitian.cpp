/*
Given a set of positive numbers,
find if we can partition it into two subsets such that
the sum of elements in both the subsets is canPartition.

Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into 
two subsets with equal sum: {1, 4} & {2, 3}

Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into 
two subsets with equal sum: {1, 3, 4} & {1, 7}

Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into 
two subsets with equal sum.
*/

/*
I have used backtracking method.This solution can be optimized
with the help of Dynamic Programming.
*/
#include <bits/stdc++.h>
using namespace std;
int asum = 0, bsum = 0;
bool canPartition(vector<int> &v, vector<int> &a, vector<int> &b, int n, int i)
{
    if (i == n || a.size() + b.size() == n)
    {
        return asum == bsum;
    }
    // You can either include v[i] in first array or in the second array.
    a.push_back(v[i]);
    asum += v[i];
    bool A = canPartition(v, a, b, n, i + 1);
    a.pop_back();
    asum -= v[i];

    b.push_back(v[i]);
    bsum += v[i];
    bool B = canPartition(v, a, b, n, i + 1);
    b.pop_back();
    bsum -= v[i];

    return A || B;
}
int main()
{
    vector<int> v;
    int n, t, i, sum;
    cin >> n;
    i = n;
    while (i--)
    {
        cin >> t;
        v.push_back(t);
    }
    vector<int> a;
    vector<int> b;
    cout << canPartition(v, a, b, n, 0) << endl;
    return 0;
}