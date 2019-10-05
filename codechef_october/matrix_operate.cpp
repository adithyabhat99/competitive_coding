#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        map<int,int>row;
        map<int,int>col;
        for(int i=0;i<q;i++)
        {
            int x,y;
            cin>>x>>y;
            row[x]++;
            col[y]++;
        }
        int rc=0,cc=0;
        for(auto i:row)
        {
            if(i.second%2==1)
                rc++;
        }
        for(auto i:col)
        {
            if(i.second%2==0)
                cc++;
        }
        int rec=row.size()-rc;
        int coc=col.size()-cc;
        cout<<(rc*cc)+(rec*coc)+(rc*(m-col.size())+coc*(n-row.size()))<<endl;
    }
    return 0;
}