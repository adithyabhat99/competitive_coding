/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:

The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:

Print number of possible ways to make change for N cents.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 1 ≤ A[i] ≤ 300

Example:

Input:

2
3
1 2 3
4
4
2 5 3 6
10

Output:

4
5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n,t,sum,j,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    cin>>sum;
	    sort(a,a+n);
	    int temp[n][sum+1];
	    for(i=0;i<n;i++) temp[i][0]=1;
	    for(i=0;i<n;i++){
	        for(j=1;j<=sum;j++){
	            if(i==0){
	                if(a[i]>j) temp[i][j]=0;
	                else
	                {
	                    if(j%a[i]==0)
	                    temp[i][j]=1;
	                    else
	                    temp[i][j]=0;
	                }
	            }
	            else if(j<a[i]) temp[i][j]=temp[i-1][j];
	            else temp[i][j]=temp[i-1][j]+temp[i][j-a[i]];
	        }
	    }
	    cout<<temp[n-1][sum]<<endl;
	}
	return 0;
}