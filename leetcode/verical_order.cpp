// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3415/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(TreeNode *r, int x, int y, map<int, map<int, set<int>>> &m)
    {
        if (r != nullptr)
        {
            m[x][y].insert(r->val);
            dfs(r->left, x - 1, y + 1, m);
            dfs(r->right, x + 1, y + 1, m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode *r, vector<vector<int>> res = {})
    {
        map<int, map<int, set<int>>> m;
        dfs(r, 0, 0, m);
        for (auto itx = m.begin(); itx != m.end(); ++itx)
        {
            res.push_back(vector<int>());
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity)
            {
                res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
            }
        }
        return res;
    }
};