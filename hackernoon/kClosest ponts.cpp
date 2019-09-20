// Print the K closest distances to origin
// Used max heap
#include<bits/stdc++.h>
using namespace std;
int findDistance(pair<int,int> a)
{
    return a.first*a.first+a.second*a.second;
}
int main()
{
    vector<pair<int,int>> v;
    int n,a,b,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    priority_queue<int> q;
    vector<pair<int,int>> output(k);
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(i<k)
        {
            q.push(findDistance(v[i]));
        }
        else{
            int d=findDistance(v[i]);
            if(d<q.top())
            {
                q.pop();
                q.push(d);
            }
        }
        i++;
    }
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}