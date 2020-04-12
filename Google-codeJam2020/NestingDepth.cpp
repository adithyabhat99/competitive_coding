#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        string s,res;
        cin>>s;
        int depth=0;
        for(int i=0;i<s.length();i++)
        {
            int n=(int)s[i]-'0';
            if(n==depth)
            {
                res+=s[i];
            }
            else if(n<depth)
            {
                for(int j=0;j<depth-n;j++)
                    res+=')';
                res+=s[i];
                depth=n;
            }
            else
            {
                for(int j=0;j<n-depth;j++)
                    res+='(';
                res+=s[i];
                depth=n;
            }
        }
        for(int i=0;i<depth;i++)
            res+=')';
        cout<<"Case #"<<x<<": "<<res<<endl;
    }
    return 0;
}