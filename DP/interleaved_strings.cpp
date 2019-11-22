//https://www.techiedelight.com/check-string-interleaving-two-given-strings/
#include<bits/stdc++.h>
using namespace std;
bool isInterleaved(string x,string y,string s,unordered_map<string,bool> &dp)
{
    if(!x.length() && !y.length() && !s.length())
        return true;
    if(!s.length())
        return false;
    string z=x+"|"+y+"|"+s;
    if(dp.find(z)==dp.end())
    {
        bool X=(x.length() && x[0]==s[0])&&isInterleaved(x.substr(1),y,s.substr(1),dp);
        bool Y=(y.length() && y[0]==s[0])&&isInterleaved(x,y.substr(1),s.substr(1),dp);
        dp[z]=X||Y;
    }
    return dp[z];
}
int main()
{
    string x,y,s;
    cin>>x>>y>>s;
    unordered_map<string,bool>dp;
    cout<<isInterleaved(x,y,s,dp)<<endl;
    return 0;
}