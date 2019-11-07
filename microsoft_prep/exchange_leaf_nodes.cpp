//https://practice.geeksforgeeks.org/problems/exchange-the-leaf-nodes/1/?ref=self
void swaps(Node *root,Node *&p)
{
    if(!root) return;
    if(!root->left && !root->right)
    {
        if(p)
        {
            int x=p->data;
            p->data=root->data;
            root->data=x;
            p=NULL;
        }
        else
        {
            p=root;
        }
    }
    swaps(root->left,p);
    swaps(root->right,p);
}
void pairwiseSwap(Node *root)
{
    // code here
    Node *p=NULL;
    swaps(root,p);
}