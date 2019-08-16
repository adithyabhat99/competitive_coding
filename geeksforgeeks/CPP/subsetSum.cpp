/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints: 

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000

                   
Example:

Input:
2
4
1 5 11 5
3
1 3 5 

Output:

YES
NO
*/
My Solution:Recursive solution
#include <bits/stdc++.h>
using namespace std;
bool isSub(int a[],int n,int sum){
    if(sum==0) return true;
    if(n==0 && sum) return false;
    if(a[n-1]>sum) return isSub(a,n-1,sum);
    return isSub(a,n-1,sum)||isSub(a,n-1,sum-a[n-1]);
}
bool findSub(int a[],int n){
    int s=0;
    for(int i=0;i<n;i++)
    s+=a[i];
    if(s%2) return false;
    return isSub(a,n,s);
}
int main() {
	//code
	int t,n,i,j,sum=0,lsum;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    if(findSub(a,n)) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}

Dynamic Programming Solution:Better solution
using namespace std;
bool findSub(int a[], int n) 
{ 
    int sum = 0; 
    int i, j;
    for (i = 0; i < n; i++) 
      sum += a[i]; 
      
    if (sum%2 != 0)   
       return false; 
    
    bool part[sum/2+1][n+1]; 
    for (i = 0; i <= n; i++) 
      part[0][i] = true; 
    
    for (i = 1; i <= sum/2; i++) 
      part[i][0] = false;      
     for (i = 1; i <= sum/2; i++)   
     { 
       for (j = 1; j <= n; j++)   
       { 
         part[i][j] = part[i][j-1]; 
         if (i >= a[j-1]) 
           part[i][j] = part[i][j] || part[i - a[j-1]][j-1]; 
       }         
     }     
       
     return part[sum/2][n]; 
}      

int main() {
	//code
	int t,n,i,j,sum=0,lsum;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    if(findSub(a,n)) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}