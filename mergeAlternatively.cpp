/*
Given two linked lists, your task is to complete the function mergeList() which insert's nodes of second list into first list at alternate positions of first list.

For example:
Input:
List1- 5->7->17->13->11
List2- 12->10->2->4->6
Output:
List1- 5->12->7->10->17->2->13->4->11->6
List2- (empty)
The nodes of second list should only be inserted when there are positions available.

For example:
Input:
List1- 1->2->3
List2- 4->5->6->7->8
Output:
List1- 1->4->2->5->3->6
List2- 7->8
Input:
The function takes 2 arguments as input, the reference pointer to the head of the two linked list's(head1 & head2).
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case first print space separated vales of the first linked list, then in the next line print space separated values of the second linked list.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
9 10
6
5 4 3 2 1 6
5
99 88 77 66 55
5
55 44 33 22 11
Output:
10 6 9 1 
2 3 4 5 
55 11 66 22 77 33 88 44 99 55
*/

void mergeList(struct Node **p, struct Node **q)
{
     // Code here
     Node *x=*p,*y=*q;
     Node *t1,*t2;
     while(x && y ){
         t1=x->next;
         x->next=y;
         t2=y->next;
         y->next=t1;
         y=t2;
         x=t1;
     }
     *q=y;
    
}
