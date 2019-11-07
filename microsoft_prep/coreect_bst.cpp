//https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
void correctUntil(Node *root,Node **first,Node **middle,Node **last,Node **prev)
{
    if(!root)
        return;
    correctUntil(root->left,first,middle,last,prev);
    if(*prev && root->data < (*prev)->data)
    {
        if(!(*first))
        {
            *first=*prev;
            *middle=root;
        }
        else
            *last=root;
    }
    *prev=root;
    correctUntil(root->right,first,middle,last,prev);
}
struct Node *correctBST( struct Node* root )
{
    // add code here.
    Node *first,*last,*middle,*prev;
    first=last=middle=prev=NULL;
    correctUntil(root,&first,&middle,&last,&prev);
    if(first && last)
    {
        swap(&(first->data),&(last->data));
    }
    else if(first && middle)
    {
        swap(&(first->data),&(middle->data));
    }
    return root;
}