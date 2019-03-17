/*
Write a program to find the sum of bit differences in all pairs that can be formed from array elements n. Bit difference of a pair (x, y) is a count of different bits at same positions in binary representations of x and y. For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Input: The first line of input contains an integer T denoting the number of test cases. First line of the test case will contain an array of elements n.
Output: The sum of bit differences of all pairs that can be formed by given array.
Constraints:

1 <=T<= 100

1 <=N<= 10

1 <=a[i]<= 10
Example:

Input:

2
2 
1 2
3 
1 3 5

Output:

4
8

*/

#include <iostream>
using namespace std;
int countBits(int n){
    int c=0;
    while(n){
        n=n&(n-1);
        c++;
    }
    return c;
}
int bitdiff(int a[],int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int x=a[i]^a[j];
            c+=countBits(x);
        }
    }
    return 2*c;
}
int main() {
	//code
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<bitdiff(a,n)<<endl;
	}
	return 0;
}