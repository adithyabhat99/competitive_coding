/*
Given K sorted linked lists each of size N. The task is to merge them in such a way that after merging they will be sorted.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of linked lists and next line contains data of elements of all K linked lists, with first element as N, the length of linked list and next N elements for the same linked list.

Output:
Print the merged linked list.

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input
1
4
3 1 2 3 2 4 5 2 5 6 2 7 8 

Output:
1 2 3 4 5 5 6 7 8

Explanation 
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st      list     1 -> 2-> 3
2nd    list      4->5
3rd     list      5->6
4th     list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
*/
/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
  #include<bits/stdc++.h>
 Node *merge(Node *a,Node *b){
     if(!a && !b) return NULL;
     if(!a) return b;
     if(!b) return a;
     Node *res=NULL;
     if(a->data <= b->data){
         res=a;
         res->next=merge(a->next,b);
     }
    else{
        res=b;
        res->next=merge(a,b->next);
    }   
    return res;
 }
Node * mergeKList(Node *a[], int N)
{
       // Your code here
       int i,j;
       N--;
       while(N!=0){
           i=0;j=N;
       while(i<j){
           a[i]=merge(a[i],a[j]);
           i++;
           j--;
           if(i>=j){
               N=j;
           }
       }
       }
       return a[0];
}