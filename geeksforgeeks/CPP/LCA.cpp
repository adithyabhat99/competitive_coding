/*
Given a Binary Search Tree and 2 nodes value n1 and n2, your task is to find the lowest common ancestor(LCA) of the two nodes .

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input.
The first line contains N, the number of nodes of the BST.
The second line contains the values of the nodes, each separated by a space.
The third line contains the two values n1 and n2 separated by a space.

Output Format:
For each testcase, in a new line, print the LCA of n1 and n2.

Your Task:
This is a function problem. You don't have to take any input. You are required to complete the function LCA that takes node, n1, n2 as parameters and returns the node that is LCA of n1 and n2.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Node value <= 1000

Example:
Input
1
6
5 4 6 3 7 8
7 8

Output 
7

Explanation 
The BST in above test case will look like

    5
   /  \ 
  4  6
 /      \
3        7
            \ 
             8
here the LCA of 7 and 8 is 7 .
*/

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
Node *LCA(Node *root, int n1, int n2)
{
    //Your code here
    if (!root)
        return NULL;
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else
        return root;
}