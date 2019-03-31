/*
Given a string with repeated characters, task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print 1 if the generated sting doesn't contains any same adjacent characters, else if no such string is possible to be made print 0.
Constraints:
1<=T<=100
1<=length of string<=600
*/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size(),c;
	    int i,j,m=0;
	    for(i=0;i<n;i++){
	        c=0;
	        for(j=i+1;j<n;j++){
	            if(s[i]==s[j]){
	                c++;
	            }
	        }
	        if(c>m)
	        {
	            m=c;
	        }
	    }
        
	    if(m>=s.size()/2)
	cout<<"0\n";
	else cout<<"1\n";
	}
	
	return 0;
}