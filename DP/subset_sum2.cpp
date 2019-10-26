//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include<iostream>
using namespace std;
bool isSum(int S[],int n,int sum)
{
    bool X[n+1][sum+1];
    for(int i=0;i<=n;i++)
        X[i][0]=true;
    for(int i=1;i<=sum;i++)
        X[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<S[i-1])
            {
                X[i][j]=X[i-1][j];
            }
            else
            {
                X[i][j]=X[i-1][j]||X[i-1][j-S[i-1]];
            }
        }
    }
    return true;
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int S[n],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>S[i];
            sum+=S[i];
        }
        if(sum%2==1)
            cout<<"NO\n";
        else if(isSum(S,n,sum/2))
            cout<<"YES"<<endl;
        else
            cout<<"NO\n";
    }
    return 0;
}