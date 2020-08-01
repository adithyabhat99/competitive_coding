/*
Test case 1:(output: 0)
6
-1 1
0 2
0 2
1 1
1 1
2 1

Test case 2:(output: 2)
4
-1 1
0 4
1 3
2 4
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data, treeSum;
    vector<node *> children;
    node(int d)
    {
        data = d;
        treeSum = d;
    }
};
void minimumDifference(node *n, int &totalSum, int &diff)
{
    if (!n)
        return;
    for (int i = 0; i < n->children.size(); i++)
    {
        minimumDifference(n->children[i], totalSum, diff);
        int childTreeSum = n->children[i]->treeSum;
        int remainingSum = (totalSum - n->children[i]->treeSum);
        diff = min(diff, abs(remainingSum - childTreeSum));
    }
}
void calTreeSums(node *n)
{
    if (!n)
        return;
    for (int i = 0; i < n->children.size(); i++)
    {
        calTreeSums(n->children[i]);
        n->treeSum += n->children[i]->treeSum;
    }
}
int main()
{
    int n, p, s;
    cin >> n;
    vector<node *> nodes;
    int diff = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> s;
        node *n = new node(s);
        nodes.push_back(n);
        if (p != -1)
        {
            nodes[p]->children.push_back(n);
        }
    }
    calTreeSums(nodes[0]);
    minimumDifference(nodes[0], nodes[0]->treeSum, diff);
    cout << diff << endl;
    return 0;
}