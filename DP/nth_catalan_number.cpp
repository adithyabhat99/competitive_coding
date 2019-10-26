//https://www.geeksforgeeks.org/program-nth-catalan-number/
//Dynamic programming
#include<iostream>
using namespace std;
int catalan(int n)
{
    int a[n];
    a[0]=a[1]=1;
    for(int i=2;i<n;i++)
    {
        a[i]=0;
        for(int j=0;j<i;j++)
        {
            a[i]+=a[j]*a[i-j-1];
        }
    }
    return a[n-1];
}
int main()
{
    int n;
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}