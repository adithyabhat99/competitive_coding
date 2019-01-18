/*
Generate all prime numbers between two given numbers.

Input:

The first line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing two space separated integers m and n.
Output:

For every test case print all prime numbers p such that m <= p <= n, space separated. Separate the answers for each test case by a new line.

Constraints:
1<=T<=60
1 <= m <= n <= 100000,
n - m <= 100000

Example:

Input:

2

1 10

3 5

Output:

2 3 5 7

3 5
*/

#include<bits/stdc++.h>
using namespace std;
int primeOrnot(int n){
    int i;
    if(n==0 || n==1)
        return 0;
    if(n==2)
        return 1;
    if(!(n%2))
        return 0;
    for(i=2;i<n/2;i++)
        if(!(n%i))
            return 0;
    return 1;
        
}
int main() {
	//code
	int t,n,m,i;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    for(i=m;i<=n;i++)
	    {
	        if(primeOrnot(i))
	        cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}