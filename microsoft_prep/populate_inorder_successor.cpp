//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
void helper(node *p,node *&n)
{
    if(!p) return;
    helper(p->right,n);
    p->next=n;
    n=p;
    helper(p->left,n);
}
void populateNext(struct node* p)
{
// Your code goes here
    if(!p) return;
    node *n=NULL;
    helper(p,n);
}