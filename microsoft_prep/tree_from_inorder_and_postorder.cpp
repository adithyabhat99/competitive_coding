//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
Node *build(int in[],int post[],int start,int end,int &postIndex,unordered_map<int,int>&mp)
{
    if(start>end) return NULL;
    int curr=post[postIndex--];
    Node *c=new Node(curr);
    if(start==end)
        return c;
    int i=mp[curr];
    c->right=build(in,post,i+1,end,postIndex,mp);
    c->left=build(in,post,start,i-1,postIndex,mp);
    return c;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[in[i]]=i;
    int postIndex=n-1;
    return build(in,post,0,n-1,postIndex,mp);
}
