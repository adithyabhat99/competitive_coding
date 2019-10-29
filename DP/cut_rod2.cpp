//https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int x,y,z;
	    cin>>x>>y>>z;
	    int arr[3]={x,y,z};
	    int dp[n+1];
	    dp[0]=0;
	    for(int i=1;i<=n;i++)
	    dp[i]=INT_MIN;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<3;j++)
	            if(arr[j]<=i)
	                dp[i]=max(dp[i],dp[i-arr[j]]+1);
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}