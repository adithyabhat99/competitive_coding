#include<bits/stdc++.h>
using namespace std;
int cut_rod(int n,int price[])
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int Max=INT_MIN;
        for(int j=0;j<i;j++)
        {
            Max=max(Max,price[j]+dp[i-j-1]);
        }
        dp[i]=Max;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)   
        cin>>price[i];
    cout<<cut_rod(n,price)<<endl;
    return 0;
}