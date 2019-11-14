//https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
#include <bits/stdc++.h>
using namespace std;
bool isFound(int **a,int n,pair<int,int>&source,pair<int,int>&dest,bool **vis)
{
    queue<pair<int,int>>q;
    q.push(source);
    vis[source.first][source.second]=true;
    while(!q.empty())
    {
        pair<int,int> f=q.front();
        if(f==dest)
            return true;
        q.pop();
        int i=f.first,j=f.second;
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j]!=0)
        {
            vis[i-1][j]=true;
            q.push(make_pair(i-1,j));
        }
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1]!=0)
        {
            vis[i][j-1]=true;
            q.push(make_pair(i,j-1));
        }
        if(i+1<n && !vis[i+1][j] && a[i+1][j]!=0)
        {
            vis[i+1][j]=true;
            q.push(make_pair(i+1,j));
        }
        if(j+1<n && !vis[i][j+1] && a[i][j+1]!=0)
        {
            vis[i][j+1]=true;
            q.push(make_pair(i,j+1));
        }
    }
    return false;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    pair<int,int>source,dest;
	    int **a=new int*[n];
	    bool **vis=new bool*[n];
	    for(int i=0;i<n;i++)
	    {
	        a[i]=new int[n];
	        vis[i]=new bool[n];
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
                vis[i][j]=false;
	            if(a[i][j]==1) source=make_pair(i,j);
	            else if(a[i][j]==2) dest=make_pair(i,j);
	        }
	    }
	    cout<<isFound(a,n,source,dest,vis)<<endl;
	}
	return 0;
}