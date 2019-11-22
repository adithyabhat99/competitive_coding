//https://www.techiedelight.com/calculate-size-largest-plus-1s-binary-matrix/
#include<bits/stdc++.h>
using namespace std;
int largestPlus(int **a,int n)
{
    int left[n][n],right[n][n],bottom[n][n],up[n][n];
    memset(left,0,sizeof(left)),memset(right,0,sizeof(right)),memset(bottom,0,sizeof(bottom)),memset(up,0,sizeof(up));
    for(int i=0;i<n;i++)
    {
        up[0][i]=a[0][i];
        left[i][0]=a[i][0];
        right[i][n-1]=a[i][n-1];
        bottom[n-1][i]=a[n-1][i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i][j])
                left[i][j]=left[i-1][j]+1;
            if(a[j][i])
                up[j][i]=up[j-1][i]+1;
            if(a[n-1-j][i])
                bottom[n-1-j][i]=bottom[n-j][i]+1;
            if(a[i][n-1-j])
                right[i][n-1-j]=right[i][n-j]+1;
        }
    }
    int M=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            M=max(M,min(left[i][j],min(right[i][j],min(bottom[i][j],up[i][j]))));
    }
    return M;
}
int main()
{
    int n;
    cin>>n;
    int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<largestPlus(a,n)<<endl;
    return 0;
}