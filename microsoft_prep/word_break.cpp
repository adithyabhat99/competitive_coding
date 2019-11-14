//https://practice.geeksforgeeks.org/problems/word-break/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    string str;
	    unordered_map<string,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        cin>>str;
	        mp[str]++;
	    }
	    cin>>str;
	    n=str.size();
	    vector<bool>dp(n+1,false);
	    dp[0]=true;
	    string t="",t1="";
	    for(int i=1;i<=n;i++)
	    {
	        t+=str[i-1];
	        t1="";
	        for(int j=i-1;j>=0;j--)
	        {
	            t1=str[j]+t1;
	            if(mp.find(t1)!=mp.end() && dp[j])
	            {
	                dp[i]=true;
	            }
	        }
	    }
	    if(dp[n])
	        cout<<"1\n";
	    else
	        cout<<"0\n";
	}
	return 0;
}