//https://practice.geeksforgeeks.org/problems/word-break-part-2/0/?ref=self
#include <bits/stdc++.h>
using namespace std;
bool contains(string dict[],string p,int n)
{
    for (int i = 0; i < n; i++) 
        if (dict[i].compare(p) == 0) 
            return true; 
    return false;
}
void diShit(string dict[],string str,int n,string res,int &N)
{
    for(int i=1;i<=n;i++)
    {
        string prefix=str.substr(0,i);
        if(contains(dict,prefix,N))
        {
            if(i==n)
            {
                res+=prefix;
                cout<<res<<")";
                return;
            }
            diShit(dict,str.substr(i,n-i),n-i,res+prefix+" ",N);
        }
    }
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    string str;
	    string dict[n];
	    for(int i=0;i<n;i++)
	        cin>>dict[i];
	    cin>>str;
	    diShit(dict,str,str.size(),"(",n);
	    cout<<endl;
	}
	return 0;
}