#include<iostream>
using namespace std;
int main()
{
    int t,n;
    long long int k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(k>n/2 && n%2==1)
            a[n/2]=0;
        k=k%(3*n);
        long long int x,y;
        for(int i=0;i<k;i++)
        {
            x=i%n;
            y=n-x-1;
            a[x]=a[x]^a[y];
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}