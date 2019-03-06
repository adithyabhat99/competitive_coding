/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(!r1 && !r2)
    return true;
    if(!r1 || !r2) return false;
    if(r1->data!=r2->data)
    return false;
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}
/*
Given  two  binary trees, your task is to find if both of them are identical or not .  

Input:
The task is to complete the method which takes 2 argument, the  roots r1 and r2  of the  Binary Trees. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if both trees are identical  else false.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0

In above example there is one  test case which represent two trees with 3 nodes and 2 edges where in first test case both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3 where as in second test case both trees are not identical .
*/