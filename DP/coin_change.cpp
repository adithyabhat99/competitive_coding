//https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
#include<bits/stdc++.h>
int coinChange(int a[],int m,int n)
{
    int table[n+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=a[i];j<=n;j++)
        {
            table[j]+=table[j-a[i]];
        }
    }
    return table[n];
}
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    cout<<coinChange(a,m,n)<<endl;
}