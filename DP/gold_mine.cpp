//https://www.geeksforgeeks.org/gold-mine-problem/
#include<iostream>
using namespace std;
int goldMine(int **a,int m,int n)
{
    for(int col=n-1;col>=0;col--)
    {
        for(int row=0;row<m;row++)
        {
            int right,right_down,right_up;
            right_up=(col==n-1||row==0)?0:a[row-1][col+1];
            right_down=(col==n-1||row==m-1)?0:a[row+1][col+1];
            right=(col==n-1)?0:a[row][col+1];
            a[row][col]=a[row][col]+max(right,max(right_down,right_up));
        }
    }
    int Max=a[0][0];
    for(int i=1;i<m;i++)
    {
        Max=max(Max,a[i][0]);
    }

    return Max;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int **a=new int*[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<goldMine(a,m,n)<<endl;
    return 0;
}