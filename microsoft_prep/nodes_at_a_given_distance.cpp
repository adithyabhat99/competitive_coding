//https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
//https://www.youtube.com/watch?v=nPtARJ2cYrg
void fillParent(node *root,unordered_map<node *,node*>&parent,unordered_map<node *,bool>&done)
 {
    if(!root)
        return;
    done[root]=false;
    if(root->left);
        parent[root->left]=root;
    if(root->right)
        parent[root->right]=root;
    fillParent(root->left,parent,done);
    fillParent(root->right,parent,done);
 }
 int Present(node *root,node *target,int m)
 {
    if(!root || !target)
        return -1;
    if(root==target)
        return m;
    int l=Present(root->left,target,m+1);
    int r=Present(root->right,target,m+1);
    return max(l,r);
 }
 /* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance o f root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
int printkdistanceNode(node* root, node* target , int k)
{
// Your code here
    int dis=Present(root,target,0);
    if(dis==-1)
        return -1;
    unordered_map<node *,node *>parent;
    unordered_map<node *,bool> done;
    fillParent(root,parent,done);
    queue<node *>q;
    int l=0;
    q.push(target);
    done[target]=true;
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            node *f=q.front();
            q.pop();
            if(f->left && done[f->left]==false)
            {
                q.push(f->left);
                done[f->left]=true;
            }
            if(f->right && done[f->right]==false)
            {
                q.push(f->right);
                done[f->right]=true;
            }
            node *p=(f==root)?NULL:parent[f];
            if(p && done[p]==false)
            {
                q.push(p);
                done[p]=true;
            }
        }
        if(l==k-1)
        {
            break;
        }
        l++;
    }
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        q.pop();
    }
    return dis;
}