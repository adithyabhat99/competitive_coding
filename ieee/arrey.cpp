#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unordered_map<int,int> mp;
    int x=0;
    while(cin>>x)
    {
        mp[x]++;
    }
    int M=INT_MIN,m=x;
    for(auto a:mp)
    {
        if(mp[m]<=mp[a.first])
        {
            M=a.second;
            m=a.first;
        }
    }
    cout<<m<<endl;
    return 0;
}