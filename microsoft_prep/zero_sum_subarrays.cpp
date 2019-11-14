//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include <bits/stdc++.h>
using namespace std;
int zeroSubs(long long int a[],int n)
{
    long long int sum=0,c=0;
    unordered_map<long long int,vector<int>> mp;
    //vector<pair<int,int>> out;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
        {
            //out.push_back(make_pair(0,i));
            c++;
        }
        if(mp.find(sum)!=mp.end())
        {
            /*vector<int> vc=mp[sum];
            for(auto it=vc.begin();it!=vc.end();it++)
            {
                out.push_back(make_pair(*it+1,i));
            }*/
            c+=mp[sum].size();
        }
        mp[sum].push_back(i);
    }
    //return out.size();
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<zeroSubs(a,n)<<endl;    
	}
	return 0;
}