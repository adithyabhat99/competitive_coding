//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0/?ref=self
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
	    {
	        cin>>a[i];
	    }
	    long long int i=0;
	    long long int max_area=0,area;
	    stack<long long int>s;
	    while(i<n)
	    {
	        if(s.empty()||a[s.top()]<=a[i])
	        {
	            s.push(i++);
	        }
	        else
	        {
	            long long int t=s.top();
	            s.pop();
	            area=a[t]*(s.empty()?i:(i-s.top()-1));
	            max_area=max(area,max_area);
	        }
	    }
	    while(!s.empty())
	    {
	        long long int t=s.top();
            s.pop();
            area=a[t]*(s.empty()?i:(i-s.top()-1));
            max_area=max(area,max_area);
	    }
	    cout<<max_area<<endl;
	}
	return 0;
}