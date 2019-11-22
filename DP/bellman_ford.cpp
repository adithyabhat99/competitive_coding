//https://www.techiedelight.com/single-source-shortest-paths-bellman-ford-algorithm/
#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int source,dest,weight;
    Edge(int s,int d,int w)
    {
        source=s,dest=d,weight=w;
    }
};
void printPath(int parent[],int i)
{
    if(i<0)
        return;
    printPath(parent,parent[i]);
    cout<<i<<" ";
}
void bellman_ford(vector<Edge>&v,int E,int N,int s)
{
    int dis[N];
    for(int i=0;i<N;i++)
        dis[i]=999;
    dis[s]=0;
    int parent[N];
    memset(parent,-1,sizeof(parent));
    int k=N,S,D,W;
    while(k--)
    {
        for(int i=0;i<E;i++)
        {
            S=v[i].source,D=v[i].dest,W=v[i].dest;
            if(dis[S]+W<dis[D])
            {
                dis[D]=W+dis[S];
                parent[D]=S;
            }
        }
    }
    for(int i=0;i<E;i++)
    {
        S=v[i].source,D=v[i].dest,W=v[i].dest;
        if(dis[S]+W<dis[D])
        {
            cout<<"Contains negative weight cycle\n";
            return;
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<"Distance from source to "<<i<<" is "<<dis[i]<<endl;
        cout<<"Path is ";
        printPath(parent,i);
        cout<<endl;
    }
}
int main()
{
    int E,N,source;
    int s,d,w;
    cout<<"Enter no of edges and vertices\n";
    cin>>E>>N;
    cout<<"Enter "<<E<<" edges\n";
    vector<Edge> v;
    for(int i=0;i<E;i++)
    {
        cin>>s>>d>>w;
        v.push_back(Edge(s,d,w));
    }
    cout<<"Enter source\n";
    cin>>source;
    bellman_ford(v,E,N,source);
    return 0;
}