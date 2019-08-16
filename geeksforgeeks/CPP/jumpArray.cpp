/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
1
11
1 3 5 8 9 2 6 7 6 8 9
Output:
3
*/
#include <iostream>
using namespace std;
int jumps(int a[],int n){
    int maxCurr=0,maxPrev=-1,jump=0,i;
    for(i=0;i<n;i++){
        if(maxCurr>=n-1)
            return jump;
        if(i>maxCurr)
            return -1;
        if(i>maxPrev){
            jump++;
            maxPrev=maxCurr;
        }
        maxCurr=max(maxCurr,i+a[i]);
    }
    return jump;
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
	    cout<<jumps(a,n)<<endl;
	}
	return 0;
}