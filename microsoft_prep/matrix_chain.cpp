//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include <bits/stdc++.h>
using namespace std;
int best(int *a,int **c,int i,int j)
{
    if(j<=i+1)
        return 0;
    int Min=INT_MAX;
    if(c[i][j]==0)
    {
        for(int k=i+1;k<j;k++)
        {
            int q=best(a,c,i,k)+best(a,c,k,j)+(a[i]*a[k]*a[j]);
            Min=min(Min,q);
        }
        c[i][j]=Min;
    }
    return c[i][j];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int *a=new int[n];
	    int **c=new int*[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        c[i]=new int[n];
	    }
        cout<<best(a,c,0,n-1)<<endl;
	}
	return 0;
}