// https://practice.geeksforgeeks.org/problems/maximum-node-level/1
int maxNodeLevel(Node *root)
{
    queue<Node *> q;
    int n,m=-100,l=-1,ans;
    if(!root) return 0;
    q.push(root);
    while(!q.empty())
    {
        n=q.size();
        if(n>m)
        {
            ans=l;
            m=n;
        }
        l++;
        while(n>0)
        {
            Node *t=q.front();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
            q.pop();
            n--;
        }
    }
    return l;
}