//https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0
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
    return X[n][sum];
}
int main()
{
    int n,t,k;
    cin>>t;
    while(t--)
    {
        cin>>n; 
        cin>>k;
        int S[n],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>S[i];
            sum+=S[i];
        }
        int i,j;
        for(i=k,j=2;i<=sum;i*=j,j++)
        {
            if(isSum(S,n,i))
            {
                cout<<1<<endl;
                break;
            }
        }
        if(i>sum)
        {
            cout<<0<<endl;
        }
    }
    return 0;
}