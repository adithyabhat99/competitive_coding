/*Given two strings, check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input: 
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 1016

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	string a,b;
	int x[256],t,m;
	cin>>t;
	while(t--){
	    cin>>a>>b;
	    m=1;
	    memset(x,0,sizeof(x));
	    int i;
	    if(a.size()!=b.size()){
	    cout<<"NO\n";
	    continue;
	    }
	    for(i=0;i<a.size();i++)
	    x[(int)a[i]]++;
	    for(i=0;i<b.size();i++)
	    x[(int)b[i]]--;
	    for(i=0;i<256;i++)
	    {
	        if(x[i])
	        {
	            cout<<"NO\n";
	            m=0;
	            break;
	        }
	    }
	    if(m)
	    cout<<"YES\n";
	}
	
	return 0;
}
