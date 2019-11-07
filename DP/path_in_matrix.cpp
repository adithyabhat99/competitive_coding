#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n][n];
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>a[i][j];
	    int s[n][n];
	    for(int i=0;i<n;i++)
	        s[n-1][i]=a[n-1][i];
	    for(int i=n-2;i>=0;i--)
	    {
	        for(int j=0;j<n;j++)
	        {
	            int l=(j-1>=0)?s[i+1][j-1]:0;
	            int c=s[i+1][j];
	            int r=(j+1<n)?s[i+1][j+1]:0;
	            s[i][j]=a[i][j]+max(l,max(c,r));
	        }
	    }
	    int M=0;
	    for(int i=0;i<n;i++)
	        M=max(M,s[0][i]);
	    cout<<M<<endl;
	}
	return 0;
}