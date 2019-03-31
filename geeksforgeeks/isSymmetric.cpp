/*Given a Binary Tree of size N, your task is to complete the function isSymettric(), that check whether a binary is Symmetric or not, i.e. the binary tree is Mirror image of itself or not.
For example:
The following binary tree is symmetric:

        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3

But the following is not:

       1
     /   \
    2      2
     \      \
      3      3
Input:

The function takes a single argument as input, the root node of the binary tree. There will be T test cases and for each test case the function will be called separately. 
 

Output:
For each testcase the function should return a boolean value.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
3
1 1
1 2 L 1 2 R 0
2 1
10 20 R 10 20 L 20 30 R 5
2 2
10 20 R 10 20 L 10 20 R 10 20 L 20 30 L 100 

Output:
True
False
True

Explanation:
TestCase 1:

             0
           /   \
          1     1
         /       \
        2         2
Tree is mirror image of itself i.e. tree is symmetric

TestCase 2:

             5
          /    \
        10      20
      /    \      \
    20     20      30 
Tree is not mirror image of itself i.e. tree is not symmetric

TestCase 3:

              100
            /     \
          10       10
         /   \    /   \
       20     20 20    20
Tree is mirror image of itself i.e. tree is symmetric
*/
/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isSymmetric2(Node *n1,Node *n2){
    if(!n1 && !n2) return true;
    if(!n1 || !n2) return false;
    if(n1->key != n2->key) return false;
    return isSymmetric2(n1->left,n2->right)&&isSymmetric2(n1->right,n2->left);
}
bool isSymmetric(struct Node* root)
{
	// Code here
	if(!root) return true;
	return isSymmetric2(root->left,root->right);
}