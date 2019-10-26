//https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
#include<bits/stdc++.h>
using namespace std;
void printSubs(int S[],bool **X,int n,int sum,int &c)
{
    if(n==0) return;
    if(n==1 && sum!=0 && X[1][sum])
    {
        c++;
        return;
    }
    if(n==1 && sum==0)
    {
        c++;
        return;
    }
    if(X[n-1][sum])
    {
        printSubs(S,X,n-1,sum,c);
    }   
    if(sum>=S[n-1] && X[n-1][sum-S[n-1]])
    {
        printSubs(S,X,n-1,sum-S[n-1],c);
    }
}
void SubsetSum(int S[],int n,int sum)
{
    bool **X=new bool*[n+1];
    for(int i=0;i<=n;i++)
    {
        X[i]=new bool[sum+1];
        X[i][0]=true;
    }
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
    if(!X[n][sum])
    {
        cout<<0<<endl;
        return;
    }
    else
    {
        int c=0;
        printSubs(S,X,n,sum,c); 
        cout<<c<<endl;
    }
}
int main()
{
    int n,sum,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int S[n];
        for(int i=0;i<n;i++)
        {
            cin>>S[i];
        }
        cin>>sum;
        SubsetSum(S,n,sum);
    }
    return 0;
}