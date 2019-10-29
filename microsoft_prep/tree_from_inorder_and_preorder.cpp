//https://practice.geeksforgeeks.org/problems/construct-tree-1/1/
Node *build(int in[],int pre[],int inStart,int inEnd,unordered_map<int,int>&mp,int &preIndex)
{
    if(inStart>inEnd)
        return NULL;
    int curr=pre[preIndex++];
    Node *c=new Node(curr);
    if(inStart==inEnd)
        return c;
    int inIndex=mp[curr];
    c->left=build(in,pre,inStart,inIndex-1,mp,preIndex);
    c->right=build(in,pre,inIndex+1,inEnd,mp,preIndex);
    return c;
}
Node* buildTree(int in[],int pre[], int inStart, int inEnd)
{
//add code here.
    unordered_map<int,int>mp;
    for(int i=inStart;i<=inEnd;i++)
    {
        mp[in[i]]=i;
    }
    int preINdex=0;
    return build(in,pre,inStart,inEnd,mp,preIndex);
}