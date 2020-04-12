#include <bits/stdc++.h>
using namespace std;
int kadane(int a[],int n)
{
    int max_ending_here=a[0];
    int max_so_far=a[0];
    for(int i=1;i<n;i++)
    {
        max_ending_here=max(a[i],max_ending_here+a[i]);
        max_so_far=max(max_so_far,max_ending_here);
    }
    return max_so_far;
}
//this is kadane's algorithm in circular form
int maxMoney(int a[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        a[i]=-a[i];
    }
    int negSum=kadane(a,n);
    for(int i=0;i<n;i++)
        a[i]=-a[i];
    return max(kadane(a,n),sum+negSum);
}
/* //old answer(TLE)
int maxMoney(int a[], int n)
{
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int sum=a[i];
        for(int j=(i+1)%n;j!=i;j=(j+1)%n)
        {
            m=max(m,sum);
            sum+=a[j];
        }
        m=max(m,sum);
    }
    return m;
}*/
int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxMoney(a, n) << endl;
    }
    return 0;
}