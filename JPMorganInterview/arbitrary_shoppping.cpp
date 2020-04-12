#include<bits/stdc++.h>
using namespace std;
void arb_helper(vector<int> &a,int n,int money,int s,int &M)
{
    if(money==0)
    {
        M=max(M,s);
        return;
    }
    if(n<0)
    {
        return;
    }
    arb_helper(a,n-1,money-a[n],s+1,M);
    arb_helper(a,n-1,money,s,M);
}
int arbitrary_shopping(vector<int> a,int n,int money)
{
    int s=0;
    int M=0;
    arb_helper(a,n-1,money,s,M);
    return M;
}
int main()
{
    int n,money;
    cin>>money>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<arbitrary_shopping(a,n,money)<<endl;
    return 0;
}