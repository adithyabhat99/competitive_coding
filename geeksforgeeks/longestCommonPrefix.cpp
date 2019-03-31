/*
Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer N. Next line has space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1 <= T <= 103
1 <= N <= 103
1 <= |S| <= 103

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

Explanation:
Testcase 1: Longest common prefix in all the given string is gee.
*/
#include<bits/stdc++.h>
using namespace std;
string pre(set<string>s){
    
}
int main() {
	//code
	int t,i,j;
	cin>>t;
	while(t--){
	    int n,min=INT_MAX,c=0;
	    cin>>n;
	    string a[n];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i].size()<min)
	        min=a[i].size();
	    }
	    for(i=0;i<min;i++)
	    {
	        for(j=0;j<n;j++)
	        {   
	            if(j<n-1){
                    if(a[j][i]==a[j+1][i])
                    {
                       
                    }
                    else
                    {
                        c=1;
                        break;
                    }
	            }
	        }
	        if(c==1){
	            if(i==0)
	            cout<<-1;
	            for(int k=0;k<i;k++)
	            cout<<a[0][k];
	            break;
	        }
            
            
	    }
        if(i==min && c==0){
                for(int k=0;k<min;k++){
                    cout<<a[0][k];
                    c=1;
                    
                }
        }
	    else if(c==0)
	     cout<<a[0];
	    cout<<endl;
	}
	return 0;
}