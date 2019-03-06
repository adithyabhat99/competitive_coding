/*
Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. Every node is considered as a path of length 1.longest-consecutive-sequence-in-Binary-tree-example
Input:

The first line of the input contains a single integer T denoting the number of test cases. For each test a root node is given to the longestConsecutive function. The only input to the function is the root of the binary Tree.
Output:

For each test case output in a single line, find the length of the longest path of the binary tree.
If no such sequence is possible return -1.

Constraints:

1<=T<=50
1<=N<=50
Example:

Input:

2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:

2
-1

Explanation:
Test case 1:

           1

        /     \

      2        3

For the above test case the longest sequence is : 1 2 ,output is 2

Test case 2:

            10

         /        \

     20          30

   /      \       /

40        60     90

For the above test case no sequence is possible: -1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/
void lo(Node *root,int c,int data,int &M){
    if(!root) return;
    if(root->data==data)
    c++;
    else
    c=1;
    M=max(c,M);
    lo(root->left,c,root->data+1,M);
    lo(root->right,c,root->data+1,M);
}
int longestConsecutive(Node* root)
{
    //Code here
    if(!root) return 0;
    int M=0;
    lo(root,0,root->data,M);
    if(M==1) return -1;
    return M;
}