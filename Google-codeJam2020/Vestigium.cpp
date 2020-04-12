#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,c,r;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        k=0,r=0,c=0;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            int done=0;
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(!done && mp.find(a[i][j])!=mp.end())
                {
                    r++;
                    done=1;
                }
                else
                {
                    mp[a[i][j]]++;
                }
            }
            k+=a[i][i];
        }
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>mp;
            int done=0;
            for(int j=0;j<n && !done;j++)
            {
                if(mp.find(a[j][i])!=mp.end())
                {
                    done=1;
                    c++;
                }
                else
                {
                    mp[a[j][i]]++;
                }
                
            }
        }
        cout<<"Case #"<<x<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}