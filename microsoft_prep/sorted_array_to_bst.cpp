//https://practice.geeksforgeeks.org/problems/array-to-bst/0/?ref=self
#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
    tree(int d)
    {
        data=d;
        right=left=NULL;
    }
};
void preorder(tree *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
tree* buildTree(tree *root,int *a,int l,int h)
{
    if(l>h) return NULL;
    int r=(h+l)/2;
    root=new tree(a[r]);
    root->left=buildTree(root->left,a,l,r-1);
    root->right=buildTree(root->right,a,r+1,h);
    return root;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int *a=new int[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    tree *root=NULL;
	    root=buildTree(root,a,0,n-1);
	    preorder(root);
	    cout<<endl;
	}
	return 0;
}