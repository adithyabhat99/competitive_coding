// Find the maximum depth json string is going
#include<bits/stdc++.h>
using namespace std;
int fun(string json,int n)
{
    stack<int>s;
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(json[i]=='{'||json[i]=='[')
            s.push(json[i]);
        m=(m>s.size()?m:s.size());
        if(json[i]=='}'||json[i]==']')
            s.pop();
    }
    return m;
}