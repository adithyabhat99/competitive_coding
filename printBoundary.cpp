/*
Write a function to print Boundary Traversal of a binary tree. Boundary Traversal of a binary tree here means that you have to print boundary nodes of the binary tree Anti-Clockwise starting from the root.
Note: Boundary node means nodes present at boundary of leftSubtree and nodes present at rightSubtree also including leaf nodes.
For below tree, function should print 20 8 4 10 14 25 22 .
Input:
The input contains T, denoting the number of testcases. The task is to complete the method which takes one argument, root of the tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print Boundary traversal of the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
7
20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R 22 25 R

Output:
1 3 2
20 8 4 10 14 25 22 .
*/
#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    struct tree *r;
    struct tree *l;
};
typedef struct tree *node;
node getnode(int d)
{
    node n = new struct tree;
    n->data = d;
    n->r = n->l = NULL;
    return n;
}
void preorder(node root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
}
void printleft(node root)
{
    if(!root) return;
    if(root->l)
    {
        cout<<root->data<<" ";
        printleft(root->l);
    }
    else if(root->r){
        cout<<root->data<<" ";
        printleft(root->r);
    }
}
void printleaf(node root){
    if(!root) return;
    if(root->l)
    printleaf(root->l);
    if(!root->l && !root->r)
    cout<<root->data<<" ";
    if(root->r)
    printleaf(root->r);
}
vector<int> v;
void printright(node root){
    if(!root) return;
    if(root->r){
        v.push_back(root->data);
        printright(root->r);
    }
    else if(root->l)
    {
        v.push_back(root->data);
        printright(root->l);
    }
}
void printBoundary(node root)
{
     if(!root) return;
     cout<<root->data<<" ";
     printleft(root->l);
     printleaf(root->l);
     printleaf(root->r);
     printright(root->r);
     for(long long int x=v.size()-1;x>=0;x--){
         cout<<v[x]<<" ";
     }
     v.clear();
}
int main()
{
    map<int, node> m;
    int p, c, n;
    char a;
    node root = NULL;
    node parent, child;
    cin >> n;
    while (n--)
    {
        cin >> p >> c;
        getchar();
        cin >> a;
        if (m.find(p) == m.end())
        {
            parent = getnode(p);
            m[p] = parent;
            if (!root)
                root = parent;
        }
        else
            parent = m[p];
        child = getnode(c);
        if (a == 'L')
            parent->l = child;
        else
            parent->r = child;
        m[c] = child;
    }
    preorder(root);
    cout << endl;
    printBoundary(root);
    cout<<endl;
    return 0;
}