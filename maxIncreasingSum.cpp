/*
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10
*/
#include <iostream>
using namespace std;
int maxSum(int a[],int n){
    int msi[n],i,j,m=0;
    for(i=0;i<n;i++)
    msi[i]=a[i];
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
            if(a[i]>a[j] && msi[i]<msi[j]+a[i])
            msi[i]=msi[j]+a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        m=max(msi[i],m);
    }
    return m;
}
int main() {
	//code
	int t,n,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    cout<<maxSum(a,n)<<endl;
	}
	return 0;
}