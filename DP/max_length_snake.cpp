//https://www.techiedelight.com/maximum-length-snake-sequence/
#include<bits/stdc++.h>
using namespace std;
void printPath(int **a,int **L,pair<int,int>Point)
{
    vector<pair<int,int>>path;
    path.push_back(Point);
    int i=Point.first;
    int j=Point.second;
    while(L[i][j])
    {
        if(i-1>=0 && abs(a[i][j]-a[i-1][j])==1 && L[i][j]-L[i-1][j]==1)
        {
            path.push_back(make_pair(i-1,j));
            i--;
        }
        if(j-1>=0 && abs(a[i][j]-a[i][j-1])==1 && L[i][j]-L[i][j-1]==1)
        {
            path.push_back(make_pair(i,j-1));
            j--;
        }
    }
    cout<<"Path is\n";
    for(auto it=path.rbegin();it!=path.rend();it++)
    {
        cout<<a[it->first][it->second]<<" - ";
    }
    cout<<endl;
}
void mls(int n,int **a)
{
    int **L=new int*[n];
    for(int i=0;i<n;i++)
    {
        L[i]=new int[n];
    }
    pair<int,int> Point;
    int Max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            L[i][j]=0;
            if(i-1>=0 && abs(a[i][j]-a[i-1][j])==1)
            {
                L[i][j]=L[i-1][j]+1;
                if(Max<L[i][j])
                {
                    Point=make_pair(i,j);
                    Max=L[i][j];
                }
            }
            if(j-1>=0 && abs(a[i][j-1]-a[i][j])==1)
            {
                L[i][j]=L[i][j-1]+1;
                if(Max<L[i][j])
                {
                    Point=make_pair(i,j);
                    Max=L[i][j];
                }
            }
        }
    }
    cout<<"Maximum weight of snake path is "<<Max<<endl;
    printPath(a,L,Point);
}
int main()
{
    int n;
    cin>>n;
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)    
            cin>>a[i][j];
    }
    mls(n,a);
    return 0;
}