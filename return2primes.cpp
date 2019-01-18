/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair. 

NOTE: A solution will always exist, read Goldbach’s conjecture.

Also, solve the problem in linear time complexity, i.e., O(n).

 

Input:

The first line contains T, the number of test cases. The following T lines consist of a number each, for which we'll find two prime numbers.

Note: The number would always be an even number.

 
Output:

For every test case print two prime numbers space separated, such that the smaller number appears first. Answer for each test case must be in a new line.
Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 10000


Example:

Input:

5
74
1024
66 
8
9990

Output:

3 71
3 1021
5 61
3 5
17 9973
*/

#include<bits/stdc++.h>
using namespace std;
int primeOrnot(int n){
    int i;
    if(n==0 || n==1)
        return 0;
    if(n==2)
        return 1;
    for(i=2;i<n/2;i++)
    {
        if(!(n%i))
        {
            return 0;
            break;
        }
    }
    return 1;
        
}
int main() {
	//code
	int t,n,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    for(i=3;i<n;i++){
	        if(primeOrnot(i) && primeOrnot(n-i))
	        {
	            cout<<i<<" "<<n-i<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
