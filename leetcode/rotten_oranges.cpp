// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3418/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int valid = 0, res = -1;
        queue<vector<int>> q;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] > 0)
                    valid++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (!q.empty())
        {
            res++;
            int s = q.size();
            for (int k = 0; k < s; k++)
            {
                vector<int> curr = q.front();
                q.pop();
                valid--;
                for (int i = 0; i < 4; i++)
                {
                    int x = curr[0] + dir[i][0];
                    int y = curr[1] + dir[i][1];
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        return (valid == 0) ? max(0, res) : -1;
    }
};