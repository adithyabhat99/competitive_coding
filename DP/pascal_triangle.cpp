//too easy
#include<iostream>
using namespace std;
int pascal(int n)
{
    int a[n][n];
    a[0][0]=1;
    cout<<1<<endl;
    for(int i=1;i<n;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
        cout<<a[i][0]<<" ";
        for(int j=1;j<i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pascal(n);
    return n;
}