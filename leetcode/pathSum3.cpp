// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + pathSumFromRoot(root, sum);
    }
    int pathSumFromRoot(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        return (root->val == sum) + pathSumFromRoot(root->right, sum - root->val) + pathSumFromRoot(root->left, sum - root->val);
    }
};