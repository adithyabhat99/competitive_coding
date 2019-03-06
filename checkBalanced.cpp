/*
Given a binary tree, find if it is height balanced or not.  A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if tree is height balanced, else false.

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 100
0 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
1
 

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   Second test case represents a tree with 4 edges and 5 nodes.
*/
int height(Node *root){
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node *root)
{
    if(!root) return true;
    int x=height(root->right)-height(root->left);
    if(x==0 || x==1|| x==-1)
    return isBalanced(root->left)&&isBalanced(root->right);
    else
    return false;
}
