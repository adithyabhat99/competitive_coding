/*struct node *splitList(struct node *head)
Given Pointer/Reference to the head of a doubly linked list, task is to Sort the given doubly linked list using Merge Sort.

You need to complete the function splitList() and merge(), which will be called by the function mergeSort().

struct node *mergeSort(struct node *head)
{
    if (!head || !head->next)
        return head;
    struct node *second = splitList(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}
The spliList() function takes a single input, the pointer reference to the head of the doubly linked list. The function return pointers reference to the head of the second list. The function splits the linked list in to two halves just like in standard merge sort. As the name suggests function merge will merge two doubly linked lists, as in standard merge sort.

Input:
There are be multiple test cases, for each test case function mergeSort() will be called separately. The only input to the function is the pointer/reference to the head of the doubly linked list.

Output:
For each test, print the sorted doubly linked list in both order i.e. in non-decreasing and non-increasing order.

Constraints:
1<=T<=100
1<=N<=105

Example:
Input:
2
8
7 3 5 2 6 4 1 8
5
9 15 0 -1 0
Ouput:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1
*/
/*
Structure of the node of the list is as
struct node
{
	int data;
	struct node *next, *prev;
};
*/
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head)
{
    if(!head) return NULL;
    node *first,*second;
    first=head;
    second=head;
    while(second->next && second->next->next){
        first=first->next;
        second=second->next->next;
    }
    node *t=first->next;
    first->next=NULL;
    return t;
}
struct node *merge(struct node *first, struct node *second)
{
    if (!first) 
        return second; 
      if (!second) 
        return first; 
    if (first->data<second->data) 
    { 
        first->next=merge(first->next,second); 
        first->next->prev=first; 
        first->prev=NULL; 
        return first; 
    } 
    else
    { 
        second->next=merge(first,second->next); 
        second->next->prev=second; 
        second->prev=NULL; 
        return second; 
    } 
}
