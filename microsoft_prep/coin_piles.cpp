//https://practice.geeksforgeeks.org/problems/coin-piles/0
/*
t variable is trying to store (at a point in time) one entire coin pile
Whereas temp is storing the no. of coins that'll be needed to remove FROM OTHER PILES if the current pile remains intact.
Hope this clarifies something.
The beauty of this question lies in trying to understand how it unfolds,
so spend some time thinking about why the solution is working. Once you get it, it'll all seem worth it..
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)   
	        cin>>a[i];
	    sort(a,a+n);
	    int temp,t=0,ans=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        temp=t;
	        for(int j=n-1;j>i;j--)
	        {
	            if(a[j]-a[i]-k>0)
	                temp+=a[j]-a[i]-k;
	        }
	        t+=a[i];
	        ans=min(ans,temp);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}