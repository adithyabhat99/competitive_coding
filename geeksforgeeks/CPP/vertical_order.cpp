/*
You are given a binary tree for which you have to print its vertical order traversal. your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order.
Note: Please use preorder traversal logic when completing the function.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 2 lines of input. The first line contains number of operations to insert the nodes. The second line contains the nodes and their position during the insertion.

Output Format:
For each testcase, the vertical order traversal of the tree is to be printed. The nodes' data are to be separated by spaces.

Your Task:
Your task is to just complete the verticalOrder function and you don't have to take any input or output.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000

Example:
Input:
3
3
1 2 L 1 3 R 3 5 L
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2 1 5 3
3 1 2
40 20 10 60 30

Explanation:
Testcase1:
         1
       /     \
    2         3
              /
         5
As it is evident from the above diagram that during vertical traversal 2 will come first, then 1 and  5, and then 3. So output is 2 1 5 3
Testcase2:
         1
       /     \
     3       2
As it is evident from the above diagram that during vertical traversal 3 will come first, then 1 and then 2. So output is 3 1 2
*/
multimap<int,int> a;
void travel(node root,int hd){
    if(!root) return;
    a.insert(make_pair(hd,root->data));
    travel(root->l,hd-1);
    travel(root->r,hd+1);
}
void verticalOrder(node root)
{
    if(!root) return;
    a.clear();
    travel(root,0);
    for(auto x:a)
    cout<<x.second<<" ";
}