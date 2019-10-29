//https://practice.geeksforgeeks.org/problems/painting-the-fence/0
#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	long long int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    long long int dp[n+1];
	    memset(dp,0,sizeof(dp));
	    dp[1]=k;
	    long long int same=0,diff=k;
	    for(int i=2;i<=n;i++)
	    {
	        same=diff;
	        diff=dp[i-1]*(k-1);
	        diff=diff%(1000000007);
	        dp[i]=(same+diff)%(1000000007);
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}