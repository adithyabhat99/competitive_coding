/*
Given a number (greater than 2), print two prime numbers whose sum will be equal to given number, else print -1 if no such number exists.

NOTE: A solution will always exist if the number is even. Read Goldbach’s conjecture.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then print [a, b] only
and not all possible solutions.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.

Output:
Print the two prime numbers in a single line with space in between.

Constraints:
1 ≤ T ≤ 50
2 ≤ N ≤ 1000000

Example:
Input:
2
8
3
Output
3 5
-1
*/

#include <bits/stdc++.h>
using namespace std;
int isPrime(int n){
    int i;
    if(n==2 || n==3)
    return 1;
    if(!(n%2))
    return 0;
    for(i=2;i<n/2;i++)
     if(!(n%i))
     {
         return 0;
     }
     return 1;
}
int main() {
	//code
	int t,n,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    int m=0;
	    vector<int> v;
	    for(i=2;i<=n/2;i++)
	    if(isPrime(i) && isPrime(n-i))
	    v.push_back(i);
	    for(auto x:v){
	    if(x+(n-x)==n){
	    cout<<x<<" "<<n-x<<endl; m=1;
	    break;
	    }
	    }
	    if(!m) cout<<-1<<endl;
	}
	return 0;
}