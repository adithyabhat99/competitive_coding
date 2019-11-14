//https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0/?ref=self
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int c_sum=a[0],max_sum=a[0];
	    for(int i=1;i<n;i++)
	    {
	        c_sum=max(c_sum+a[i],a[i]);
	        max_sum=max(max_sum,c_sum);
	    }
	    cout<<max_sum<<endl;
	}
	return 0;
}