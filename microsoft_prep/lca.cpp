//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/?ref=self
Node * lca(Node* root ,int n1 ,int n2 )
{
    //Your code here 
    if(!root) return NULL;
    Node *lnode=NULL,*rnode=NULL;
    if(root->data==n1 || root->data==n2)
        return root;
    lnode=lca(root->left,n1,n2);
    rnode=lca(root->right,n1,n2);
    if(lnode && rnode)
        return root;
    return (lnode)?lnode:rnode;
}