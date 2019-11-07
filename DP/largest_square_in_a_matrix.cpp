//https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
#include <iostream>
using namespace std;

int main() {
	//code
	int t,m,n,M;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    M=0;
	    int a[m][n],s[m][n];
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            M=max(M,a[i][j]);
	        }
	    }
	    for(int i=0;i<m;i++)
	        s[i][0]=a[i][0];
	    for(int i=0;i<n;i++)
	        s[0][i]=a[0][i];
	    for(int i=1;i<m;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	            if(a[i][j])
	            {
	                s[i][j]=min(s[i-1][j],min(s[i-1][j-1],s[i][j-1]))+1;
	                M=max(M,s[i][j]);
	            }
	            else
	            {
	                s[i][j]=0;
	            }
	        }
	    }
	    cout<<M<<endl;
	}
	return 0;
}