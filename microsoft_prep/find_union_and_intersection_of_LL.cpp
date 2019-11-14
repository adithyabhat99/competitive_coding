//https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1
void split(node *head,node **a,node **b)
{
    node *fast,*slow;
    if(!head || !head->next)
    {
        *a=head;
        b=NULL;
        return;
    }
    slow=head;
    fast=head->next;
    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *a=head;
    *b=slow->next;
    slow->next=NULL;
}
node *merge(node *a,node *b)
{
    if(!a) return b;
    if(!b) return a;
    node *x=NULL;
    if(a->data < b->data)
    {
        x=a;
        x->next=merge(a->next,b);
    }
    else if(a->data > b->data)
    {
        x=b;
        x->next=merge(a,b->next);
    }
    return x;
}
void mergeSort(node **head)
{
    if(!(*head) || !(*head)->next)
        return;
    node *a,*b;
    node *h=*head;
    split(h,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *head=merge(a,b);
}
void reverse(node **head)
{
    if(!(*head) || !(*head)->next)
        return;
    node *prev=NULL,*N;
    while(*head)
    {
        N=(*head)->next;
        (*head)->next=prev;
        prev=*head;
        *head=N;
    }
    *head=prev;
}
struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    mergeSort(&head1);
    mergeSort(&head2);
    node *result=NULL;
    node *h1=head1,*h2=head2;
    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            push(&result,h1->data);
            h1=h1->next;
        }
        else if(h1->data > h2->data)
        {
            push(&result,h2->data);
            h2=h2->next;
        }
        else
        {
            push(&result,h1->data);
            h1=h1->next;
            h2=h2->next;
        }
    }
    while(h1)
    {
        push(&result,h1->data);
        h1=h1->next; 
    }
    while(h2)
    {
        push(&result,h2->data);
        h2=h2->next; 
    }
    reverse(&result);
    return result;
}
struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    mergeSort(&head1);
    mergeSort(&head2);
    node *result=NULL;
    node *h1=head1,*h2=head2;
    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            h1=h1->next;
        }
        else if(h1->data > h2->data)
        {
            h2=h2->next;
        }
        else
        {
            push(&result,h1->data);
            h1=h1->next;
            h2=h2->next;
        }
    }
    reverse(&result);
    return result;
}