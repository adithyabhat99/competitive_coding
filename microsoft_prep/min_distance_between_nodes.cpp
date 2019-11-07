//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/?ref=self
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
int dis(Node *root,int data,int d)
{
    if(!root) return -1;
    if(root->data==data)
        return d;
    int l=dis(root->left,data,d+1);
    int r=dis(root->right,data,d+1);
    return max(l,r);
}
int findDist(Node* root, int a, int b)
{
    // Your code here 
    Node *anc=lca(root,a,b);
    int l=dis(anc,a,0);
    int r=dis(anc,b,0);
    return l+r;
}