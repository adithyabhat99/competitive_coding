//https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right,*left;
    Node(int d)
    {
        right=left=NULL;
        data=d;
    }
};
bool isPreorder(int pre[],int n)
{
    int root=INT_MIN;
    stack<int>s;
    s.push(pre[0]);
    for(int i=1;i<n;i++)
    {
        if(pre[i]<root)
            return false;
        while(!s.empty() && pre[i]>s.top())
        {
            root=s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}
void postorder(Node *root)
{
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void postOrder(int pre[],int n)
{
    stack<Node*>s;
    Node *root=new Node(pre[0]);
    Node *p;
    s.push(root);
    for(int i=1;i<n;i++)
    {
        p=NULL;
        while(!s.empty() && pre[i]>s.top()->data)
        {
            p=s.top();
            s.pop();
        }
        if(p)
        {
            p->right=new Node(pre[i]);
            s.push(p->right);
        }
        else
        {
            s.top()->left=new Node(pre[i]);
            s.push(s.top()->left);
        }
    }
    postorder(root);
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int pre[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>pre[i];
	    }
	    if(!isPreorder(pre,n))
	    {
	        cout<<"NO\n";
	        continue;
	    }
	    postOrder(pre,n);
	    cout<<endl;
	}
	return 0;
}