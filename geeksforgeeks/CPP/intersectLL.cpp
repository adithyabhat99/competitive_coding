/*
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, then your function should create a third list as 2->4->6.


Input:

You have to complete the method which takes 3 argument: the head of the first linked list , the head of second linked list and the head of the third link list which is to be created. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Complete the Function given to produce the desired list with intersectioned values.

Constraints:
1 <=T<= 100
1 <= size of linked lists <= 100
1 <= Data in linked list nodes <= 1000
 

Example:(The input/output format below should be used for Expected Output only)

Input
1                       -->  (No of test cases)
5 4                    -->  (sizes of linked lists)
1 2 3 4 6           -->  (Elements of 1st linked list) 
2 4 6 8              -->  (Elements of 2nd linked list)

Output
2 4 6                 -->  (Elements of resultant 3rd linked list 
*/

void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    if(!(*head1) || !(*head2))
    *head3=NULL;
    else{
        *head3=NULL;
        Node *a,*b,*c=NULL;
        a=*head1; b=*head2;
        while(a){
            while(b && b->val!=a->val)
            b=b->next;
            if(b && b->val==a->val)
            {
                if(!c)
                {
                   c=new Node();
                   c->val=b->val;
                   *head3=c;
                }
                else {
                if(c->val!=b->val){
                Node *m=new Node();
                m->val=b->val;
                c->next=m;
                c=m;
                }
                }
            }
            b=*head2;
            a=a->next;
    }
   
    }
}