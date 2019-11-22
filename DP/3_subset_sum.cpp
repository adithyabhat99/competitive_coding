//https://www.techiedelight.com/3-partition-problem/
#include<bits/stdc++.h>
using namespace std;
bool isSubSum(int a[],int n,unordered_map<string,bool>&mp,int x,int y,int z)
{
    if(x==0 && y==0 && z==0)
        return true;
    if(n<0)
        return false;
    string s=to_string(x)+"|"+to_string(y)+"|"+to_string(z)+"|"+to_string(n);
    if(mp.find(s)==mp.end())
    {
        bool A=false;
        if(x-a[n]>=0)
            A=isSubSum(a,n-1,mp,x-a[n],y,z);
        bool B=false;
        if(!A && y-a[n]>=0)
            B=isSubSum(a,n-1,mp,x,y-a[n],z);
        bool C=false;
        if((!A && !B) && (z-a[n]>=0))
            C=isSubSum(a,n-1,mp,x,y,z-a[n]);
        mp[s]=A||B||C;
    }
    return mp[s];
}
int main()
{
    int n,sum=0;
    cin>>n;
    unordered_map<string,bool> mp;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<((sum%3==0)&&isSubSum(a,n-1,mp,sum/3,sum/3,sum/3))<<endl;
    return 0;
}