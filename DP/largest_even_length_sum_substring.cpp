//https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	string str;
	cin>>t;
	while(t--)
	{
	    cin>>str;
	    n=str.length();
	    int m=0;
	    for(int i=0;i<n-1;i++)
	    {
	        int l=i,r=i+1,lsum=0,rsum=0;
	        while(l>=0 && r<n)
	        {
	            lsum+=str[l]-'0';
	            rsum+=str[r]-'0';
	            if(lsum==rsum)
	                m=max(m,(r-l+1));  
	            l--,r++;
	        }
	    }
	    cout<<m<<endl;
	}
	return 0;
}