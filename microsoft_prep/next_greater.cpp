//https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	long long int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    stack<long long int>s;
	    long long int nextGreater[n];
	    s.push(0);
	    for(int i=1;i<n;i++)
	    {
	        while(!s.empty() && a[s.top()]<a[i])
	        {
	            nextGreater[s.top()]=i;
	            s.pop();
	        }
	        s.push(i);
	    }
	    while(!s.empty())
	    {
	        nextGreater[s.top()]=-1;
	        s.pop();
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(nextGreater[i]!=-1)
	            cout<<a[nextGreater[i]]<<" ";
	        else
	            cout<<-1<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}