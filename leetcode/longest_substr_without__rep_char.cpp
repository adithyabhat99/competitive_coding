#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> mp;
    int i=0,ans=0;
    for(int j=0;j<s.length();j++)
    {
        if(mp.find(s[j])!=mp.end())
        {
            i=max(mp[s[j]],i);
        }
        ans=max(ans,j-i+1);
        mp[s[j]]=j+1;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}