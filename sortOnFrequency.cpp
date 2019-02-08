/*
Given an array of integers, sort the array according to frequency of elements. For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. 

If frequencies of two elements are same, print them in increasing order.

 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:

Print each sorted array in a seperate line. For each array its numbers should be seperated by space.


Constraints:

1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ A [ i ] ≤ 60 


Example:

Input:

1
5
5 5 4 6 4

Output:

4 4 5 5 6 
*/
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> &p1,pair<int,int> &p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}
void sortf(int a[],int n){
    map<int,int> m;
    int i;
    for(i=0;i<n;i++){
        m[a[i]]++;
    }
    int s=m.size();
    pair<int,int>p[s];
    i=0;
    for(auto x=m.begin();x!=m.end();x++){
        p[i++]=make_pair(x->first,x->second);
    }
    sort(p,p+s,compare);
    for (i = 0; i < s; i++) 
    { 
        int freq = p[i].second; 
        while (freq--) 
            cout << p[i].first << " "; 
    } 
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
	    sortf(a,n);
	    cout<<endl;
	}
	return 0;
}