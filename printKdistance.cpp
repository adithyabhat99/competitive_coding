/*
Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).  Nodes should be printed from left to right.  If k is more that height of tree, nothing should be printed.

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and k. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes at k distance from root. Nodes should be printed from left to right.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2 0
1 2 R 1 3 L
4 2
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
40 60

There are two test casess.  First case represents a tree with 3 nodes, 2 edges and value of k as 0. Here root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes and k as 1.
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// function should print the nodes at k distance from root
void printKdistance(Node *root, int k)
{
  // Your code here
  if(!root)
    return;
  if(!k)
    cout<<root->data<<" ";
  if(k) 
    printKdistance(root->left,k-1);
  if(k)
    printKdistance(root->right,k-1);
  
}