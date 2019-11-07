//https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1
void BToCDLL(Node *root,Node **head)
{
    if(!root)
        return;
    static Node *prev=NULL;
    BToCDLL(root->left,head);
    if(!(*head))
    {
        (*head)=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BToCDLL(root->right,head);
}
Node *bTreeToCList(Node *root)
{
//add code here.
    Node *head=NULL;
    BToCDLL(root,&head);
    Node *last,*p=head;
    while ( p!= NULL)
    {
        last=p;
        p=p->right;
    }
    last->right=head;
    head->left=last;
    return head;
}