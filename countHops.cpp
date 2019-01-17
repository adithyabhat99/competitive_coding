/*
A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int f(ll a[],int n){
    int i;
    a[1]=1; a[2]=2; a[3]=4;
    if(n<=3)
        return a[n];
    for(i=4;i<=n;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    return a[n];
}
int main()
{
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n+1];
        memset(a,0,sizeof(a));
        cout<<f(a,n)<<endl;
    }
    return 0;
}
