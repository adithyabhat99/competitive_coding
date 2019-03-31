/*
Given a Binary Tree, find diameter of it. 
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree
Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return diameter of binary tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3
4
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */
int height(Node *root){
    if(!root)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* root)
{
   // Your code here
   int lH,rH,lD,rD;
   if(!root)
   return 0;
   lH=height(root->left);
   rH=height(root->right);
   lD=diameter(root->left);
   rD=diameter(root->right);
   return max(lH+rH+1,max(lD,rD));
   
}