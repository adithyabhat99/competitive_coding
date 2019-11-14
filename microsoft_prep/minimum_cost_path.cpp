//https://practice.geeksforgeeks.org/problems/minimum-cost-path/0/?ref=self
#include <bits/stdc++.h>
using namespace std;
struct cell
{
    int x,y,distance;
    cell(int x,int y,int dis):x(x),y(y),distance(dis){}
};
bool operator<(const cell &a,const cell &b)
{
    if(a.distance==b.distance)
    {
        if(a.x!=b.x)
            return a.x<b.x;
        if(a.y!=b.y)
            return a.y<b.y;
    }
    return a.distance<b.distance;
}
bool isInGrid(int i,int j,int n)
{
    return (i<n && i>=0 && j<n && j>=0);
}
int shortestDistance(int **a,int n)
{
    set<cell> s;
    int dis[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dis[i][j]=INT_MAX;
    s.insert(cell(0,0,0));
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    dis[0][0]=a[0][0];
    while(!s.empty())
    {
        cell k=*s.begin();
        s.erase(s.begin());
        for(int i=0;i<4;i++)
        {
            int x=k.x+dx[i];
            int y=k.y+dy[i];
            if(!isInGrid(x,y,n))
                continue;
            if(dis[x][y]>dis[k.x][k.y]+a[x][y])
            {
                if(dis[x][y]!=INT_MAX)
                {
                    s.erase(s.find(cell(x,y,dis[x][y])));
                }
                dis[x][y]=dis[k.x][k.y]+a[x][y];
                s.insert(cell(x,y,dis[x][y]));
            }
        }
    }
    return dis[n-1][n-1];
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int **a=new int*[n];
	    for(int i=0;i<n;i++)
        {
            a[i]=new int[n];
            for(int j=0;j<n;j++)
                cin>>a[i][j];    
        }
        cout<<shortestDistance(a,n)<<endl;
	}
	return 0;
}