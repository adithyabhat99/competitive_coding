#include<iostream>
using namespace std;
long long int friendsPairing(int n)
{
    long long int a[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
        {
            a[i]=i;
        }
        else{
            a[i]=a[i-1]+(i-1)*a[i-2];
        }
    }
    return a[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<friendsPairing(n)<<endl;
    return 0;
}