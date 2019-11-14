//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int lbs(int a[],int n)
{
    int lis[n],lds[n];
    for(int i=0;i<n;i++)
        lis[i]=lds[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j] && lds[i]<lds[j]+1)
            {
                lds[i]=lds[j]+1;
            }
        }
    }
    int m=lis[0]+lds[0]-1;
    for(int i=1;i<n;i++)
        m=max(m,lis[i]+lds[i]-1);
    return m;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<lbs(a,n)<<endl;
	}
	return 0;
}