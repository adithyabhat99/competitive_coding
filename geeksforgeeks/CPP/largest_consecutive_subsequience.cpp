// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    set<int> s;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        s.insert(x);
	    }
	    int prev=-100,m=INT_MIN,k=1,first=1;
	    for(auto l:s)
	    {
            if(first==1)
            {
                first=0;
                prev=l;
                m=1;
            }
	        else if(prev==l-1)
	        {
	            k++;
	            m=max(k,m);
	        }
	        else
	        {
	            m=max(k,m);
	            k=1;
	        }
	        prev=l;
	    }
	    cout<<m<<endl;
	}
	return 0;
}