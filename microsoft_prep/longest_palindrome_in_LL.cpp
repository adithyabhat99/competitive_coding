//https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1/?ref=self
int countpals(Node *a,Node *b)
{
    int c=0;
    for(;a&&b;a=a->next,b=b->next)
    {
        if(a->data==b->data)
            c++;
        else
            break;
    }
    return c;
}
int maxPalindrome(Node *head)
{
    //Your code here
    Node *prev=NULL;
    int res=0;
    while(head)
    {
        Node *n=head->next;
        head->next=prev;
        res=max(res,2*countpals(prev,n)+1);
        res=max(res,2*countpals(head,n));
        prev=head;
        head=n;
    }
    return res;
}