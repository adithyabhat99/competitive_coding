#include<bits/stdc++.h>
using namespace std;
int max_divisible(int a[],int n)
{
    int dp[n];
    sort(a,a+n);
    dp[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        int Max=0;
        for(int j=i+1;j<n;j++)
            if(a[j]%a[i]==0)
                Max=max(Max,dp[j]);
        dp[i]=1+Max;
    }
    int M=dp[0];
    for(int i=0;i<n;i++)
        M=max(M,dp[i]);
    return M;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<max_divisible(a,n)<<endl;
    return 0;
}