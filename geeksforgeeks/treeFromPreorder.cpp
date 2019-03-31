/*
Given an array ‘pre[]’ that represents Preorder traversal of a binary tree. 
One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. 
The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node 
and value ‘N’ indicates that the corresponding node is non-leaf node.
Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5
Input Format:
The function takes three arguments as input, first an integer N, denoting the size of both the array, second an array "pre[]"  that represents Preorder traversal of the binary tree and the last argument an character array "preLN[]" which indicates that the corresponding node in Binary Tree is a leaf node or a normal node.
There will be T, test cases and for each test case the function will be called separately.

Output Format:
The output will be the inorder traversal of the resultant tree.

Constraints:
1<=T<=100
1<=N<=100

Your Task:
Your task is to complete the function constructTree(), that constructs the tree from the given two arrays and return the root pointer to new binary tree formed.

Example:
Input:
3
5
10 30 20 5 15 
N N L L L 
4
1 2 4 3 
N N L L 
6
1 2 4 6 5 3 
N N N L L L 
Output:
20 30 5 10 15 
4 2 3 1 
6 4 5 2 3 1 
*/

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node *cons(int n,int pre[],char preLN[],int &m){
    if(m>=n){
        return NULL;
    }
    Node *child=new Node;
    if(preLN[m]=='L'){
        child->data=pre[m];
        child->left=child->right=NULL;
        return child;
    }
    child->data=pre[m];
    m++;
    child->left=cons(n,pre,preLN,m);
    m++;
    child->right=cons(n,pre,preLN,m);
    return child;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int m=0;
    return cons(n,pre,preLN,m);
}