//https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
//Dynamic programming
#include<iostream>
int bell(int n)
{
    int a[n+1][n+1];
    a[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        a[i][0]=a[i-1][i-1];
        for(int j=1;j<=i;j++)
            a[i][j]=a[i-1][j-1]+a[i][j-1];
    }
    return a[n][0];
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<bell(n)<<endl;
    return 0;
}