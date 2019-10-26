#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int m = -1;
	    int c;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    for(int i=1;i<n;i++)
	    {
	        c=0;
	        for(int j=i-1;j>=0;j--)
	        {
	            if(a[j]%a[i]==0)
	               c++;
	        }
	        m=max(m,c);
	    }
	    cout<<m<<endl;
	}
	return 0;
}