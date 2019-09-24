#include<bits/stdc++.h>
using namespace std;
int fun(int n,int i,int h)
{
    int l,r;
    if(i>=n) return h-1;
    l=fun(n,2*i+1,h+1);
    r=fun(n,2*i+2,h+1);
    return max(l,r);
}
int main()
{
    int n;
    cin>>n;
    cout<<fun(n,0,1)<<endl;
}