//https://practice.geeksforgeeks.org/problems/construct-a-full-binary-tree/1
Node *until(int pre[],int preMirror[],int &preIndex,int l,int h,int s)
{
    if(preIndex>=s || l>h)
        return NULL;
    Node *root=new Node(pre[preIndex]);
    preIndex++;
    if(l==h)
        return root;
    int i;
    for(i=l;i<=h;i++)
    {
        if(pre[preIndex]==preMirror[i])
            break;
    }
    if(i<=h)
    {
        root->left=until(pre,preMirror,preIndex,i,h,s);
        root->right=until(pre,preMirror,preIndex,l+1,i-1,s);
    }
    return root;
}
Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    // Code here
    int preIndex=0;
    return until(pre,preMirror,preIndex,0,size-1,size);
}