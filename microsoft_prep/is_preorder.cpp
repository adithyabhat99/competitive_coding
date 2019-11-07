//https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0/?ref=self
#include <bits/stdc++.h>
using namespace std;
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
	        cout<<"0\n";
	        continue;
	    }
	    else
	    {
	        cout<<"1\n";
	    }
	}
	return 0;
}