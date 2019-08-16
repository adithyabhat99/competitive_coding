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
void topView(node root){
    queue<pair<node,int>> q;
    map<int,int> m;
    vector<int> o;
    int d=0,a;
    if(!root) return;
    m[d]=root->data;
    q.push(make_pair(root,d));
    while(!q.empty()){
        node curr=q.front().first;
        a=int(m[d]);
        if(find(o.begin(),o.end(),a)==o.end())
        o.push_back(a);
        d=q.front().second;
        if(m.find(d)==m.end())
        m[d]=curr->data;
        if(curr->l)
        q.push(make_pair(curr->l,d-1));
        if(curr->r)
        q.push(make_pair(curr->r,d+1));
        q.pop();
    }
    a=int(m[d]);
    if(find(o.begin(),o.end(),a)==o.end())
    o.push_back(a);
    for(auto x:o)
    cout<<x<<" ";
}
void bottomView(node root)
{
    if (!root)
        return;
    map<int, int> m;
    queue<pair<node , int>> q;
    int hd = 0;
    q.push(make_pair(root, hd));
    while (!q.empty())
    {
        node curr = q.front().first;
        hd = q.front().second;
        m[hd] = curr->data;
        if (curr->l)
            q.push(make_pair(curr->l, hd - 1));
        if (curr->r)
            q.push(make_pair(curr->r, hd + 1));
        q.pop();
    }
    for (auto x : m)
    {
        cout << x.second << " ";
    }
}
void leftView(node root)
{
    if (!root)
        return;
    queue<node> q;
    node qq;
    q.push(root);
    int n = q.size();
    cout << root->data << " ";
    while (!q.empty())
    {
        qq = q.front();
        q.pop();
        n--;
        if (qq->l)
            q.push(qq->l);
        if (qq->r)
            q.push(qq->r);
        if (!n && !q.empty())
        {
            cout << q.front()->data << " ";
            n = q.size();
        }
    }
}
void rightView(node root)
{
    queue<node> q;
    node qq;
    if (!root)
        return;
    q.push(root);
    cout << root->data << " ";
    int n = q.size();
    while (!q.empty())
    {
        qq = q.front();
        q.pop();
        n--;
        if (qq->r)
            q.push(qq->r);
        if (qq->l)
            q.push(qq->l);
        if (!n && !q.empty())
        {
            cout << q.front()->data << " ";
            n = q.size();
        }
    }
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
    leftView(root);
    cout << endl;
    rightView(root);
    cout << endl;
    bottomView(root);
    cout << endl;
    topView(root);
    cout<<endl;
    return 0;
}

/*
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. You are required to complete the function topView, which should print the top view of the given binary tree.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

Note: For the problem the printing should be level wise, i.e. starting node should be root.

Input:
The first line of the input contains a single integer T denoting the number of test cases. For each test a root node is given to the topView function. The only input to the function is the root of the binary Tree.

Output:
For each test case output in a single line, top view of the binary tree.

Constraints:
1<=T<=100
1<=N<=50

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:
1 2 3
10 20 30 40
 

Explanation:
Test case 1:

           1

        /     \

      2        3

For the above test case the top view is: 1 2 3

Test case 2:

            10

         /        \

     20          30

   /      \       /

40      60 90

TopView is: 10 20 30 40
*/

/*
Given a binary tree, print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance from root. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5, 10, 4, 14, 25.

Input:
The input contains T, deonoting the number of testcases. Each testcase contains 2 lines. The first line of each testcase contains number of nodes and second line contains data nodes. The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in bottom view of Binary Tree. Your code should not print a newline, it is added by the caller code that runs your function.

Constraints:
1 <=T<= 30
0 <= Number of nodes<= 100
0 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
40 20 60 30

Explanation:
Testcase 1:  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.


Thus nodes of binary tree will be printed as such 3 1 2.
*/

/*
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.

Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

            

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in right view of Binary Tree.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2
10 30 60

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.
*/

/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

            

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains two lines. The first line contains number of edges in binary tree. The second line contains number of edges+1 number of nodes data.

Output:
The function should print nodes in left view of Binary Tree.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function leftView().

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3
10 20 40

*/