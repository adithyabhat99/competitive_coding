//https://www.techiedelight.com/maximum-sum-of-subsequence-with-no-adjacent-elements/
#include<iostream>
using namespace std;
int maxSubNoAdj(int a[],int n)
{
    if(n==1)
        return a[0];
    int prev_prev=a[0];
    int prev=max(a[0],a[1]),curr;
    for(int i=2;i<n;i++)
    {
        curr=max(a[i],max(prev,prev_prev+a[i]));
        prev_prev=prev;
        prev=curr;
    }
    return prev;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubNoAdj(a,n)<<endl;
    return 0;
}