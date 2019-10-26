#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	char x;
	while(t--)
	{
	    cin>>n;
	    set<char> nuts,bolts;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        nuts.insert(x);
	    }
	    for(int i=0;i<n;i++)    
	    {
	        cin>>x;
	        bolts.insert(x);
	    }
	    for(auto m:nuts)
	        cout<<m<<" ";
	    cout<<endl;
	    for(auto m:bolts)
	        cout<<m<<" ";
	    cout<<endl;
	}
	return 0;
}