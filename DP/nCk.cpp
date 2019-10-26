//https://practice.geeksforgeeks.org/problems/ncr/0
//O(n) space DP!
#include<bits/stdc++.h>
using namespace std;
unsigned long long int nCk(int n,int k)
{
    unsigned long long int C[k+1];
    memset(C,0,sizeof(C));
    C[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j>0;j--)
        {
            C[j]=(C[j]%(1000000007)+C[j-1]%(1000000007))%(1000000007);
        }
    }
    return C[k];
}
int main()
{
    int n,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<nCk(n,k)<<endl;
    }
    return 0;
}