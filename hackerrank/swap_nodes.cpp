// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
// I used level order traversal to solve this problem
// Passed 8 out of 10 test cases
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
vector<int> In;
void inorder(vector<vector<int>> indexes, int i)
{
    if (i == indexes.size() || i < 0)
    {
        return;
    }
    inorder(indexes, indexes[i][0] - 1);
    In.push_back(i + 1);
    inorder(indexes, indexes[i][1] - 1);
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    In.clear();
    vector<vector<int>> ans(queries.size());
    //For every query
    for (int i = 0; i < queries.size(); i++)
    {
        deque<int> q;
        int level = 1;
        q.push_back(1);
        //Level order
        while (!q.empty())
        {
            if (level % queries[i] == 0)
            {
                for (int j = 0; j < q.size(); j++)
                {
                    swap(indexes[q[j] - 1][0], indexes[q[j] - 1][1]);
                }
            }
            int s = q.size();
            for (int j = 0; j < s; j++)
            {
                if (indexes[q.front() - 1][0] != -1)
                {
                    q.push_back(indexes[q.front() - 1][0]);
                }
                if (indexes[q.front() - 1][1] != -1)
                {
                    q.push_back(indexes[q.front() - 1][1]);
                }
                q.pop_front();
            }
            level++;
        }
        inorder(indexes, 0);
        ans[i] = In;
        In.clear();
    }
    return ans;
}