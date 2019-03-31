/*
Given an input stream of n integers the task is to insert integers to stream and print the kth largest element in the stream at each insertion.

Example:

Input:
stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
k = 3

Output:    {-1,   -1, 10, 11, 20, 40, 50,  50, ...}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Constraints:
1<=T<=100
1<=n,k<=1000
1<=stream[]<=100000

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4 

Output:
-1 -1 -1 1 2 3
3 4 
*/
//Better solution is : https://ide.geeksforgeeks.org/F80qlC0Zhy using heaps
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,k,i;
	cin>>t;
	while(t--){
	    cin>>k>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(i<k-1)
	        cout<<"-1 ";
	        else
	        {
	            if(i==k-1) continue;
	            sort(a,a+i);
	            cout<<a[i-k]<<" ";
	            
	        }
	    }
	    sort(a,a+n);
	    cout<<a[i-k];
	    cout<<endl;
	}
	return 0;
}