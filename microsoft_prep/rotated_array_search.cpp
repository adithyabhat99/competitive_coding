#include <iostream>
using namespace std;
int bin(int a[],int k,int l,int h)
{
    int m=(l+h)/2;
    if(l>h) return -1;
    if(a[m]==k)
        return m;
    else if(a[m]<k)
    {
        return bin(a,k,m+1,h);
    }
    else
        return bin(a,k,l,m-1);
}
int main() {
	int n,k,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cin>>k;
	    int p=0;
	    for(int i=1;i<n;i++)
	    {
	        if(a[i]<a[i-1])
	        {
	            p=i;
	            break;
	        }
	    }
        if(a[0]<=k && a[p-1]>=k)
        {
            cout<<bin(a,k,0,p-1)<<endl;
        }
        else{
            cout<<bin(a,k,p,n-1)<<endl;
        }
	}
	return 0;
}