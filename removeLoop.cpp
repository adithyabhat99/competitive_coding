/*
Given a linked list of N nodes. The task is to remove the loop in it if present.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length N of the linked list and next line contains N data of the linked list. 

Output:
For each testcase, there should be a single line of output which prints 1, if loop has been removed, else 0.

User Task:
The task is to complete the function removeTheLoop() which has the only argument as head reference of the linked list.

Constraints:
1 <= T <= 50
1 <= N <= 300

Example(To be used only for expected output) :
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3
The linked list with nodes N = 3 is given. here x=2 which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

struct Node
{
int data;
Node* next; 
};*/

void removeTheLoop(Node *node)
{
     //Your code here
     Node *s=node,*f=node;
     if(!node) return;
     while(f && f->next){
         s=s->next;
         f=f->next->next;
         if(s==f){
             f->next->next=NULL;
             break;
         }
     }
}

//Bonus:Detect loop
int detectloop(Node *head)
{
   if(!head) return 0;
   Node *f=head,*s=head;
   while(f && f->next)
   {
       f=f->next->next;
       s=s->next;
       if(s==f)
       return 1;
   }
   return 0;
}