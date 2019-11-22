//https://www.techiedelight.com/maximum-subarray-problem-kadanes-algorithm/
#include<bits/stdc++.h>
using namespace std;
int kadanes(int a[],int n)
{
    int csum=0,msum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        csum=max(a[i],a[i]+csum);
        msum=max(csum,msum);
    }
    return msum;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<kadanes(a,n)<<endl;
    return 0;
}