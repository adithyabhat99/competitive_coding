//https://www.techiedelight.com/calculate-sum-elements-sub-matrix-constant-time/
#include<iostream>
using namespace std;
int printSum(int **a,int m,int n,int p,int q,int r,int s)
{
    int sum[m][n];
    sum[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        sum[i][0]=a[i][0]+sum[i-1][0];
        sum[0][i]=a[0][i]+sum[0][i-1];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int total=sum[r][s];
    if(q-1>=0)
    {
        total-=sum[r][q-1];
    }
    if(p-1>=0)
    {
        total-=sum[p-1][s];
    }
    if(q-1>=0 && p-1>=0)
    {
        total+=sum[p-1][q-1];
    }
    return total;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int **a=new int*[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int p,q,r,s;
    cin>>p>>q>>r>>s;
    cout<<printSum(a,m,n,p,q,r,s)<<endl;
    return 0;
}