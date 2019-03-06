/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of N Spaced 3 elements, Parent node data, child node data and position of child node( 'L'  or  'R' ).

Output:
Return the Maximum possible sum.

Constraints:
1<=T<=100
1<=N<=30

Example:
Input:
1
13
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
Output:
27
*/
//Similar to diameter of a binary tree
int sum(Node *root){
    if(!root) return 0;
    return root->data+max(sum(root->left),sum(root->right));
}
int maxPathSum(struct Node *root)
{
    int l,r,ll,rr;
    if(!root) return 0;
    l=sum(root->left);
    r=sum(root->right);
    rr=maxPathSum(root->right);
    ll=maxPathSum(root->left);
    return max(r+l+root->data,max(ll,rr));
}