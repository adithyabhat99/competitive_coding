//https://practice.geeksforgeeks.org/problems/key-pair/0/?ref=self
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,sum;
	cin>>t;
	while(t--)
	{
	    cin>>n>>sum;
	    int a[n],x=0;;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    unordered_set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        if(sum-a[i]>=0 && s.find(sum-a[i])!=s.end())
	        {
	            cout<<"Yes\n";
	            x=1;
	            break;
	        }
	        s.insert(a[i]);
	    }
	    if(!x)
	        cout<<"No\n";
	}
	return 0;
}