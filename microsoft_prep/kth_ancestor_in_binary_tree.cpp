//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/?ref=self
void fillParent(Node *root,unordered_map<Node *,Node*>&parent)
 {
    if(!root)
        return;
    if(root->left);
        parent[root->left]=root;
    if(root->right)
        parent[root->right]=root;
    fillParent(root->left,parent);
    fillParent(root->right,parent);
}
Node *findNode(Node *root,int node)
{
    if(!root) return NULL;
    if(root->data==node)
        return root;
    Node *l=findNode(root->left,node);
    if(l) return l;
    Node *r=findNode(root->right,node);
    return r;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(k==0) return -1;
    unordered_map<Node*,Node*>parent;
    fillParent(root,parent);
    Node *t=findNode(root,node);
    int i=0;
    while(i<k && parent[t])
    {
        t=parent[t];
        i++;
    }
    if(i<k) return -1;
    return t->data;
}
