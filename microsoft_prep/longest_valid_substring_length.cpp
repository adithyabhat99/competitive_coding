//https://practice.geeksforgeeks.org/problems/valid-substring/0/?ref=self
//https://leetcode.com/articles/longest-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int M=0,l=0,r=0;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='(')
	            l++;
	        else
	            r++;
	        if(l==r)
	        {
	            M=max(M,2*l);
	        }
	        else if(r>l)
	        {
	            l=r=0;
	        }
	    }
	    l=r=0;
	    for(int i=S.length()-1;i>=0;i--)
	    {
	        if(S[i]=='(')
	            l++;
	        else
	            r++;
	        if(l==r)
	        {
	            M=max(M,2*l);
	        }
	        else if(l>r)
	        {
	            l=r=0;
	        }
	    }
	    cout<<M<<endl;
	}
	return 0;
}