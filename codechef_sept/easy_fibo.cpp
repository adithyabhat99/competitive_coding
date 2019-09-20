#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x=(int)pow(2,floor(log2(n)));
        int X[x];
        X[0]=0,X[1]=1;
        for(int i=2;i<=x;i++)
            X[i]=X[i-1]+X[i-2];
        cout<<X[x-1]%10<<endl;
    }
    return 0;
}

// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
// 1 2 5 13 34 89 233
// 2 13 89
// 13
// 3