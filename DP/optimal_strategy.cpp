//https://www.techiedelight.com/pots-gold-game-dynamic-programming/
#include<bits/stdc++.h>
using namespace std;
int lookup[20][20];
int optimal(int coin[],int i,int j)
{
    if(i==j)
        return coin[i];
    if(i+1==j)
        return max(coin[i],coin[j]);
    if(lookup[i][j]==0)
    {
        int start=coin[i]+min(optimal(coin,i+1,j-1),optimal(coin,i+2,j));
        int end=coin[j]+min(optimal(coin,i,j-2),optimal(coin,i+1,j-1));
        lookup[i][j]=max(start,end);
    }
    return lookup[i][j];
}
int main()
{
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
        cin>>coin[i];
    cout<<optimal(coin,0,n-1)<<endl;
    return 0;
}