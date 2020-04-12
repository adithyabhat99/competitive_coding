#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n;
        int s,e;
        string ans;
        cin>>n;
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,make_pair(e,i)));
            ans+='C';
        }
        sort(v.begin(),v.end());
        int C=0,J=0,imp=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first>=C)
            {
                ans[v[i].second.second]='C';
                C=v[i].second.first;
            }
            else if(v[i].first>=J)
            {
                ans[v[i].second.second]='J';
                J=v[i].second.first;
            }
            else
            {
                imp=1;
                break;
            }
            
        }
        cout<<"Case #"<<x<<": ";
        if(imp==1)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else    
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}