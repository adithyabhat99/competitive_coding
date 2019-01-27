/*
Given a linked list of N nodes. The task is to remove duplicates from the given list (if exists).

For example if the linked list is 11->11->11->21->43->43->60, then linked list should be converted to 11->21->43->60.

Note: Try not to use extra space. Expected time complexity is O(N).

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the linked list data.

Output:
For each testcase, there will be a single line of output which contains linked list with no duplicates.

User Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input
2
4
2 2 4 5
5
2 2 2 2 2

Output
2 4 5
2

Explanation:
Testcase 1: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.
 
*/

Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node *q;
 while(root && root->next && root->data==root->next->data){
     q=root;
     root=root->next;
     free(q);
 }
 if(root && root->next){
 Node *t=root->next;
 Node *prev=root;
 while(t && t->next){
     
     if(t->data==t->next->data){
         prev->next=t->next;
         q=t;
         t=t->next;
         free(q);
         continue;
     }
     prev=t;
     t=t->next;
 }
 }
 return root;
}